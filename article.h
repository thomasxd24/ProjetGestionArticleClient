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

Article saisirArticle(FILE *flot);
void afficherArticle(Article a);
int remplirTabArticle(Article * tab[],int tmax);
void afficherTabArticle(Article ** tab,int nbarticle);

/*-------------------------------------------- Sauvegarder Tableau ------------------------------------------*/

void sauveTabArticle(Article *tab,int tmax);

/*-------------------------------------------- TrieDicoArticleDesignation --------------------------------------------------------*/

void copier (Article * tab[], int i, int j, Article * R[]);
void fusionDesignation (Article * R[], int n, Article * S[], int m ,Article * t[]);
void triDicoDesignation (Article * tab[], int n);

/*-------------------------------------------- TrieDicoArticlePrix --------------------------------------------------------*/

void fusionPrix (Article * R[], int n, Article * S[], int m ,Article * t[]);
void triDicoPrix(Article * tab[], int n);

/*-------------------------------------------- TrieDicoArticleQuantite --------------------------------------------------------*/

void fusionQuantite (Article * R[], int n, Article * S[], int m ,Article * t[]);
void triDicoQuantite (Article * tab[], int n);

/*-------------------------------------------- TrieDicoArticleID --------------------------------------------------------*/

void fusionID (Article * R[], int n, Article * S[], int m ,Article * t[]);
void triDicoID (Article * tab[], int n);

/*-------------------------------------------- RechercheArticleDesignation --------------------------------------------------------*/

int rechercherDicoDesignation(char * rechmodele,Article ** tab, int nbc,int *trouve);

/*-------------------------------------------- RecherheDicoArticle --------------------------------------------------------*/
