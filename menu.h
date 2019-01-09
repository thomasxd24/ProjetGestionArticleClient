#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"article.h"
#include"client.h"
#include"ligneCommande.h"

/*-------------------------------------------- Menu ---------------------------------------------------------*/
int afficheMenuPrinciple(void);
void menuPrinciple(Article * tabArt[], int *tailleArt,Client tabClient[],int *nbClient);

/*-------------------------------------------- Menu Article -------------------------------------------------*/
void afficheMenuArticle(void);
void menuArticle(Article *tabArt[], int *tailleArt);
void afficheChoixTriArticle(void);
void menuChoixTriArticle(Article *tabArticle[], int *nbArticle);

/*-------------------------------------------- Menu Client --------------------------------------------------*/
void afficheMenuClient(void);
void menuClient(Client tabClient[], int *nbClient);
void afficheChoixTriClient(void);
void menuChoixTriClient(Client tabClient[], int *nbClient);


/*-------------------------------------------- Menu Reglage --------------------------------------------------*/
int afficheMenuReglage(void);
void menuReglage(Article *tabArt[], int *tailleArt);

/*-------------------------------------------- Menu Commande --------------------------------------------------*/
int afficheMenuCommande(void);
void menuCommande(Article *tabArt[], int *tailleArt);






