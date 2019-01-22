#ifndef CLIENTDEF
#define CLIENTDEF
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"ligneCommande.h"
/*-------------------------------------------- Afficher le tableau des clients --------------------------------------------------------*/

void afficherTabClient(Client tabClient[], int nbClient);
Client saisirClient(FILE *flot);
Client *chargeTabClient(Client *tabClient, int *nbClient);
int testPosClient(Client R, Client S, int choix);
void copierClient(Client tab[], int i, int j, Client R[]);
void fusionClient(Client R[], int n, Client S[], int m, Client t[], int trieID);
void triDicoClient(Client tab[], int n, int trieID);
int rechercherDicoClient(char *rechnom, Client tab[], int nbc, int *trouve, int rechID);
int supprimeClient(Client *tabClient, int nb);
Client saisieClient(int nb);
Client *ajouterClient(Client tabClient[], int *nbClient);
void afficherConsultClient(Client client);
void consulterClient(Client tabClient[], int nbClient);
void sauvegardeClient(Client c, FILE *flot);
void sauvegardeTabClient(Client tab[], int tmax);
Client *modification(Client *tabClient, int taille);
char nomFichClient[50];
#endif /* EXAMPLE_H */