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
	for (int i=0;i<10;i+=2){
		for (int j=0;j<10;j++){
			if (j!=4 && j!=5){
				if (j<=3){
					damier[i][j]=new Piece(i,j,'n');
				}
				else{
					damier[i][j]=new Piece(i,j,'b');
				}
			}
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
