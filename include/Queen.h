#ifndef QUEEN_H
#define QUEEN_H
#include <windows.h>

#include <Piece.h>


class Queen : public Piece
{
	public:
		Queen();
		Queen(int,int,char);
		virtual ~Queen();
		char getcouleur(){return couleur;};
        int verif_dep(Piece* [10][10],int,int,int,int);
        bool verif_capt(Piece* [10][10],int,int);
        void afficher();
        void inter_afficher(sf::RenderWindow*,int,int);
	protected:

	private:
};

#endif // QUEEN_H
