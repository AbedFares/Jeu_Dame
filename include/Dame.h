#ifndef DAME_H
#define DAME_H
#include "Piece.h"
#include "Pion.h"
#include <iostream>
#include <string>
using namespace std;
class Dame
{
	public:
		Dame();
		virtual ~Dame();
		void initialiser();
		void afficher();
		int verif_dep(string ,string );
        bool test_format(string);
        bool verif_capt(string );
        void mise_jour(string,string);
        bool nulle();
        int termine();
    protected:

	private:
		Piece* damier[10][10];
		static int nbre_coup;
		static int sans_capt;
};

#endif // DAME_H
