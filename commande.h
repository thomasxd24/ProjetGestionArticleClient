#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"client.h"
#include"article.h"
#include"ligneCommande.h"

void calculCommande(Client tabClient[], int posClient, Article *commandeArt, int quantite, int idCommande);
void saisirCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);
void saisirLigneCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt, FILE *flot, int ligne);
void lireFichierCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);
Ensemble verifCommandeEnAttente(Ensemble commandes, Article *commandeArt, int *quantite, Client tabClient[], int pos);
void verifTabClientCommande(Client tabClient[], int nbClient, Article *commandeArt, int *quantite);
void saisirReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);
LigneCommande lireLigneCommande(FILE *flot, Article *tabArt[], int nbArt);
void remplirTabLigneCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);