#include <iostream>
#include "Dame.h"
using namespace std;

int main()
{
    Dame d;
    d.initialiser();
    d.afficher();
	string ch1,ch2;
	int verif=0;
    while ( (d.termine()==0) && !d.nulle() ){
		cin>>ch1>>ch2;
		if (d.test_format(ch1) && d.test_format(ch2)){
			//cout<<d.verif_dep(ch1,ch2)<<endl;
			int check=d.verif_dep(ch1,ch2);
			if ( check!=0 ){
				d.mise_jour(ch1,ch2);
				d.increment();
				d.afficher();
				if (d.verif_capt(ch2) && ( check==2 || check==4 ) ){
					//cout<<"hne"<<endl;
					d.decrement();
					string q=ch2;
					string s=ch1;
					string aux=ch1;
					while (d.verif_capt(q)&& (check==2 || check==4) ){
						//cout<<"ici"<<endl;
						cout<<"choisir une seule case"<<endl;
						cin>>s;
						if (d.test_format(s)){
							check=d.verif_dep(q,s);
							if (check==2 || check==4){
								//cout<<"here"<<endl;
								d.mise_jour(q,s);
								d.afficher();
								q=s;
							}
						}
					}
					d.increment();
				}
			}
		}

    }
    return 0;
}
