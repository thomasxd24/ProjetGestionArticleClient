#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"ligneCommande.h"
#include"client.h"
#include"article.h"


void menuPrinciple(Article * tabArt[], int *tailleArt,Client tabClient[],int *nbClient);
void menuArticle(Article *tabArt[], int *tailleArt);
void menuClient(Client tabClient[], int *nbClient);
void menuCommande(Article *tabArt[], int nbArt);
void menuReglage(Article *tabArt[], int *tailleArt,Client tabClient[], int *nbClient);






