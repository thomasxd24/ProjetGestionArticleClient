#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
	int idarticle;
	float prixunitaire;
	int quantite;
    char designation[50];
} Article;

/*-------------------------------------------- Chargement tableau ( v1 )-------------------------------------*/

Article saisirArticle(FILE *flot);// ca marche
void afficherArticle(Article a);// ca marche
int remplirTabArticle(Article * tab[],int tmax);// ca marche
void afficherTabArticle(Article ** tab,int nbarticle);// ca marche

/*-------------------------------------------- Sauvegarder Tableau ------------------------------------------*/

void sauveTabArticle(Article *tab,int tmax);

/*-------------------------------------------- TrieDicoArticleDesignation --------------------------------------------------------*/
void triDicoArticle (Article * tab[], int n,int choix);// ca marche
// choix:
// 1: idarticle
// 2: designation
// 3: prix
// 4: quantite


/*-------------------------------------------- RechercheArticleDesignation --------------------------------------------------------*/

int rechercherDicoDesignation(char * rechmodele,Article ** tab, int nbc,int *trouve); // ca marche

/*-------------------------------------------- RecherheDicoArticle --------------------------------------------------------*/
