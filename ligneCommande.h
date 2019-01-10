#ifndef SOME_HEADER_GUARD_WITHh_UNIQUE_NAMEO
#define SOME_HEADER_GUARD_WITHh_UNIQUE_NAMEO
#include"struct.h"
#include"article.h"
#include"client.h"


/*-------------------------------------------- Structure -------------------------------------------------------*/


Ensemble ensembleVide (void);
Ensemble insererEnTete (Ensemble e, LigneCommande commande);
Ensemble ajouterCommande(Ensemble e ,LigneCommande commande);
Booleen commandeEstVide(Ensemble e);
void afficherCommande (Ensemble e);
Ensemble supprimerEnTete (Ensemble e);
Ensemble supprimerCommande(Ensemble e, Article *x);
int longueur (Ensemble e);

LigneCommande lireLigneCommande(FILE*flot,Article *tabArt[], int nbArt);

#endif /* EXAMPLE_H */
/* Fonctionnalite à rajouter :


Fonctionnalite à modifier :

*/ 
