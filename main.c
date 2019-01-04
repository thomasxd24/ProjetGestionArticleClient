#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    Article *tabArt[100];
    Client *tabClient;
   
    int nbArt,nbClient;
    nbArt = remplirTabArticle(tabArt, 100);
    tabClient = chargeTabClient(tabClient,&nbClient);
    // menuPrinciple(tabArt,nbArt);
    afficherTabClient(tabClient,nbClient);
    triDicoClient(tabClient, nbClient);
    afficherTabClient(tabClient,nbClient);
    printf("Il marche!\n");
    return 0;
}