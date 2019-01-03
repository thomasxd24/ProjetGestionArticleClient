#include"article.h"

Article saisirArticle(FILE *flot){
	Article a;
	fscanf(flot,"%d",&a.idarticle);
	fscanf(flot,"%s",a.designation);
	fscanf(flot,"%s",a.modele);
	fscanf(flot,"%d",&a.stockage);
	fscanf(flot, "%f",&a.prixunitaire);
	fscanf(flot, "%d",&a.quantite);
	return a;
}

void afficherArticle(Article a){
	printf("%d \t\t %s \t %s \t %d \t %.2f \t %d \n",a.idarticle,a.designation,a.modele,a.stockage,a.prixunitaire,a.quantite);
}

int remplirTabArticle(Article * tab[],int tmax){
	FILE *flot;
	int i=0;
	Article a;
	flot=fopen("Article.txt","r");
	if(flot==NULL){
		printf("Probleme ouverture");
		return -1;
	}
	a=saisirArticle(flot);
	while(!feof(flot)){
        if(i==tmax){
            printf("Tableau plein");
            return -2;
        }
        tab[i]=(Article *)malloc(sizeof(Article));
		if (tab[i]==NULL)
		{
			printf("Probleme malloc \n");
			return -3;
		}
        *tab[i]=a;
        i=i+1;
        a=saisirArticle(flot);
	}
	fclose(flot);
	return i;
}

void afficherTabArticle(Article ** tab,int nbarticle){
	int i;
	printf("idarticle \t designation \t\t\t prix/unitaire \t quantite \n");
	printf("--------------------------------------------------------------------------\n");
	for (i=0;i<nbarticle;i++)
		afficherArticle(*tab[i]);
}

void sauveTabArticle(Article *tab,int tmax){
	FILE *flot;
	char nomfichier;
	printf("Quel fichier voulez-vous sauvegarder ?");
	scanf("%c",nomfichier);
	flot=fopen(nomfichier,"wb");
	if(flot==NULL){
		printf("Probleme ouverture");
		return;
	}
	fprintf(flot,"%d",tmax);
	fwrite(tab,sizeof(Article),tmax,flot);
	fclose(flot);
}

/*-------------------------------------------- TrieDicoArticleModele --------------------------------------------------------*/

void copier (Article * tab[], int i, int j, Article * R[]){
	int t=0;
	while(i<j){
		R[t]=tab[i];
		i=i+1;
		t=t+1;
	}
}

void fusionModele (Article * R[], int n, Article * S[], int m ,Article * t[]){
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if ((strcmp(R[i]->modele,S[j]->modele))<0){
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

void triDicoModele (Article * tab[], int n){
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
	triDicoModele(R,n/2);
	triDicoModele(S,n/2);
	fusionModele(R,n/2,S,n-(n/2),tab);
	free(R);
	free(S);
}

void fusionPrix (Article * R[], int n, Article * S[], int m ,Article * t[]){
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if (R[i]->prixunitaire<S[j]->prixunitaire){
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

void triDicoPrix (Article * tab[], int n){
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
	triDicoPrix(R,n/2);
	triDicoPrix(S,n/2);
	fusionPrix(R,n/2,S,n-(n/2),tab);
	free(R);
	free(S);
}