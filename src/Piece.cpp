#include "Piece.h"

Piece::Piece()
{
}

Piece::Piece(int a,int b,char c){
	rangee=a;
	colonne=b;
	couleur=c;
}
Piece::~Piece()
{
}
void Piece::afficher(){
	cout<<".";
}
