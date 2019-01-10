#ifndef SOME_HEADER_GUARD_WITH_UIQUE_NAME
#define SOME_HEADER_GUARD_WITH_UIQUE_NAME
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"



void triDicoClient(Client tab[], int n,int trieID);
int rechercherDicoClient(char *rechnom, Client tab[], int nbc, int *trouve, int rechID);
// si recherche id, alors rechnom doit etre '\0'
//si recherche client nom, alors rechID doit etre -1
Client saisirClient(FILE *flot);
Client * chargeTabClient(Client *tabClient,int *nbClient);
void afficherTabClient(Client tabClient[],int nbClient);



/*-------------------------------------------- SupprimerUnClient --------------------------------------------------------*/

int supprimeClient(Client * tabClient,int nb);
int adjouterClient(Client tabClient[], int nbClient);



void remplirTabLigneCommande(Client tabClient[],int nbClient, Article *tabArt[], int nbArt);
#endif /* EXAMPLE_H */