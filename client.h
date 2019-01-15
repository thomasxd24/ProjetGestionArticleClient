#ifndef CLIENTDEF
#define CLIENTDEF
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"ligneCommande.h"
/*-------------------------------------------- Afficher le tableau des clients --------------------------------------------------------*/

void afficherTabClient(Client tabClient[],int nbClient);

/*-------------------------------------------- Chargement du tableau de client --------------------------------------------------------*/

Client saisirClient(FILE *flot);
Client * chargeTabClient(Client *tabClient,int *nbClient);

/*-------------------------------------------- Tri dico --------------------------------------------------------*/

int testPosClient(Client R, Client S, int choix);
void copierClient(Client tab[], int i, int j, Client R[]);
void fusionClient(Client R[], int n, Client S[], int m, Client t[], int trieID);
void triDicoClient(Client tab[], int n,int trieID);

/*-------------------------------------------- Recherche dico --------------------------------------------------------*/

int rechercherDicoClient(char *rechnom, Client tab[], int nbc, int *trouve, int rechID);
// si recherche id, alors rechnom doit etre '\0'
//si recherche client nom, alors rechID doit etre -1

/*-------------------------------------------- SupprimerUnClient --------------------------------------------------------*/

int supprimeClient(Client * tabClient,int nb);

/*-------------------------------------------- Ajouter un client -------------------------------------------------------*/

Client saisieClient(int nb);
Client * ajouterClient(Client tabClient[], int *nbClient);

/*-------------------------------------------- Sauvegarder un client -------------------------------------------------------*/

void sauvegardeTabClient(Client tab[],int tmax);
void sauvegardeClient(Client c,FILE * flot);

void consulterClient(Client tabClient[],int nbClient);
Client * modification(Client *tabClient,int taille);
#endif /* EXAMPLE_H *

/* Fonctionnalite à rajouter :
- Pouvoir rajouter une fonction qui recherche un client et qui affiche seulement ce client
- Lier les clients aux listes de commande
- Fonction ModifierClient

Fonction à modifier: 
- fonction rajouter client

*/ 