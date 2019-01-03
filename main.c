#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"main.h"

int main(void)
{
    Article * taba[100],*hi;
    int nba,choix,nbc,choixArt1,trouvemodele,posmodele,trouve,op;
    char rechmodele[5];
    nba=remplirTabArticle(taba,100);
    afficherTabArticle(taba,nba);
    
    triDicoArticle(taba,nba,2);
    op=rechercherDicoDesignation("Chocolat",taba,nba,&trouve);
    hi=taba[op];
    printf("%d\n",hi->idarticle);
    printf("%d\n",trouve);
    afficherTabArticle(taba,nba);
    printf("Il marche!\n");
    return 1;
}