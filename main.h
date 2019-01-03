#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
	int idarticle;
	float prixunitaire;
	int quantite;
    char designation[50];
} Article;

typedef struct{
	int idClient;
	char civilite[5];
	char nom[10];
	char prenom[10];
	char adresse[50];
} Client;

/*-------------------------------------------- Menu (v1) ---------------------------------------------------------*/

void afficheMenu(void);
int choixMenu(void);

/*-------------------------------------------- Menu (v2) ---------------------------------------------------------*/

void afficheMenuArt1(void);
int choixMenuArt1(void);



/*-------------------------------------------- Chargement tableau ( v2 )-------------------------------------*/

Client saisirClient(FILE *flot);
Client * chargeTabClient(int * tmax);
void afficherTabClient(Client tab[],int nbclient);



/*-------------------------------------------- SupprimerUnClient --------------------------------------------------------*/

int supprimeClient(Client **tab,int nbc);
