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
		int verif_dep(Piece* [10][10],int,int,int,int);// 0:deplacement illegale // 1:deplacement normal // 2:deplacement avec capture //3:promotion sans capture // 4:promotion AVEC capture
        bool verif_capt(Piece* [10][10],int,int);
		char getcouleur(){return couleur;};
		void inter_afficher(char,sf::RenderWindow*,int,int);
	protected:

	private:
};

#endif // PION_H
