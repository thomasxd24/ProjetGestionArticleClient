#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#ifndef SOME_HEADER_GUARD_WITH_UIQUE_NAME
#define SOME_HEADER_GUARD_WITH_UIQUE_NAME
typedef struct{
	int idClient;
	char civilite[5];
	char nom[10];
	char prenom[10];
	char adresse[50];
} Client;


void triDicoClient(Client tab[], int n,int trieID);
int rechercherDicoClient(char * rechnom,Client * tab, int nbc,int *trouve);

Client saisirClient(FILE *flot);
Client * chargeTabClient(Client *tabClient,int *nbClient);
void afficherTabClient(Client tabClient[],int nbClient);



/*-------------------------------------------- SupprimerUnClient --------------------------------------------------------*/

int supprimeClient(Client * tabClient,int nb);
int adjouterClient(Client tabClient[], int nbClient);
#endif /* EXAMPLE_H */