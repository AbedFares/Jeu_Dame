#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
class Piece
{
	public:
		Piece();
		Piece(int,int,char);
		virtual ~Piece();
		virtual void afficher();
		virtual char getcouleur(){return couleur;};
		virtual int verif_dep(Piece* damier[10][10],int a,int b,int c,int d){return 0;};
        virtual bool verif_capt(Piece* [10][10],int,int){return false;};
        virtual void inter_afficher(sf::RenderWindow*,int,int){};

	protected:
		int rangee;
		int colonne;
		char couleur;
	private:
};

#endif // PIECE_H
