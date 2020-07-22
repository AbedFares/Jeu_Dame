#include <iostream>
#include "Dame.h"
using namespace std;

int main()
{
    Dame d;
    d.initialiser();
    d.afficher();
	string ch1,ch2;
    while ((d.termine()==0) && !d.nulle()){
		cin>>ch1>>ch2;
		if (d.test_format(ch1) && d.test_format(ch2)){
			if (d.verif_dep(ch1,ch2)!=0){
				d.mise_jour(ch1,ch2);
				if (d.verif_capt(ch2)){
					string q=ch2;
					string s;
					while (d.verif_capt(q)){
						cin>>s;
						d.mise_jour(q,s);
						q=s;
					}
				}
			}
		}
		d.afficher();
    }
    return 0;
}
