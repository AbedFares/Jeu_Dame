#ifndef DAME_H
#define DAME_H
#include "Piece.h"
#include "Pion.h"
#include <iostream>
using namespace std;
class Dame
{
	public:
		Dame();
		virtual ~Dame();
		void initialiser();
		void afficher();

	protected:

	private:
		Piece* damier[10][10];
};

#endif // DAME_H
