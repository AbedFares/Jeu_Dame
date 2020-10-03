#include "Dame.h"
int Dame::nbre_coup=0;
int Dame::sans_capt=0;
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

void Dame::interface_afficher(sf::RenderWindow* win){
	//Background
	sf::Texture Background;
	if (Background.loadFromFile("Data/Checkers_background.jpg") == -1)
		return ;
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(700,700));
	rect.setPosition(0,0);
	rect.setTexture(&Background);
	//Board
    sf::Texture board;
    board.loadFromFile("Data/checkers_board.jpg");
    if (board.loadFromFile("Data/checkers_board.jpg") == -1)
		return ;
	sf::RectangleShape rect_board;
	rect_board.setSize(sf::Vector2f(500,500));
	rect_board.setPosition(100,100);
	rect_board.setTexture(&board);
	////Drawing
	win->draw(rect);
	win->draw(rect_board);
	for (int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			damier[i][j]->inter_afficher(damier[i][j]->getcouleur(),win,i,j);
		}
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
	char c=damier[ligne_depart][col_depart]->getcouleur();
	if (Dame::nbre_coup % 2==0 && c=='n'){
			cout<<"c'est le tour du blanc"<<endl;
		return 0;
	}
	if (Dame::nbre_coup % 2==1 && c=='b'){
		cout<<"c'est le tour du noir"<<endl;
		return 0;
	}
	int col_dest=(int) dest[0] - 97;
	int ligne_dest;
	if (dest.length()==3){
		ligne_dest=0;
	}else{
		ligne_dest=58 - (int) dest[1];
	}
	if (damier[ligne_depart][col_depart]->getcouleur()=='v'){
		//cout<<"La case de depart est vide!"<<endl;
		return 0;
	}else {
		//cout<<this->forced()<<endl;
		if (this->forced() ){
			if ( damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)!=2 &&
			damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)!=4){
				cout<<"il s'agit d'une capture !"<<endl;
				return 0;
			}else{
				return damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest);
			}
		}
		return damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest);
	}
	return 0;
}
int Dame::verif_dep(string depart,int ligne_dest,int col_dest){
// 0:deplacement illegale // 1:deplacement normal // 2:deplacement avec capture
	int col_depart=(int) depart[0] - 97;
	int ligne_depart;
	if (depart.length()==3){
		ligne_depart=0;
	}else{
		ligne_depart=58 - (int) depart[1];
	}
	char c=damier[ligne_depart][col_depart]->getcouleur();
	if (Dame::nbre_coup % 2==0 && c=='n'){
			cout<<"c'est le tour du blanc"<<endl;
		return 0;
	}
	if (Dame::nbre_coup % 2==1 && c=='b'){
		cout<<"c'est le tour du noir"<<endl;
		return 0;
	}
	if (damier[ligne_depart][col_depart]->getcouleur()=='v'){
		//cout<<"La case de depart est vide!"<<endl;
		return 0;
	}else {
		//cout<<this->forced()<<endl;
		if (this->forced() ){
			if ( damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)!=2 &&
			damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)!=4){
				cout<<"il s'agit d'une capture !"<<endl;
				return 0;
			}else{
				return damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest);
			}
		}
		return damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest);
	}
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

    else {return false;cout<<"format donne est invalide"<<endl;}
}
bool Dame::verif_capt(string p){
	int col_depart=(int) p[0] - 97;
	int ligne_depart;
	if (p.length()==3){
		ligne_depart=0;
	}else{
		ligne_depart=58 - (int) p[1];
	}
	/*if ( damier[ligne_depart][col_depart]->verif_capt(damier,ligne_depart,col_depart) )
		cout<<"verif_cap works"<<endl;*/
	return damier[ligne_depart][col_depart]->verif_capt(damier,ligne_depart,col_depart);
}
/*bool Dame::verif_capt(int ligne,int colonne){
	//if ( damier[ligne][colonne]->verif_capt(damier,ligne,colonne) )
		//cout<<"verif_cap works"<<endl;
	return damier[ligne][colonne]->verif_capt(damier,ligne,colonne);
}*/
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
		//cout<<"dep norm du :"<<damier[ligne_depart][col_depart]->getcouleur()<<endl;
		Dame::sans_capt++;
		damier[ligne_dest][col_dest]=damier[ligne_depart][col_depart];
		damier[ligne_depart][col_depart]=new Piece(ligne_depart,col_depart,'v');
	}else if (damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)==2){
		//cout<<"capture du :"<<damier[ligne_depart][col_depart]->getcouleur()<<endl;
		Dame::sans_capt=0;
		damier[ligne_dest][col_dest]=damier[ligne_depart][col_depart];
		damier[(ligne_depart+ligne_dest)/2][(col_depart+col_dest)/2]=new Piece((ligne_depart+ligne_dest)/2,(col_depart+col_dest)/2,'v');
		damier[ligne_depart][col_depart]=new Piece(ligne_depart,col_depart,'v');
		//return 2;
	} else if (damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)==3){
		//cout<<"promo norm du :"<<damier[ligne_depart][col_depart]->getcouleur()<<endl;
		Dame::sans_capt++;
		damier[ligne_dest][col_dest]=new Queen(ligne_depart,col_depart,damier[ligne_depart][col_depart]->getcouleur());
		damier[ligne_depart][col_depart]=new Piece(ligne_depart,col_depart,'v');
	} else if (damier[ligne_depart][col_depart]->verif_dep(damier,ligne_depart,col_depart,ligne_dest,col_dest)==4){
		//cout<<"promo avec capt du :"<<damier[ligne_depart][col_depart]->getcouleur()<<endl;
		Dame::sans_capt=0;
		damier[ligne_dest][col_dest]=new Queen(ligne_depart,col_depart,damier[ligne_depart][col_depart]->getcouleur());
		damier[(ligne_depart+ligne_dest)/2][(col_depart+col_dest)/2]=new Piece((ligne_depart+ligne_dest)/2,(col_depart+col_dest)/2,'v');
		damier[ligne_depart][col_depart]=new Piece(ligne_depart,col_depart,'v');
	}
	//return 0;
}
bool Dame::nulle(){
	return (Dame::sans_capt==10);
}
int Dame::termine(){
//0:partie non encore termine//1: blanc gagne //2:noir gagne
bool noir=false;bool blanc=false;
for (int i=0;i<10;i++)
{ for (int j=0;j<10;j++)
{
    if (damier[i][j]->getcouleur()=='b')
        blanc=true;
    if (damier[i][j]->getcouleur() =='n')
        noir=true;

}

}
if (noir == false && blanc ==true)
    return 1;
if(noir == true && blanc == false)
    return 2;
if (noir==true && blanc==true)
    return 0;
}

bool Dame::forced(){
	char tour;
	if (Dame::nbre_coup % 2 == 0){
		tour ='b';
	}else{
		tour='n';
	}
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			if (damier[i][j]->getcouleur()==tour){
				if (damier[i][j]->verif_capt(damier,i,j)){
					//	cout<<i<<" "<<j<<endl;
					return true;
				}
			}
		}
	}
	return false;
}

string Dame::mouseclick(int x,int y){
	string s;
	if (x>=100 && x<=600){
		if (x>=105 && x<=145){
			s="a";
		}
		if (x>=155 && x<=195){
			s="b";
		}
		if (x>=205 && x<=245){
			s="c";
		}
		if (x>=255 && x<=295){
			s="d";
		}
		if (x>=305 && x<=345){
			s="e";
		}
		if (x>=355 && x<=395){
			s="f";
		}
		if (x>=405 && x<=445){
			s="g";
		}
		if (x>=455 && x<=495){
			s="h";
		}
		if (x>=505 && x<=545){
			s="i";
		}
		if (x>=555 && x<=595){
			s="j";
		}
	}
	else
	{
		s="invalid";
		return s;
	}
	if (y>=100 && y<=600){
		if (y>=105 && y<=145){
			s+="10";
		}
		if (y>=155 && y<=195){
			s+="9";
		}
		if (y>=205 && y<=245){
			s+="8";
		}
		if (y>=255 && y<=295){
			s+="7";
		}
		if (y>=305 && y<=345){
			s+="6";
		}
		if (y>=355 && y<=395){
			s+="5";
		}
		if (y>=405 && y<=445){
			s+="4";
		}
		if (y>=455 && y<=495){
			s+="3";
		}
		if (y>=505 && y<=545){
			s+="2";
		}
		if (y>=555 && y<=595){
			s+="1";
		}
	}else{
		s="invalid";
		return s;
	}
	cout<<s<<endl;
	return s;
}
void Dame::endscreen(sf::RenderWindow* win){
	win->clear();
	sf::Font arial;
	if (!arial.loadFromFile("Data/Arial.ttf") )
		return;
	sf::Text text;
	text.setFont(arial);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	this->interface_afficher(win);
	sf::Texture opac;
	if (opac.loadFromFile("Data/opac.png") == -1)
		return;
		sf::RectangleShape rect_opac;
	rect_opac.setSize(sf::Vector2f(700,700));
	rect_opac.setTexture(&opac);
	win->draw(rect_opac);
	if (this->termine()==1){
		text.setString("Blanc a gagne!!");
	} else if (this->termine()==2){
		text.setString("Noir a gagne");
	}else if (this->nulle()){
		text.setString("Partie Nulle");
	}
	text.setPosition(sf::Vector2f(300,350));
	win->draw(text);
	win->display();
}
void Dame::affichepossible(sf::RenderWindow* win,string ch1){
	if (!this->test_format(ch1)){
		return;
	}
	int col_depart=(int) ch1[0] - 97;
	int ligne_depart;
	if (ch1.length()==3){
		ligne_depart=0;
	}else{
		ligne_depart=58 - (int) ch1[1];
	}
	if (damier[ligne_depart][col_depart]->getcouleur()=='v'){
		return;
	}
	sf::Texture place_possible;
	if (place_possible.loadFromFile("Data/place_possible.png")==-1){
		return;
	}
	//win->clear();
	this->interface_afficher(win);
	sf::RectangleShape rect_poss;
	rect_poss.setSize(sf::Vector2f(40,40));
	rect_poss.setTexture(&place_possible);
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			if (this->verif_dep(ch1,i,j)!=0){
				rect_poss.setPosition(105+(j*50),105+(i*50));
				win->draw(rect_poss);
			}
		}
	}
	win->display();
	return;
}
