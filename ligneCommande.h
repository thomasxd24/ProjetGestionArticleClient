#ifndef SOME_HEADER_GUARD_WITHh_UNIQUE_NAME
#define SOME_HEADER_GUARD_WITHh_UNIQUE_NAME
#include"article.h"


/*-------------------------------------------- Structure -------------------------------------------------------*/

typedef struct 
{
    int idCommande;
    Article* artCommande;
    int quantite;
} LigneCommande;

typedef struct Maillon{
	LigneCommande v;
	struct Maillon * suiv;
}Maillon;

typedef Maillon *Ensemble;

typedef enum {faux,vrai}Booleen;

/*-------------------------------------------- Chargement TAB ---------------------------------------------------*/

/*-------------------------------------------- Afficher TAB------------------------------------------------------*/

/*-------------------------------------------- Sauvegarder TAB --------------------------------------------------*/

/*-------------------------------------------- Trie Dico Article ------------------------------------------------*/

/*-------------------------------------------- Recherche Article Designation ------------------------------------*/

/*-------------------------------------------- Supprimer Article ------------------------------------------------*/

/*-------------------------------------------- Ajouter Article --------------------------------------------------*/


#endif /* EXAMPLE_H */

/* Fonctionnalite à rajouter :


Fonctionnalite à modifier :

*/ 