#ifndef LIGNECOMMANDEDEF
#define LIGNECOMMANDEDEF
#include"struct.h"
#include"article.h"
#include"client.h"

/*-------------------------------------------- Fonctions liste --------------------------------------------------------*/
ListeCommande ensembleVide(void);
ListeCommande insererEnTete(ListeCommande e, LigneCommande commande);
ListeCommande ajouterCommande(ListeCommande e, LigneCommande commande);
Booleen commandeEstVide(ListeCommande e);
void afficherCommande(ListeCommande e);
ListeCommande supprimerEnTete(ListeCommande e);
ListeCommande supprimerCommande(ListeCommande e, int idCommande);
int longueur(ListeCommande e);


#endif 

