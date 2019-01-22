#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "main.h"

void lireNomFichier(void)
{
    FILE *flot;
    flot =fopen("projet.config","r");
    fscanf(flot,"%s",nomFichArt);
    fscanf(flot,"%s",nomFichClient);
    fscanf(flot,"%s",nomFichCommande);
    fscanf(flot,"%s",nomFichLivraison);
    fclose(flot);
}

int main(void)
{
    Article *tabArt[100];
    Client *tabClient;
    int nbArt, nbClient;
    system("clear");
    printf("Chargement des nom de fichier...");
    lireNomFichier();
    nbArt = remplirTabArticle(tabArt, 100);
    printf("Réussi\n");
    printf("Chargement des Articles...");
    nbArt = remplirTabArticle(tabArt, 100);
    printf("Réussi\n");
    printf("Chargement des Clients...");
    tabClient = chargeTabClient(tabClient, &nbClient);
    printf("Réussi\n");
    printf("Chargement et traitement des commandes...");
    remplirTabLigneCommande(tabClient, nbClient, tabArt, nbArt);
    printf("Réussi\n");
    printf("Appuyer sur une touche pour continuer...\n");
    getchar();
    menuPrinciple(tabArt, &nbArt, tabClient, &nbClient);
    return 0;
}