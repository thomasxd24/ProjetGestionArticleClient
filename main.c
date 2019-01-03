#include"project.h"

/*-------------------------------------------- Menu (v1) --------------------------------------------------------*/

void afficheMenu(void){
    printf("\n --------------------------------- Gestion de stock -------------------------------- \n");
	printf("\t 1 \t Affichage liste des article propose \n");
	printf("\t 2 \t Affichage liste des client ( avec ligne de commandes en attente ) \n");
	printf("\n --------------------------------- Client ------------------------------------------ \n");
	printf("\t 3 \t Creation d'un nouveau client \n");
	printf("\t 4 \t Suppression d'un client ( de toute donnee associe )\n");
	printf("\n --------------------------------- Commande ---------------------------------------- \n");
	printf("\t 5 \t Traitement d'une commande ( mise a jour stock / enregistrement ) \n");
	printf("\t 6 \t Affichage ( ordre alphabetique ) liste des articles en rupture de stock \n");
	printf("\n --------------------------------- Autre ------------------------------------------ \n");
	printf("\t 7 \t Affichage des lignes de commande en cours pour un client donne \n");
	printf("\t 8 \t Sauvegarder de l'ensemble des donnees \n");
	printf("\t 10 \t Quitter \n");
}

int choixMenu(void){
	int n;
	afficheMenu();
	printf("\n Option choisie : ");
	scanf("%d%*c",&n);
	while (n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6 && n!=7 && n!=8){
		afficheMenu();
		printf("\n Option choisie : ");
		scanf("%d",&n);
	}
	return n;
}

/*-------------------------------------------- Menu (v2) --------------------------------------------------------*/

void afficheMenuArt1(void){
    printf("\n --------------------------------- Choix Affichage Article -------------------------------- \n");
	printf("\t 1 \t Affichage liste des article propose (par ordre des modele) \n");
    printf("\t 2 \t Affichage liste des article propose (par prix) \n");
    printf("\t 3 \t Affichage liste des article propose (par taille de stockage) \n");
    printf("\t 4 \t Affichage liste des article propose (par quantite) \n");
    printf("\t 5 \t Affichage liste des article propose (par ID) \n");
    printf("\t 6 \t Affichage d'un article en particulier (par modele) \n");
    printf("\t 10 \t Quitter \n");
}

int choixMenuArt1(void){
	int n;
	afficheMenuArt1();
	printf("\n Option choisie : ");
	scanf("%d%*c",&n);
	while (n!=1 && n!=2 && n!=3 && n!=4 && n!=5 && n!=6){
		afficheMenuArt1();
		printf("\n Option choisie : ");
		scanf("%d",&n);
	}
	return n;
}

/*-------------------------------------------- Chargement tableau ( v1 )--------------------------------------------------------*/



/*-------------------------------------------- Sauvegarder Tableau --------------------------------------------------------*/



/*-------------------------------------------- Chargement tableau ( v2 )--------------------------------------------------------*/



/*-------------------------------------------- TrieDicoArticleModele --------------------------------------------------------*/


/*-------------------------------------------- TrieDicoArticlePrix --------------------------------------------------------*/



/*-------------------------------------------- TrieDicoArticleStockage --------------------------------------------------------*/

void fusionStockage (Article * R[], int n, Article * S[], int m ,Article * t[]){
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if (R[i]->stockage<S[j]->stockage){
			t[k]=R[i];
			i=i+1;
			k=k+1;
		}else{
			t[k]=S[j];
			j=j+1;
			k=k+1;
		}
	}while (i<n){
		t[k]=R[i];
		i=i+1;
		k=k+1;
	}while (j<m){
		t[k]=S[j];
		j=j+1;
		k=k+1;
	}
}

void triDicoStockage (Article * tab[], int n){
	Article **R,**S;
	if (n==1)
		return;
	R=(Article**)malloc((n/2)*sizeof(Article*));
	S=(Article**)malloc((n-(n/2))*sizeof(Article*));
	if (R==NULL || S==NULL){
		printf("Probleme malloc");
		return;
	}
	copier(tab,0,n/2,R);
	copier(tab,n/2,n,S);
	triDicoStockage(R,n/2);
	triDicoStockage(S,n/2);
	fusionStockage(R,n/2,S,n-(n/2),tab);
	free(R);
	free(S);
}

/*-------------------------------------------- TrieDicoArticleQuantite --------------------------------------------------------*/

void fusionQuantite (Article * R[], int n, Article * S[], int m ,Article * t[]){
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if (R[i]->quantite<S[j]->quantite){
			t[k]=R[i];
			i=i+1;
			k=k+1;
		}else{
			t[k]=S[j];
			j=j+1;
			k=k+1;
		}
	}while (i<n){
		t[k]=R[i];
		i=i+1;
		k=k+1;
	}while (j<m){
		t[k]=S[j];
		j=j+1;
		k=k+1;
	}
}

void triDicoQuantite (Article * tab[], int n){
	Article **R,**S;
	if (n==1)
		return;
	R=(Article**)malloc((n/2)*sizeof(Article*));
	S=(Article**)malloc((n-(n/2))*sizeof(Article*));
	if (R==NULL || S==NULL){
		printf("Probleme malloc");
		return;
	}
	copier(tab,0,n/2,R);
	copier(tab,n/2,n,S);
	triDicoQuantite(R,n/2);
	triDicoQuantite(S,n/2);
	fusionQuantite(R,n/2,S,n-(n/2),tab);
	free(R);
	free(S);
}

/*-------------------------------------------- TrieDicoArticleID --------------------------------------------------------*/

void fusionID (Article * R[], int n, Article * S[], int m ,Article * t[]){
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if (R[i]->idarticle<S[j]->idarticle){
			t[k]=R[i];
			i=i+1;
			k=k+1;
		}else{
			t[k]=S[j];
			j=j+1;
			k=k+1;
		}
	}while (i<n){
		t[k]=R[i];
		i=i+1;
		k=k+1;
	}while (j<m){
		t[k]=S[j];
		j=j+1;
		k=k+1;
	}
}

void triDicoID (Article * tab[], int n){
	Article **R,**S;
	if (n==1)
		return;
	R=(Article**)malloc((n/2)*sizeof(Article*));
	S=(Article**)malloc((n-(n/2))*sizeof(Article*));
	if (R==NULL || S==NULL){
		printf("Probleme malloc");
		return;
	}
	copier(tab,0,n/2,R);
	copier(tab,n/2,n,S);
	triDicoID(R,n/2);
	triDicoID(S,n/2);
	fusionID(R,n/2,S,n-(n/2),tab);
	free(R);
	free(S);
}

/*-------------------------------------------- RechercheArticleModele --------------------------------------------------------*/

int rechercherDicoModele(char * rechmodele,Article ** tab, int nbc,int *trouve){
	int inf=0, sup=nbc-1, m;
	while (inf<=sup){
		m=(inf+sup)/2;
		if((strcmp(rechmodele,tab[m]->modele))==0){
			*trouve=1;
			return m;
		}
		if((strcmp(rechmodele,tab[m]->modele))<0)
			sup=m-1;
		else
			inf=m+1;
	}
	*trouve=0;
	return inf;
}
/*-------------------------------------------- RecherheDicoClient --------------------------------------------------------*/

void copierClient(Client * tab[], int i, int j, Client * R[]){
	int t=0;
	while(i<j){
		R[t]=tab[i];
		i=i+1;
		t=t+1;
	}
}

void fusionClient(Client * R[], int n, Client * S[], int m ,Client * t[]){
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if ((strcmp(R[i]->nom,S[j]->nom))<0){
			t[k]=R[i];
			i=i+1;
			k=k+1;
		}else{
			t[k]=S[j];
			j=j+1;
			k=k+1;
		}
	}while (i<n){
		t[k]=R[i];
		i=i+1;
		k=k+1;
	}while (j<m){
		t[k]=S[j];
		j=j+1;
		k=k+1;
	}
}

void triDicoClient(Client * tab[], int n){
	Client **R,**S;
	if (n==1)
		return;
	R=(Client**)malloc((n/2)*sizeof(Client*));
	S=(Client**)malloc((n-(n/2))*sizeof(Client*));
	if (R==NULL || S==NULL){
		printf("Probleme malloc");
		return;
	}
	copierClient(tab,0,n/2,R);
	copierClient(tab,n/2,n,S);
	triDicoClient(R,n/2);
	triDicoClient(S,n/2);
	fusionClient(R,n/2,S,n-(n/2),tab);
	free(R);
	free(S);
}

int rechercherDicoClient(char * rechnom,Client ** tab, int nbc,int *trouve){
	int inf=0, sup=nbc-1, m;
	while (inf<=sup){
		m=(inf+sup)/2;
		if((strcmp(rechnom,tab[m]->nom))==0){
			*trouve=1;
			return m;
		}
		if((strcmp(rechnom,tab[m]->nom))<0)
			sup=m-1;
		else
			inf=m+1;
	}
	*trouve=0;
	return inf;
}

/*-------------------------------------------- SupprimerUnClient --------------------------------------------------------*/

int supprimeClient(Client **tab,int nbc){
	char rechnom[10];
	int pos,trouve,i;
	printf("Saisir le nom d'un client : ");
	scanf("%s%*c",rechnom);
	printf("%s",rechnom);
	pos=rechercherDicoClient(rechnom,tab,nbc,&trouve);
	if (trouve==0){
        printf("\t -------------------\n");
		printf("\t Client non trouvee \n");
        printf("\t -------------------\n");
		return nbc;
	}
	for (i=pos;i<nbc;i++)
		tab[i]=tab[i+1];
	nbc=nbc-1;
	return nbc;
}
