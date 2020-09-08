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
		string ch1,ch2;

    while (window.isOpen())
    {
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
		//d.afficher();
		int verif=0;
		if ( (d.termine()==0) && !d.nulle() ){
			if (var2){
				if (var){
					ch1=d.mouseclick(xPressed,yPressed);var2=false;
				}
				else{
					ch2=d.mouseclick(xPressed,yPressed);var2=false;
				}
			}
			cout<<ch1<<" "<<ch2<<endl;
			//cin>>ch1>>ch2;
			if (d.test_format(ch1) && d.test_format(ch2)){
				//cout<<d.verif_dep(ch1,ch2)<<endl;
				int check=d.verif_dep(ch1,ch2);
				if ( check!=0 ){
					d.mise_jour(ch1,ch2);
					d.increment();
					d.afficher();
					window.clear();
					d.interface_afficher(&window);
					window.display();
					if (d.verif_capt(ch2) && ( check==2 || check==4 ) ){
						//cout<<"hne"<<endl;
						d.decrement();
						string q=ch2;
						string s=ch1;
						string aux=ch1;
						while (d.verif_capt(q)&& (check==2 || check==4) ){
							//cout<<"ici"<<endl;
							cout<<"choisir une seule case"<<endl;
							s=d.mouseclick(xPressed,yPressed);
							cout<<"s="<<s<<endl;
							if (d.test_format(s)){
								check=d.verif_dep(q,s);
								if (check==2 || check==4){
									//cout<<"here"<<endl;
									d.mise_jour(q,s);
									d.afficher();
									q=s;
								}
							}
						}
						d.increment();
					}
				}
			}
			/*window.clear();
			d.interface_afficher(&window);
			window.display();*/
		}
	}
	return 0;
}
