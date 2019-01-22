
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
		return e;
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
		printf("┃     -    ┃               -             ┃    -     ┃   -    ┃     -      ┃\n");
		return;
	}
		
	while (e != NULL)
	{
	printf("┃%-10d┃%-29s┃%.2f\t    ┃%d\t     ┃%.2f\t  ┃\n", e->v.idCommande, e->v.article->designation, e->v.article->prixunitaire, e->v.quantite, e->v.quantite * e->v.article->prixunitaire);
		e = e->suiv;
	}
}

Ensemble supprimerEnTete(Ensemble e)
{
	Maillon *aux;
	if (e == NULL)
	{
		printf("Opération impossible");
		return e;
	}
	aux = e;
	e = e->suiv;
	free(aux);
	return e;
}

Ensemble supprimerCommande(Ensemble e, int idCommande)
{
	if (e == NULL)
		return e;
	if (idCommande == e->v.idCommande)
		return supprimerEnTete(e);
	e->suiv = supprimerCommande(e->suiv, idCommande);
	return e;
}

int longueur(Ensemble e)
{
	if (e == NULL)
		return 0;
	return 1 + longueur(e->suiv);
}

/*-------------------------------------------- Chargement tableau--------------------------------------------------------*/



Ensemble sauvegardeCommande(Ensemble e,FILE *flot)
{
	if (e == NULL)
	{
		return e;
	}	
	fprintf(flot,"%d %d %d %d\n", e->v.idCommande, e->v.article->idarticle, e->v.idClient,e->v.quantite);
	e->suiv=sauvegardeCommande(e->suiv,flot);
	return e;
}

void sauvegardeListeCommandes(Client tabClient[],int nbClient){
	int i;
	FILE *flot;
	flot = fopen(nomFichCommande, "w");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		return;
	}
	for(i = 0; i < nbClient; i++)
	{
		sauvegardeCommande(tabClient[i].commandesEnAttente,flot);
	}
	printf("sauvegarde ligne commande effectuée");
	fclose(flot);
}