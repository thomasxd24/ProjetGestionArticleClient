#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"

int main(void)
{
    Article *tabArt[100];
    Client *tabClient;
    Ensemble en;
    LigneCommande lc;
    int nbArt,nbClient;
    printf("Chargement des Articles...");
    nbArt = remplirTabArticle(tabArt, 100);
    printf("Réussi\n");
    printf("Chargement des Clients...");
    tabClient = chargeTabClient(tabClient,&nbClient);
    printf("Réussi\n");
    printf("Appuyer sur une touche pour continuer...\n");  
    getchar();
    menuPrinciple(tabArt,&nbArt,tabClient,&nbClient);

    return 0;
}