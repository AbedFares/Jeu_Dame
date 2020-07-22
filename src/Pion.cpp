#include "Pion.h"

Pion::Pion()
{
	//ctor
}
Pion::Pion(int a,int b,char c) : Piece(a,b,c){

}
Pion::~Pion()
{
	//dtor
}

void Pion::afficher(){
	if (this->getcouleur()=='b')
	{
		HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,1);
		cout<<"P";
		SetConsoleTextAttribute(hConsole,7);
	}
	else if (this->getcouleur()=='n')
	{
		HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,4);
		cout<<"P";
		SetConsoleTextAttribute(hConsole,7);
	}
}

int Pion::verif_dep(Piece* damier[10][10],int l_dep,int c_dep,int l_dest,int c_dest){
// 0:deplacement illegale // 1:deplacement normal // 2:deplacement avec capture
	if (damier[l_dep][c_dep]->getcouleur()=='n'){
		if ((l_dest==l_dep+1) &&((c_dest==c_dep+1) || (c_dep==c_dest+1) ) && (damier[l_dest][c_dest]->getcouleur()=='v')){
			return 1;
		}
		if ((l_dest==l_dep+2) &&(c_dest==c_dep+2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dest-1][c_dest-1]->getcouleur()=='b')){
				return 2;
			}
		if ((l_dest==l_dep+2) &&(c_dest==c_dep-2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dest+1][c_dest+1]->getcouleur()=='b')){
				return 2;
			}
	}else if (damier[l_dep][c_dep]->getcouleur()=='b'){
		if ((l_dest==l_dep-1) &&((c_dest==c_dep+1) || (c_dep==c_dest+1) ) && (damier[l_dest][c_dest]->getcouleur()=='v')){
			return 1;
		}
		if ((l_dest==l_dep-2) &&(c_dest==c_dep+2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dest-1][c_dest+1]->getcouleur()=='b')){
				return 2;
			}
		if ((l_dest==l_dep-2) &&(c_dest==c_dep-2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dest-1][c_dest-1]->getcouleur()=='b')){
				return 2;
			}
	}
}
