#ifndef QUEEN_H
#define QUEEN_H

#include <Piece.h>


class Queen : public Piece
{
	public:
		Queen();
		virtual ~Queen();
		char getcouleur(){return couleur;};

	protected:

	private:
};

#endif // QUEEN_H
