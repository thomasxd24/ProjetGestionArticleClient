#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"ligneCommande.h"
#include"client.h"
#include"article.h"
#include"commande.h"


void menuPrinciple(Article * tabArt[], int *tailleArt,Client tabClient[],int *nbClient);
void menuArticle(Article *tabArt[], int *tailleArt);
void menuClient(Client tabClient[], int *nbClient);
void menuCommande(Client tabClient[], int *nbClient,Article * tabArt[], int *nbArt);
void menuReappro(Client tabClient[], int *nbClient);
void menuReglage(Article *tabArt[], int *tailleArt,Client tabClient[], int *nbClient);






