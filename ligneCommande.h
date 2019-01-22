#ifndef LIGNECOMMANDEDEF
#define LIGNECOMMANDEDEF
#include"struct.h"
#include"article.h"
#include"client.h"

/*-------------------------------------------- Fonctions liste --------------------------------------------------------*/
Ensemble ensembleVide(void);
Ensemble insererEnTete(Ensemble e, LigneCommande commande);
Ensemble ajouterCommande(Ensemble e, LigneCommande commande);
Booleen commandeEstVide(Ensemble e);
void afficherCommande(Ensemble e);
Ensemble supprimerEnTete(Ensemble e);
Ensemble supprimerCommande(Ensemble e, int idCommande);
int longueur(Ensemble e);
Ensemble sauvegardeCommande(Ensemble e, FILE *flot);
void sauvegardeListeCommandes(Client tabClient[], int nbClient);


#endif 

