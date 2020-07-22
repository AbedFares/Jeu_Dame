#include "Dame.h"

Dame::Dame()
{
	//ctor
}

Dame::~Dame()
{
	//dtor
}
void Dame::initialiser(){
	for (int i=0;i<10;i++)
		for (int j=0;j<10;j++){
			if (i<4 ){
				if (i%2==0){
					if (j%2==1){
						damier[i][j]=new Pion(i,j,'n');
					}else{
						damier[i][j]=new Piece(i,j,'v');
					}
				}else{
					if (j%2==0){
						damier[i][j]=new Pion(i,j,'n');
					}else{
						damier[i][j]=new Piece(i,j,'v');
					}
				}
			}else if (i>5){
				if (i%2==0){
					if (j%2==1){
						damier[i][j]=new Pion(i,j,'b');
					}else{
						damier[i][j]=new Piece(i,j,'v');
					}
				}else{
					if (j%2==0){
						damier[i][j]=new Pion(i,j,'b');
					}else{
						damier[i][j]=new Piece(i,j,'v');
					}
				}
			}
			else{
				damier[i][j]=new Piece(i,j,'v');
			}
		}
}
void Dame::afficher(){
	cout<<"  "<<(char)221<<" a "<<(char)221<<" b "<<(char)221<<" c "<<(char)221<<" d "<<(char)221<<" e "<<(char)221<<" f "<<(char)221<<" g "<<(char)221<<" h "<<(char)221<<" i "<<(char)221<<" j "<<(char)221<<endl;
	cout<<"__________________________________________"<<endl;
	for (int i=0;i<10;i++)
	{
		if (i!=0 ) cout<<10-i<<" "<<(char)221; else cout<<10-i<<(char)221;
		for (int j=0;j<10;j++)
		{
			cout<<" ";
			damier[i][j]->afficher();
			cout<<" "<<(char)221;
		}
		if (i!=0) cout<<" "<<10-i<<" "<<(char)221; else cout<<" "<<10-i<<(char)221;
		cout<<"\n"<<endl;
	}
	cout<<"__________________________________________"<<endl;
	cout<<"  "<<(char)221<<" a "<<(char)221<<" b "<<(char)221<<" c "<<(char)221<<" d "<<(char)221<<" e "<<(char)221<<" f "<<(char)221<<" g "<<(char)221<<" h "<<(char)221<<" i "<<(char)221<<" j "<<(char)221<<endl;
}

int Dame::verif_dep(string depart,string dest){
// 0:deplacement illegale // 1:deplacement normal // 2:deplacement avec capture
	int col_depart=(int) depart[0] - 97;
	int ligne_depart;
	if (depart.length()==3){
		ligne_depart=0;
	}else{
		ligne_depart=58 - (int) depart[1];
	}
	int col_dest=(int) dest[0] - 97;
	int ligne_dest;
	if (dest.length()==3){
		ligne_dest=0;
	}else{
		ligne_dest=58 - (int) dest[1];
	}
	if (damier[ligne_depart][col_depart]->getcouleur()=='v'){
		cout<<"La case de depart est vide!"<<endl;
		return 0;
	}else
		return damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest);
	return 0;
}
bool Dame::test_format ( string ch)
{
    if (ch.length()==2)
         {if (ch[0]>='a' && ch[0]<='j'&& ch[1]>='1'&& ch[1]<='9')
             return true ;else return false;}

    else if (ch.length()==3)
            {if (ch[0]>='a' && ch[0]<='j'&& ch[1]=='1'&& ch[2]=='0')
             return true ;
             else return false;}

    else return false;
}
bool Dame::verif_capt(string s){
	return false;
}
void Dame::mise_jour(string depart,string dest){
	int col_depart=(int) depart[0] - 97;
	int ligne_depart;
	if (depart.length()==3){
		ligne_depart=0;
	}else{
		ligne_depart=58 - (int) depart[1];
	}
	int col_dest=(int) dest[0] - 97;
	int ligne_dest;
	if (dest.length()==3){
		ligne_dest=0;
	}else{
		ligne_dest=58 - (int) dest[1];
	}
	if (damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)==1){
			sans_capt++;
		damier[ligne_dest][col_dest]=damier[ligne_depart][col_depart];
		damier[ligne_depart][col_depart]=new Piece(ligne_depart,col_depart,'v');
	}else if (damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)==2){
		sans_capt=0;
		damier[ligne_dest][col_dest]=damier[ligne_depart][col_depart];
		damier[(ligne_depart+ligne_dest)/2][(col_depart+col_dest)/2]=new Piece((ligne_depart+ligne_dest)/2,(col_depart+col_dest)/2,'v');
		damier[ligne_depart][col_depart]=new Piece(ligne_depart,col_depart,'v');
	}
}
bool Dame::nulle(){
	return (sans_capt==10);
}
int Dame::termine(){
//0:partie non encore termine//1: blanc gagne //2:noir gagne
return 0;
}
