#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"

int main(void)
{
    Article * taba[100];
    int nba,choix,nbc,choixArt1,trouvemodele,posmodele;
    char rechmodele[5];
    nba=remplirTabArticle(taba,100);
    afficherTabArticle(taba,nba);
    printf("Il marche!");
    return 1;
}