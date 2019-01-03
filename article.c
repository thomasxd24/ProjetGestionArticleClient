#include"article.h"
#define champ choix
Article saisirArticle(FILE *flot){
	Article a;
	fscanf(flot,"%d %f %d ",&a.idarticle,&a.prixunitaire,&a.quantite);
	
	fgets(a.designation,50,flot);
	a.designation[strlen(a.designation)-2]='\0';
	return a;
}

void afficherArticle(Article a){
	printf("%d\t\t%.2f\t\t%d\t\t%s\n",a.idarticle,a.prixunitaire,a.quantite,a.designation);
}

int remplirTabArticle(Article * tab[],int tmax){
	FILE *flot;
	int i=0;
	Article a;
	flot=fopen("articles.don","r");
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
	printf("IDArticle  \tPrix Unitaire \tQuantite \t Designation \n");
	printf("--------------------------------------------------------------------------\n");
	for (i=0;i<nbarticle;i++)
		afficherArticle(*tab[i]);
}

void sauveTabArticle(Article *tab,int tmax){
	FILE *flot;
	char nomfichier[50];
	printf("Quel fichier voulez-vous sauvegarder ?");
	scanf("%s",nomfichier);
	flot=fopen(nomfichier,"wb");
	if(flot==NULL){
		printf("Probleme ouverture");
		return;
	}
	fprintf(flot,"%d",tmax);
	fwrite(tab,sizeof(Article),tmax,flot);
	fclose(flot);
}
void copier(Article * tab[], int i, int j, Article * R[]){
	int t=0;
	while(i<j){
		R[t]=tab[i];
		i=i+1;
		t=t+1;
	}
}

int testPosArticle(Article * R, Article * S,int choix)
{
	
	switch (choix)
	{
		case 1:
			return R->idarticle-S->idarticle;
			break;
		case 2:
			return strcmp(R->designation,S->designation);
			break;
		case 3:
			return R->prixunitaire-S->prixunitaire;
			break;
		case 4:
			return R->quantite-S->quantite;
			break;
	
		default:
			break;
	}
}

void fusion (Article * R[], int n, Article * S[], int m ,Article * t[],int choix){
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if ((testPosArticle(R[i],S[j],choix))<0){
			t[k]=R[i];
			i=i+1;
			k=k+1;
		}else{
			t[k]=S[j];
			j=j+1;
			k=k+1;
		}
	}
	while (i<n){
		t[k]=R[i];
		i=i+1;
		k=k+1;
	}
	while (j<m){
		t[k]=S[j];
		j=j+1;
		k=k+1;
	}
}

void triDicoArticle (Article * tab[], int n,int choix){
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
	triDicoArticle(R,n/2,choix);
	triDicoArticle(S,n-n/2,choix);
	fusion(R,n/2,S,n-(n/2),tab,choix);
	free(R);
	free(S);
}



/*-------------------------------------------- RechercheArticleModele --------------------------------------------------------*/

int rechercherDicoDesignation(char rechmodele[],Article * tab[], int nbc,int *trouve){
	Article hi;
	int inf=0, sup=nbc-1, m;
	while (inf<=sup){
		m=(inf+sup)/2;
		hi=*tab[m];
		if((strcmp(rechmodele,tab[m]->designation))==0){
			*trouve=1;
			return m;
		}
		if((strcmp(rechmodele,tab[m]->designation))<0)
			sup=m-1;
		else
			inf=m+1;
	}
	*trouve=0;
	return inf;
}