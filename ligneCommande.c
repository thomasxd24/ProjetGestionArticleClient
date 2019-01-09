#include"ligneCommande.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
Ensemble ensembleVide (void){
	return NULL;
}

Ensemble insererEnTete (Ensemble e, int x){
	Ensemble m;
	m=(Maillon*)malloc(sizeof(Maillon));
	if (m==NULL){
		printf("Erreur de malloc");
		exit (1);
	}
	m->v.idCommande=x;
	m->suiv=e;
	return m;

}

Ensemble ajouter (Ensemble e ,int x){
	if (e==NULL)
		return insererEnTete (e,x);
	if (x<e->v.idCommande)
		return insererEnTete (e,x);
	if (x==e->v.idCommande)
		return e;
	e->suiv=ajouter (e->suiv, x);
	return e;
}


Booleen vide (Ensemble e){
	if (e==NULL)
		return vrai;
	return faux;
}

void afficherEnsemble (Ensemble e){
	if (e==NULL){
		printf("Ensemble vide");
		return;
	}
	printf("e={");
	while (e->suiv!=NULL){
		printf("%s,",e->v.artCommande->designation);
		e=e->suiv;
	}
	printf("%d}",e->v.idCommande);
}

Ensemble supprimerEnTete (Ensemble e){
	Maillon * aux;
	if (e==NULL){
		printf ("Opération impossible");
		exit (1);
	}
	aux=e;
	e=e->suiv;
	free (aux);
	return e;
}

Ensemble supprimer(Ensemble e, int x){
	if (e==NULL)
		return e;
	if (x<e->v.idCommande)
		return e;
	if (x==e->v.idCommande)
		return supprimerEnTete (e);
	e->suiv= supprimer (e->suiv, x);
	return e;
}

int longueur (Ensemble e){
	if (e==NULL)
		return 0;
	return 1+longueur(e->suiv);
}
