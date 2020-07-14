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
		void afficher();

	protected:
		int rangee;
		int colonne;
		char couleur;
	private:
};

#endif // PIECE_H
