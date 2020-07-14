#ifndef PION_H
#define PION_H
#include <iostream>
#include <Piece.h>

using namespace std;
class Pion : public Piece
{
	public:
		Pion();
		Pion(int,int,char);
		virtual ~Pion();
		void afficher(){cout<<"P";}

	protected:

	private:
};

#endif // PION_H
