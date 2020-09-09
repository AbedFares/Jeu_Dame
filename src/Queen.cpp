#include "Queen.h"


Queen::Queen()
{
	//ctor
}

Queen::~Queen()
{
	//dtor
}

Queen::Queen(int lig, int col, char c):Piece(lig,col,c){

}

void Queen::afficher(){
	if (this->getcouleur()=='b')
	{
		HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,1);
		cout<<"Q";
		SetConsoleTextAttribute(hConsole,7);
	}
	else if (this->getcouleur()=='n')
	{
		HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole,4);
		cout<<"Q";
		SetConsoleTextAttribute(hConsole,7);
	}
}

int Queen::verif_dep(Piece* damier[10][10],int l_dep,int c_dep,int l_dest,int c_dest){
// 0:deplacement illegale // 1:deplacement normal // 2:deplacement avec capture
	if (damier[l_dep][c_dep]->getcouleur()=='n'){
		if (((l_dest==l_dep+1) &&((c_dest==c_dep+1) || (c_dep==c_dest+1) ) && (damier[l_dest][c_dest]->getcouleur()=='v'))||((l_dest==l_dep-1) &&((c_dest==c_dep+1) || (c_dep==c_dest+1) ) && (damier[l_dest][c_dest]->getcouleur()=='v'))){
			return 1;
		}
		if ((l_dest==l_dep+2) &&(c_dest==c_dep+2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep+1][c_dep+1]->getcouleur()=='b')){
				return 2;
			}

        if ((l_dest==l_dep-2) &&(c_dest==c_dep+2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep-1][c_dep+1]->getcouleur()=='b')){
				return 2;
			}
		if ((l_dest==l_dep-2) &&(c_dest==c_dep-2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep-1][c_dep-1]->getcouleur()=='b')){//
				return 2;
			}
					if ((l_dest==l_dep+2) &&(c_dest==c_dep-2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep+1][c_dep-1]->getcouleur()=='b')){
				return 2;
			}
	}else if (damier[l_dep][c_dep]->getcouleur()=='b'){if (((l_dest==l_dep+1) &&((c_dest==c_dep+1) || (c_dep==c_dest+1) ) && (damier[l_dest][c_dest]->getcouleur()=='v'))||((l_dest==l_dep-1) &&((c_dest==c_dep+1) || (c_dep==c_dest+1) ) && (damier[l_dest][c_dest]->getcouleur()=='v'))){
			return 1;
		}
		if ((l_dest==l_dep+2) &&(c_dest==c_dep+2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep+1][c_dep+1]->getcouleur()=='n')){
				return 2;
			}

        if ((l_dest==l_dep-2) &&(c_dest==c_dep+2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep-1][c_dep-1]->getcouleur()=='n')){
				return 2;
			}
		if ((l_dest==l_dep-2) &&(c_dest==c_dep-2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep-1][c_dep-1]->getcouleur()=='n')){//
				return 2;
			}
					if ((l_dest==l_dep+2) &&(c_dest==c_dep-2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep+1][c_dep-1]->getcouleur()=='n')){
				return 2;


	}
}
else return 0;}




bool Queen::verif_capt(Piece* damier[10][10],int lig_dep,int col_dep){
	if (damier[lig_dep][col_dep]->getcouleur()=='n' || damier[lig_dep][col_dep]->getcouleur()=='b'){
		if (lig_dep+2<=9 && lig_dep+2 >=0  && col_dep-2>=0 && col_dep-2<=9 ){
			if (damier[lig_dep][col_dep]->verif_dep(damier,lig_dep,col_dep,lig_dep+2,col_dep-2)==2 ){
				return true;
			}
		}
		if (lig_dep+2<=9 && lig_dep+2 >=0  && col_dep+2<=9 && col_dep+2>=0 ){
			if (damier[lig_dep][col_dep]->verif_dep(damier,lig_dep,col_dep,lig_dep+2,col_dep+2)==2 ){
				return true;
			}
		}
		if (lig_dep-2<=9 && lig_dep-2 >=0 && col_dep-2>=0 && col_dep-2<=9 ){
			if (damier[lig_dep][col_dep]->verif_dep(damier,lig_dep,col_dep,lig_dep-2,col_dep-2)==2 ){
				return true;
			}
		}
		if (lig_dep-2<=9 && lig_dep-2 >=0  && col_dep+2<=9 && col_dep+2>=0 ){
			if (damier[lig_dep][col_dep]->verif_dep(damier,lig_dep,col_dep,lig_dep-2,col_dep+2)==2 ){
				return true;
			}
		}
	}
	return false;
}

void Queen::inter_afficher(char c,sf::RenderWindow* win,int i,int j){
	if (c=='b')

	{sf::Texture QueenBlanc;
	if (QueenBlanc.loadFromFile("Data/dame_rouge_prep.png") == -1)
		return;
	sf::RectangleShape rectQueenBlanc;
	rectQueenBlanc.setSize(sf::Vector2f(40,40));
	rectQueenBlanc.setTexture(&QueenBlanc);
	rectQueenBlanc.setPosition(105+(j*50),105+(i*50));
	win->draw(rectQueenBlanc);}
	if( c=='n'){
        sf::Texture QueenNoir;
	if (QueenNoir.loadFromFile("Data/dame_noir_prep.png") == -1)
		return;
	sf::RectangleShape rectQueenNoir;
	rectQueenNoir.setSize(sf::Vector2f(40,40));
	rectQueenNoir.setTexture(&QueenNoir);
	rectQueenNoir.setPosition(105+(j*50),105+(i*50));
	win->draw(rectQueenNoir);
	}
}
