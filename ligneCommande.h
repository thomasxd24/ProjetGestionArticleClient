#ifndef LIGNECOMMANDEDEF
#define LIGNECOMMANDEDEF
#include"struct.h"
#include"article.h"
#include"client.h"

/*-------------------------------------------- Fonctions liste --------------------------------------------------------*/

Ensemble ensembleVide (void);
Ensemble insererEnTete (Ensemble e, LigneCommande commande);
Ensemble ajouterCommande(Ensemble e ,LigneCommande commande);
Booleen commandeEstVide(Ensemble e);
void afficherCommande (Ensemble e);
Ensemble supprimerEnTete (Ensemble e);
Ensemble supprimerCommande(Ensemble e, Article *x);
int longueur (Ensemble e);

/*-------------------------------------------- Chargement tableau--------------------------------------------------------*/
void remplirTabLigneCommande(Client tabClient[],int nbClient, Article *tabArt[], int nbArt);

/*-------------------------------------------- Supprimer ligne vide --------------------------------------------------------*/


/*-------------------------------------------- Tri echange --------------------------------------------------------*/

void sauvegardeListeCommandes(Client tabClient[],int nbClient);
/* ----------------------------------------Sauvegarder----------------------------------*/


#endif /* EXAMPLE_H */

