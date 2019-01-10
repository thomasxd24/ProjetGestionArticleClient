
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ligneCommande.h"

/*-------------------------------------------- Fonctions liste --------------------------------------------------------*/

Ensemble ensembleVide(void)
{
	return NULL;
}

Ensemble insererEnTete(Ensemble e, LigneCommande commande)
{
	Ensemble m;
	m = (Maillon *)malloc(sizeof(Maillon));
	if (m == NULL)
	{
		printf("Erreur de malloc");
		exit(1);
	}
	m->v = commande;
	m->suiv = e;
	return m;
}

Ensemble ajouterCommande(Ensemble e, LigneCommande commande)
{
	if (e == NULL)
		return insererEnTete(e, commande);
	e->suiv = ajouterCommande(e->suiv, commande);
	return e;
}

Booleen commandeEstVide(Ensemble e)
{
	if (e == NULL)
		return vrai;
	return faux;
}

void afficherCommande(Ensemble e)
{
	if (e == NULL)
	{
		printf("Ensemble vide");
		return;
	}
		
	while (e != NULL)
	{
	printf("┃%d\t   ┃%-19s┃%.2f\t  ┃%d\t   ┃%.2f\t┃\n", e->v.idCommande, e->v.article->designation, e->v.article->prixunitaire, e->v.quantite, e->v.quantite * e->v.article->prixunitaire);
		e = e->suiv;
	}
}

Ensemble supprimerEnTete(Ensemble e)
{
	Maillon *aux;
	if (e == NULL)
	{
		printf("Opération impossible");
		exit(1);
	}
	aux = e;
	e = e->suiv;
	free(aux);
	return e;
}

Ensemble supprimerCommande(Ensemble e, Article *x)
{
	if (e == NULL)
		return e;
	if (x->idarticle == e->v.article->idarticle)
		return supprimerEnTete(e);
	e->suiv = supprimerCommande(e->suiv, x);
	return e;
}

int longueur(Ensemble e)
{
	if (e == NULL)
		return 0;
	return 1 + longueur(e->suiv);
}

/*-------------------------------------------- Chargement tableau--------------------------------------------------------*/

LigneCommande lireLigneCommande(FILE *flot, Article *tabArt[], int nbArt)
{
	LigneCommande v;
	Article *art;
	int pos, trouve, idArt;
	fscanf(flot, "%d%d%d%d", &v.idCommande,&idArt,&v.idClient,&v.quantite);
	printf("%d %d %d", v.idCommande,v.idClient,v.quantite);
	pos = rechercherDicoArticle('\0', tabArt, nbArt, &trouve, idArt);
	if (!trouve) //Article non trouvee, passer au prochain lignecommande
		v.article = NULL;
	else
		v.article = tabArt[pos];
	return v;
}

void remplirTabLigneCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
	FILE *flot;
	LigneCommande commande;
	int trouve, pos;
	flot = fopen("ligneCommandes.don", "r");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		return;
	}
	
	while (!feof(flot))
	{
		commande = lireLigneCommande(flot, tabArt, nbArt);
		pos = rechercherDicoClient('\0', tabClient, nbClient, &trouve, commande.idClient);
		printf("|%d %d %d", commande.idCommande,commande.idClient,commande.quantite);
		if (!trouve || commande.article == NULL) //Client non trouvee ou article non trouvee, passer au prochain lignecommande
		{
			printf("%d", commande.article == NULL);
			commande = lireLigneCommande(flot, tabArt, nbArt);
			continue;
		}
		printf("ajout");
		tabClient[pos].commandes = ajouterCommande(tabClient[pos].commandes, commande);
	}
}
