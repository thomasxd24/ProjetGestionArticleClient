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
Ensemble ensembleVide (void);
Ensemble insererEnTete (Ensemble e, LigneCommande commande);
Ensemble ajouterCommande(Ensemble e ,LigneCommande commande);
Booleen commandeEstVide(Ensemble e);
void afficherCommande (Ensemble e);
Ensemble supprimerEnTete (Ensemble e);
Ensemble supprimerCommande(Ensemble e, Article *x);
int longueur (Ensemble e);

#endif /* EXAMPLE_H */

int remplirTabLigneCommande(LigneCommande *tab[], int tmax, FILE*flot);
LigneCommande lireLigneCommande(LigneCommande * flot);

/* Fonctionnalite à rajouter :


Fonctionnalite à modifier :

*/ 
