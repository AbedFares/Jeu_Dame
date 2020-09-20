#ifndef DAME_H
#define DAME_H
#include "Queen.h"
#include "Piece.h"
#include "Pion.h"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
class Dame
{
	public:
		Dame();
		virtual ~Dame();
		void initialiser();
		void afficher();
		int verif_dep(string ,string ); // verifier si le deplacement est legeal
        bool test_format(string); // test le format de la chaine input
        bool verif_capt(string ); // verifier s'il s'agit d'une capture d'une position donne
        //bool verif_capt(int,int ); // verifier s'il s'agit d'une capture d'une position donne
        void mise_jour(string,string); // fait le deplacement des pieces
        bool nulle(); // true : si partie est nulle // false : sinon
        int termine(); // retourner 0 si termine // 1: si blanc gagne // 2: si noir gagne
        bool forced(); // retourner true si il y a une capture
		static int get_nbcoup(){ return nbre_coup;};
		static int get_sanscapt(){ return sans_capt;};
		void increment(){ nbre_coup++;}; // augmente le nbre de coup par 1 chaque tour
		void decrement(){ nbre_coup--;};
		void interface_afficher(sf::RenderWindow*);
		string mouseclick(int,int);
		void endscreen(sf::RenderWindow*);
    protected:

	private:
		Piece* damier[10][10];
		static int nbre_coup;
		static int sans_capt;
};

#endif // DAME_H
