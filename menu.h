#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"ligneCommande.h"
#include"client.h"
#include"article.h"
#include"commande.h"


int choixMenu(void);
void afficheMenuPrinciple(void);
void menuPrinciple(Article *tabArt[], int *tailleArt, Client tabClient[], int *nbClient);
void afficheMenuArticle(void);
void afficheMenuCommande(void);
void afficheMenuReappro(void);
void afficheChoixTriArticle(void);
void menuChoixTriArticle(Article *tabArticle[], int *nbArticle);
void menuArticle(Article *tabArt[], int *tailleArt, Client tabClient[], int *nbClient);
void afficheMenuClient(void);
void afficheChoixTriClient(void);
void menuChoixTriClient(Client tabClient[], int *nbClient);
void menuClient(Client tabClient[], int *nbClient);
void menuCommande(Client *tabClient[], int *nbClient, Article *tabArt[], int *nbArt);
void menuReappro(Client tabClient[], int *nbClient, Article *tabArt[], int *nbArt);
void afficheMenuReglage(void);
void menuReglage(Article *tabArt[], int *tailleArt, Client tabClient[], int *nbClient);







