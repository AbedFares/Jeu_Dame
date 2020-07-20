#ifndef QUEEN_H
#define QUEEN_H

#include <Piece.h>


class Queen : public Piece
{
	public:
		Queen();
		virtual ~Queen();
		char getcouleur(){return couleur;};
        int verif_dep(Piece* [10][10],int,int,int,int);
	protected:

	private:
};

#endif // QUEEN_H
