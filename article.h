#ifndef ARTICLEDEF
#define ARTICLEDEF
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"

/*-------------------------------------------- Chargement TAB ---------------------------------------------------*/

Article saisirArticle(FILE *flot);// ca marche
int remplirTabArticle(Article * tab[],int tmax);// ca marche

/*-------------------------------------------- Afficher TAB------------------------------------------------------*/

void afficherArticle(Article a);// ca marche
void afficherTabArticleRupture(Article ** tab,int nbarticle);// ca marche
void afficherTabArticle(Article ** tab,int nbarticle);// ca marche

/*-------------------------------------------- Sauvegarder TAB --------------------------------------------------*/

void sauvegardeArticle(Article a,FILE * flot);
void sauvegardeTabArticle(Article *tab[],int tmax);

/*-------------------------------------------- Trie Dico Article -------------------------------------------------*/

int testPosArticle(Article * R, Article * S,int choix);
void copier(Article * tab[], int i, int j, Article * R[]);
void fusion (Article * R[], int n, Article * S[], int m ,Article * t[],int choix);
void triDicoArticle (Article * tab[], int n,int choix);// ca marche
// choix:
// 1: idarticle
// 2: designation
// 3: prix
// 4: quantite

/*-------------------------------------------- Recherche Article-------------------------------------*/

int rechercherDicoArticle(char * rechmodele,Article ** tab, int nbc,int *trouve,int choixID); // ca marche
// choix:
// 1: idarticle
// 2: designation
/*-------------------------------------------- Supprimer Article --------------------------------------------------*/

int supprimeArticle(Article ** tabArt,int nb);

/*-------------------------------------------- Ajouter Article -----------------------------------------------------*/

Article saisieArticle(int tailleArt);
int ajouterArticle(Article *tabArt[], int tailleArt);
Article ** modificationArt(Article **tabArt,int taille);


#endif /* EXAMPLE_H */

/* Fonctionnalite à rajouter :
- Pouvoir rajouter une fonction qui recherche un article et qui affiche seulement cette article
- Lier les article au liste de commande
- Fonction ModifierArticle 

*/ 