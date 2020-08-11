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
// 0:deplacement illegale // 1:deplacement normal // 2:deplacement avec capture //3:promotion sans capture // 4:promotion AVEC capture
	if (damier[l_dep][c_dep]->getcouleur()=='n'){
		if ((l_dest==l_dep+1) &&((c_dest==c_dep+1) || (c_dep==c_dest+1) ) && (damier[l_dest][c_dest]->getcouleur()=='v')){
			if (l_dest==9){
				return 3;
			}
			else{
				return 1;
			}
		}
		if ((l_dest==l_dep+2) &&(c_dest==c_dep+2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dest-1][c_dest-1]->getcouleur()=='b')){
			if (l_dest==9)
				return 4;
			else{
				//cout<<"here"<<endl;
				return 2;
			}
			}
		if ((l_dest==l_dep+2) &&(c_dest==c_dep-2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dep+1][c_dep-1]->getcouleur()=='b')){
			if (l_dest==9)
				return 4;
			else{
				//cout<<"ici"<<endl;
				return 2;
			}
			}
	}else if (damier[l_dep][c_dep]->getcouleur()=='b'){
		if ((l_dest==l_dep-1) &&((c_dest==c_dep+1) || (c_dep==c_dest+1) ) && (damier[l_dest][c_dest]->getcouleur()=='v')){
			if (l_dest==0){
				//cout<<"promotion sans capture"<<endl;
				return 3;
			}
			else{
				//cout<<"deplacement normal"<<endl;
				return 1;
			}
		}
		if ((l_dest==l_dep-2) &&(c_dest==c_dep+2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dest+1][c_dest-1]->getcouleur()=='n')){
				if (l_dest==0){
				//cout<<"promotion avec capture"<<endl;
					return 4;
				}
				else{
				//cout<<"deplacement avec capture"<<endl;
					return 2;
				}
			}
		if ((l_dest==l_dep-2) &&(c_dest==c_dep-2 ) && (damier[l_dest][c_dest]->getcouleur()=='v')
			&& (damier[l_dest+1][c_dest+1]->getcouleur()=='n')){
				if (l_dest==0){
				//cout<<"promotion avec capture"<<endl;
					return 4;
				}
				else{
				//cout<<"deplacement avec capture"<<endl;
					return 2;
				}
		} else {//cout<<"??????????  "<<damier[l_dest-1][c_dest-1]->getcouleur()<<endl;
		 return 0;}
	}
}
bool Pion::verif_capt(Piece* damier[10][10],int lig_dep,int col_dep){
	if (damier[lig_dep][col_dep]->getcouleur()=='n'){
		if (lig_dep+2<=9 && col_dep-2>=0 && col_dep-2<=9 ){
			if (damier[lig_dep][col_dep]->verif_dep(damier,lig_dep,col_dep,lig_dep+2,col_dep-2)==2 ){
				//cout<<"bla bla"<<endl;
				return true;
			}
		}
		if (lig_dep+2<=9 && col_dep+2<=9 && col_dep+2>=0 ){
			if (damier[lig_dep][col_dep]->verif_dep(damier,lig_dep,col_dep,lig_dep+2,col_dep+2)==2 ){
				//	cout<<"hala hala"<<endl;
				return true;
			}
		}
	}
	if (damier[lig_dep][col_dep]->getcouleur()=='b'){
		if (lig_dep-2>=0 && col_dep-2>=0 && col_dep-2<=9 ){
			if (damier[lig_dep][col_dep]->verif_dep(damier,lig_dep,col_dep,lig_dep-2,col_dep-2)==2 ){
				return true;
			}
		}
		if (lig_dep+2<=9 && col_dep+2<=9 && col_dep+2>=0 ){
			if (damier[lig_dep][col_dep]->verif_dep(damier,lig_dep,col_dep,lig_dep-2,col_dep+2)==2 ){
				return true;
			}
		}
	}
	return false;
}
