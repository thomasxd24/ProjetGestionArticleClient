#ifndef ARTICLEDEF
#define ARTICLEDEF
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"struct.h"
#include"getch.h"

/*-------------------------------------------- Chargement TAB ---------------------------------------------------*/
// Remplir un tableau de pointeur sur des article a partir d’un fichier
Article saisirArticle(FILE *flot);
int remplirTabArticle(Article *tab[], int tmax);

void afficherArticle(Article a);
void afficherTabArticle(Article **tab, int nbarticle);
void afficherTabArticleRupture(Article **tab, int nbarticle);

void sauvegardeArticle(Article a, FILE *flot);
void sauvegardeTabArticle(Article *tab[], int tmax);

int testTriArticle(Article *R, Article *S, int choix);
void copier(Article *tab[], int i, int j, Article *R[]);
void fusion(Article *R[], int n, Article *S[], int m, Article *t[], int choix);
void triDicoArticle(Article *tab[], int n, int choix);
// choix:
// 1: idArticle
// 2: designation
// 3: prix
// 4: quantite
int rechercherDicoArticle(char designation[], Article *tab[], int nbc, int *trouve, int rechID);

int supprimeArticle(Article **tabArt, int nb);

Article saisieArticle(int tailleArt);
int ajouterArticle(Article *tabArt[], int tailleArt);

Article **modificationArt(Article **tabArt, int taille);

void afficherClientCommande(Client client, LigneCommande commande);
ListeCommande verifArtDansCommandes(Article *article, ListeCommande commandes, int *trouve, Client client);
void afficherArticleCommande(Article *article, Client tabClient[], int nbClient, int choixCommande);

void afficherConsultArticle(Article *article, Client tabClient[], int nbClient);
void consulterArticle(Article *tabArt[], int nbArt, Client tabClient[], int nbClient);

char nomFichArt[50]; // declaration de variable global



#endif 