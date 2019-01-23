#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"client.h"
#include"article.h"
#include"ligneCommande.h"

void calculCommande(Client tabClient[], int posClient, Article *commandeArt, int quantite, int idCommande);
Client * saisirCommande(Client tabClient[], int *nbClient, Article *tabArt[], int nbArt);

LigneCommande lireLigneCommande(FILE *flot, Article *tabArt[], int nbArt);
void remplirTabLigneCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);

ListeCommande verifCommandeEnAttente(ListeCommande commandes, Article *commandeArt, int *quantite, Client tabClient[], int pos);
void verifTabClientCommande(Client tabClient[], int nbClient, Article *commandeArt, int *quantite);

void saisirReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);

void saisirLigneReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt, FILE *flot);
void lireFichierReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt);

void supprimerCommandeEnAttente(Client tabClient[], int nbClient);

ListeCommande sauvegardeCommande(ListeCommande e, FILE *flot);
void sauvegardeListeCommandes(Client tabClient[], int nbClient);

char nomFichCommande[50];
char nomFichLivraison[50];