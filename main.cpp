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
	sf::Texture Background;
	if (Background.loadFromFile("Data/Checkers_background.jpg") == -1)
		return 1;
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(700,700));
	rect.setPosition(0,0);
	rect.setTexture(&Background);

    Texture board;
    board.loadFromFile("Data/checkers_board.jpg");
    if (board.loadFromFile("Data/checkers_board.jpg") == -1)
		return 1;
	RectangleShape rect_board;
	rect_board.setSize(Vector2f(500,500));
	rect_board.setPosition(100,100);
	rect_board.setTexture(&board);
    while (window.isOpen())
    {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.draw(rect);
		window.draw(rect_board);
		d.interface_afficher(&window);
		window.display();
		d.afficher();
		string ch1,ch2;
		int verif=0;
		while ( (d.termine()==0) && !d.nulle() ){
			cin>>ch1>>ch2;
			if (d.test_format(ch1) && d.test_format(ch2)){
				//cout<<d.verif_dep(ch1,ch2)<<endl;
				int check=d.verif_dep(ch1,ch2);
				if ( check!=0 ){
					d.mise_jour(ch1,ch2);
					d.increment();
					d.afficher();
					if (d.verif_capt(ch2) && ( check==2 || check==4 ) ){
						//cout<<"hne"<<endl;
						d.decrement();
						string q=ch2;
						string s=ch1;
						string aux=ch1;
						while (d.verif_capt(q)&& (check==2 || check==4) ){
							//cout<<"ici"<<endl;
							cout<<"choisir une seule case"<<endl;
							cin>>s;
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
		}
		window.clear();
		window.display();
	}
	return 0;
}
