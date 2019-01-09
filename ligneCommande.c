#include"ligneCommande.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


Ensemble ensembleVide (void){
	return NULL;
}

Ensemble insererEnTete (Ensemble e, LigneCommande commande){
	Ensemble m;
	m=(Maillon*)malloc(sizeof(Maillon));
	if (m==NULL){
		printf("Erreur de malloc");
		exit (1);
	}
	m->v=commande;
	m->suiv=e;
	return m;

}

Ensemble ajouterCommande(Ensemble e ,LigneCommande commande){
	if (e==NULL)
		return insererEnTete (e,commande);
	e->suiv=ajouterCommande(e->suiv, commande);
	return e;
}


Booleen commandeEstVide(Ensemble e){
	if (e==NULL)
		return vrai;
	return faux;
}

void afficherCommande (Ensemble e){
	if (e==NULL){
		printf("Ensemble vide");
		return;
	}
	printf("%s\n",e->v.artCommande->designation);
	while (e->suiv!=NULL){
		printf("%s\n",e->v.artCommande->designation);
		e=e->suiv;
	}
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

Ensemble supprimerCommande(Ensemble e, Article *x){
	if (e==NULL)
		return e;
	if (x->idarticle==e->v.artCommande->idarticle)
		return supprimerEnTete (e);
	e->suiv= supprimerCommande(e->suiv, x);
	return e;
}

int longueur (Ensemble e){
	if (e==NULL)
		return 0;
	return 1+longueur(e->suiv);
}

int remplirTabLigneCommande(LigneCommande *tab[], int tmax, FILE*flot){
	LigneCommande v;
	int i=0;
	v=lireLigneCommande(flot);
	while(!feof(flot)){
		if(i==tmax)
			return -1;
		tab[i]=(LigneCommande*)malloc(sizeof(LigneCommande));
		if(tab[i]==NULL){
			printf("Probleme malloc \n");
			exit(1);
		}
		*tab[i]=v;
		i=i+1;
		v=lireLigneCommande(flot);
	}
	return i;
}

LigneCommande lireLigneCommande(*flot){
	lireLigneCommande v;
	fscanf(flot,"%d",&v.idCommande);
	fgets(v.artCommande,100,flot);
	v.artCommande[strlen(v.artCommande)-1]="\0";
	fscanf(flot,"%d",&v.quantite);
	return v;
}
