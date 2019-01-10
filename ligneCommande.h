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


/* ----------------------------------------Sauvegarder----------------------------------*/

void sauvegarder (Article *tabArt[], int nbArt, FILE*flot);


#endif /* EXAMPLE_H */

/* fonction à rajouter:
    - modidierLigneCommande
    - RechercherLigneCommande

+++++++++++Rajouter tous dans le menu+++++++

/* Fonctionnalite à modifier :
    - supprimerLigneCommandeVide(Article *tabArt[], int nbArt);
    - triEchange(Article *tabArt[], int nbArt);
    - echanger(Article *tabArt[], int i, int j);
    - plusGrand(Article *tabArt[], int nbArt);
    - sauvegarder (Article *tabArt[], int nbArt, FILE*flot);

*/ 
