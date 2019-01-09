#ifndef SOME_HEADER_GUARD_WITH_UNIQUE_NAME
#define SOME_HEADER_GUARD_WITH_UNIQUE_NAME
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*-------------------------------------------- Structure -------------------------------------------------------*/

typedef struct{
	int idarticle;
	float prixunitaire;
	int quantite;
    char designation[50];
} Article;	

/*-------------------------------------------- Chargement TAB ---------------------------------------------------*/

Article saisirArticle(FILE *flot);// ca marche
int remplirTabArticle(Article * tab[],int tmax);// ca marche

/*-------------------------------------------- Afficher TAB------------------------------------------------------*/

void afficherArticle(Article a);// ca marche
void afficherTabArticleRupture(Article ** tab,int nbarticle);// ca marche
void afficherTabArticle(Article ** tab,int nbarticle);// ca marche

/*-------------------------------------------- Sauvegarder TAB --------------------------------------------------*/

void sauveTabArticle(Article *tab,int tmax);

/*-------------------------------------------- Trie Dico Article -------------------------------------------------*/

void triDicoArticle (Article * tab[], int n,int choix);// ca marche
// choix:
// 1: idarticle
// 2: designation
// 3: prix
// 4: quantite

/*-------------------------------------------- Recherche Article Designation --------------------------------------*/

int rechercherDicoDesignation(char * rechmodele,Article ** tab, int nbc,int *trouve); // ca marche

/*-------------------------------------------- Supprimer Article --------------------------------------------------*/

int supprimeArticle(Article ** tabArt,int nb);

/*-------------------------------------------- Ajouter Article -----------------------------------------------------*/

int adjouterArticle(Article *tabArt[], int tailleArt);



#endif /* EXAMPLE_H */

/* Fonctionnalite à rajouter :
- Pouvoir rajouter une fonction qui recherche un article et qui affiche seulement cette article
- Rajouter les different triDicoArticle dans le menu triDicoArticle
- Lier les article au liste de commande
- Fonction ModifierArticle 

Fonctionnalite à modifier :
- sauveTabArticle = fonctionne pas
*/ 