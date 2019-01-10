
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"ligneCommande.h"

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
	printf("%s\n",e->v.article->designation);
	while (e->suiv!=NULL){
		printf("%s\n",e->v.article->designation);
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
	if (x->idarticle==e->v.article->idarticle)
		return supprimerEnTete (e);
	e->suiv= supprimerCommande(e->suiv, x);
	return e;
}

int longueur (Ensemble e){
	if (e==NULL)
		return 0;
	return 1+longueur(e->suiv);
}




LigneCommande lireLigneCommande(FILE*flot,Article *tabArt[], int nbArt){
	LigneCommande v;
	Article * art;
	int pos,trouve,idArt;
	fscanf(flot,"%d",&v.idCommande);
	fscanf(flot,"%d",&idArt);
	pos=rechercherDicoArticle('\0',tabArt,nbArt,&trouve,idArt);
	if(!trouve)//Article non trouvee, passer au prochain lignecommande
		v.article=NULL;
	else
		v.article=tabArt[pos];
	fscanf(flot,"%d",&v.quantite);
	return v;
}

void remplirTabLigneCommande(Client tabClient[],int nbClient, Article *tabArt[], int nbArt){
	FILE *flot;
	LigneCommande commande;
	int trouve,pos;
	flot = fopen("ligneCommandes.don", "r");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		return;
	}
	commande=lireLigneCommande(flot,tabArt,nbArt);
	while(!feof(flot)){
		pos=rechercherDicoClient('\0',tabClient,nbClient,&trouve,commande.idClient);
		if(!trouve||commande.article==NULL)//Client non trouvee ou article non trouvee, passer au prochain lignecommande
		{
			commande=lireLigneCommande(flot,tabArt,nbArt);
			continue;
		}
		tabClient[pos].commandes=ajouterCommande(tabClient[pos].commandes,commande);
		commande=lireLigneCommande(flot,tabArt,nbArt);
	}
}


LigneCommande supprimerLigneCommandeVide(Article *tabArt[], int nbArt){
	int i, j;
	for(i=0;i<nb;i++){	
		if(tabArt[i]->commande=ensembleVide()){	
			free(tabArt[i]);
			for(j=i;j<nbArt-1;j++)
				tabArt[j]=tabArt[j+1];
		}
		nbArt=nbArt-1;
	}
	return nbArt;
}

void triEchange(Article *tabArt[], int nbArt)
{
	int pge;
	while(nbArt>1)
	{	pge=plusGrand(tabArt,nbArt);
		echanger(tabArt,pge,nbArt-1);
		nbArt=nbArt-1;
	}
}

void echanger(Article *tabArt[], int i, int j)
{
	Article * aux;
	aux=tabArt[i];
	tabArt[i]=tabArt[j];
	tabArt[j]=aux;
}

int plusGrand(Article *tabArt[], int nbArt)
{
	int pge=0, i;
	for(i=0;i<nbArt;i++)
		if(*(tabArt[i]->commande)>*(tabArt[pge]->commande))
			pge=1;
	return pge;
}

void sauvegarder (Article *tabArt[], int nbArt, FILE*flot)
{
	int i;
	for(i=0;i<nbArt;i++)
	{	fprintf(flot,"%d %s %d %d",tabArt[i]->commande,tabArt[i]->commande,*(tabArt[i]->commande))
		affciherCommande(tabArt[i]-commande,flot)
	}
}