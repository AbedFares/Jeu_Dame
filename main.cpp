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
    while ((d.termine()==0) && !d.nulle()){
		cin>>ch1>>ch2;
		if (d.test_format(ch1) && d.test_format(ch2)){
			cout<<d.verif_dep(ch1,ch2)<<endl;
			if (d.verif_dep(ch1,ch2)!=0){
				d.mise_jour(ch1,ch2);
				d.increment();
				d.afficher();
				/*if (d.verif_capt(ch2) ){
					string q=ch2;
					string s;
					while (d.verif_capt(q)){
						cin>>s;
						if (d.verif_dep(q,s)==2){
							d.mise_jour(q,s);
							q=s;
						}
					}
				}*/
			}
		}

    }
    return 0;
}
