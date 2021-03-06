
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ligneCommande.h"

/*-------------------------------------------- Fonctions liste --------------------------------------------------------*/

ListeCommande ensembleVide(void)
{
	return NULL;
}

ListeCommande insererEnTete(ListeCommande e, LigneCommande commande)
{
	ListeCommande m;
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

ListeCommande ajouterCommande(ListeCommande e, LigneCommande commande)
{
	if (e == NULL)
		return insererEnTete(e, commande);
	e->suiv = ajouterCommande(e->suiv, commande);
	return e;
}

Booleen commandeEstVide(ListeCommande e)
{
	if (e == NULL)
		return vrai;
	return faux;
}

void afficherCommande(ListeCommande e)
{
	if (e == NULL)
	{
		return;
	}
		
	while (e != NULL)
	{
	printf("┃%-10d┃%-29s┃%.2f\t    ┃%d\t     ┃%.2f\t  ┃\n", e->v.idCommande, e->v.article->designation, e->v.article->prixunitaire, e->v.quantite, e->v.quantite * e->v.article->prixunitaire);
		e = e->suiv;
	}
}

ListeCommande supprimerEnTete(ListeCommande e)
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

ListeCommande supprimerCommande(ListeCommande e, int idCommande)
{
	if (e == NULL)
		return e;
	if (idCommande == e->v.idCommande)
		return supprimerEnTete(e);
	e->suiv = supprimerCommande(e->suiv, idCommande);
	return e;
}

int longueur(ListeCommande e)
{
	if (e == NULL)
		return 0;
	return 1 + longueur(e->suiv);
}



