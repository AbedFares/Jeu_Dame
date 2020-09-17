#include <iostream>
#include "Dame.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

int main()
{
	Dame d;
    d.initialiser();
	sf::RenderWindow window(sf::VideoMode(700, 700), "Jeu de Dames");
	//Images
		bool var=false;
		bool var2=false;
		bool var3=true;
		string ch1,ch2;
		string initial;
		int check;
    while (window.isOpen())
    {
    	//		cout<<"hne"<<endl;
		sf::Event event;
		int xPressed=0;int yPressed=0;
		int xReleased=0;int yReleased=0;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed){
				if (event.mouseButton.button == sf::Mouse::Left){
					xPressed=event.mouseButton.x;
					yPressed=event.mouseButton.y;
					var=!var;
					var2=true;
				}
			}
		}
		window.clear();
		d.interface_afficher(&window);
		window.display();
		if ( (d.termine()==0) && !d.nulle() ){
			if (var3){
				if (var2){
					if (var){
						ch1=d.mouseclick(xPressed,yPressed);var2=false;
						cout<<ch1<<" ";
					}
					else{
						ch2=d.mouseclick(xPressed,yPressed);var2=false;
						cout<<ch2<<endl;
					}
				}
				if (d.test_format(ch1) && d.test_format(ch2)){
					check=d.verif_dep(ch1,ch2);
					if ( check!=0 ){
						d.mise_jour(ch1,ch2);
						d.increment();
						d.afficher();
						window.clear();
						d.interface_afficher(&window);
						window.display();
						initial=ch2;
						if (d.verif_capt(ch2) && ( check==2 || check==4 ) ){
							cout<<"var3"<<var3<<endl;
							d.decrement();
							var3=false;
						}
					}
				}
			} else{
				if (var2){
					if (var){
						ch1=d.mouseclick(xPressed,yPressed);var2=false;
						cout<<"var3var"<<var3<<endl;
						cout<<ch1<<" ";
					}
					else{
						ch2=d.mouseclick(xPressed,yPressed);var2=false;
						cout<<ch2<<endl;
					}
				}
				if (d.test_format(ch1) && d.test_format(ch2) && (ch1==initial)){
					check=d.verif_dep(ch1,ch2);
					cout<<d.get_nbcoup()<<endl;
					if (check==2 || check==4){
						//cout<<"here"<<endl;
						d.mise_jour(ch1,ch2);
						window.clear();
						d.interface_afficher(&window);
						window.display();
						d.afficher();
						cout<<ch2<<d.verif_capt(ch2)<<endl;
						if (d.verif_capt(ch2) ){initial=ch2;} else {var3=true;d.increment();}
					}
				}
			}
		}
	}
	return 0;
}
