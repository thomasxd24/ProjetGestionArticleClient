#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int idClient;
	char civilite[5];
	char nom[10];
	char prenom[10];
	char adresse[50];
} Client;


void copierClient(Client * tab[], int i, int j, Client * R[]);
void fusionClient(Client * R[], int n, Client * S[], int m ,Client * t[]);
void triDicoClient(Client * tab[], int n);
int rechercherDicoClient(char * rechnom,Client ** tab, int nbc,int *trouve);

Client saisirClient(FILE *flot);
Client * chargeTabClient(int * tmax);
void afficherTabClient(Client tab[],int nbclient);



/*-------------------------------------------- SupprimerUnClient --------------------------------------------------------*/

int supprimeClient(Client **tab,int nbc);