#ifndef PIECE_H
#define PIECE_H
#include <iostream>

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

	protected:
		int rangee;
		int colonne;
		char couleur;
	private:
};

#endif // PIECE_H
