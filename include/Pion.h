#ifndef PION_H
#define PION_H
#include <iostream>
#include <Piece.h>
#include <windows.h>

using namespace std;
class Pion : public Piece
{
	public:
		Pion();
		Pion(int,int,char);
		virtual ~Pion();
		void afficher();
		int verif_dep(Piece* [10][10],int,int,int,int);
		char getcouleur(){return couleur;};
	protected:

	private:
};

#endif // PION_H
