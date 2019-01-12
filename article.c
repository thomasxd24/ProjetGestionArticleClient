#include "article.h"

/*-------------------------------------------- Chargement TAB ---------------------------------------------------*/

Article saisirArticle(FILE *flot)
{
	Article a;
	fscanf(flot, "%d %f %d ", &a.idarticle, &a.prixunitaire, &a.quantite);

	fgets(a.designation, 50, flot);
	a.designation[strlen(a.designation) - 1] = '\0';
	return a;
}

int remplirTabArticle(Article *tab[], int tmax)
{
	FILE *flot;
	int i = 0;
	Article a;
	flot = fopen("articles.don", "r");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		return -1;
	}
	a = saisirArticle(flot);
	while (!feof(flot))
	{
		if (i == tmax)
		{
			printf("Tableau plein");
			return -2;
		}
		tab[i] = (Article *)malloc(sizeof(Article));
		if (tab[i] == NULL)
		{
			printf("Problème malloc \n");
			return -3;
		}
		*tab[i] = a;
		i = i + 1;
		a = saisirArticle(flot);
	}
	fclose(flot);
	return i;
}

/*-------------------------------------------- Afficher TAB------------------------------------------------------*/

void afficherArticle(Article a)
{
	printf("%d\t┃%.2f\t┃%d\t ┃%s\n", a.idarticle, a.prixunitaire, a.quantite, a.designation);
}

void afficherTabArticle(Article **tab, int nbarticle)
{
	int i;
	printf("Liste des Articles\n");
	printf("━━━━━━━━┳━━━━━━━┳━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("ID\t┃Prix\t┃Quantite┃Designation \n");
	printf("━━━━━━━━╋━━━━━━━╋━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━\n");
	for (i = 0; i < nbarticle; i++)
		afficherArticle(*tab[i]);
	printf("━━━━━━━━┻━━━━━━━┻━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("Nombre d'Article en total : %d \n", nbarticle);
}

void afficherTabArticleRupture(Article **tab, int nbarticle)
{
	int i;
	printf("Liste des Articles en ruptures\n");
	printf("━━━━━━━━┳━━━━━━━┳━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("ID\t┃Prix\t┃Quantite┃Designation \n");
	printf("━━━━━━━━╋━━━━━━━╋━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━\n");
	for (i = 0; i < nbarticle; i++)
		if (tab[i]->quantite == 0)
			afficherArticle(*tab[i]);
	printf("━━━━━━━━┻━━━━━━━┻━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("Nombre d'Article En Rupture : %d \n", nbarticle);
}
/*-------------------------------------------- Sauvegarder TAB --------------------------------------------------*/

void sauvegardeArticle(Article a,FILE * flot){
	fprintf(flot,"%d \t %.2f \t %d \t %s \n",a.idarticle,a.prixunitaire,a.quantite,a.designation);
}

void sauvegardeTabArticle(Article *tab[],int tmax){
	int i;
	FILE *flot;
	flot = fopen("articles.don", "r+");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		return;
	}
	for(i=0;i<tmax;i++){
		sauvegardeArticle(*tab[i],flot);
	}
	printf("Sauvegarde article effectuée\n");
	fclose(flot);
}
/*-------------------------------------------- Trie Dico Article ------------------------------------------------*/
int testTriArticle(Article *R, Article *S, int choix)
{

	switch (choix)
	{
	case 1:
		return R->idarticle - S->idarticle;
		break;
	case 2:
		return strcmp(R->designation, S->designation);
		break;
	case 3:
		return R->prixunitaire - S->prixunitaire;
		break;
	case 4:
		return R->quantite - S->quantite;
		break;

	default:
		break;
	}
}

void copier(Article *tab[], int i, int j, Article *R[])
{
	int t = 0;
	while (i < j)
	{
		R[t] = tab[i];
		i = i + 1;
		t = t + 1;
	}
}

void fusion(Article *R[], int n, Article *S[], int m, Article *t[], int choix)
{
	int i = 0, j = 0, k = 0;
	while (i < n && j < m)
	{
		if ((testTriArticle(R[i], S[j], choix)) < 0)
		{
			t[k] = R[i];
			i = i + 1;
			k = k + 1;
		}
		else
		{
			t[k] = S[j];
			j = j + 1;
			k = k + 1;
		}
	}
	while (i < n)
	{
		t[k] = R[i];
		i = i + 1;
		k = k + 1;
	}
	while (j < m)
	{
		t[k] = S[j];
		j = j + 1;
		k = k + 1;
	}
}

void triDicoArticle(Article *tab[], int n, int choix)
{
	Article **R, **S;
	if (n == 1)
		return;
	R = (Article **)malloc((n / 2) * sizeof(Article *));
	S = (Article **)malloc((n - (n / 2)) * sizeof(Article *));
	if (R == NULL || S == NULL)
	{
		printf("Problème malloc");
		return;
	}
	copier(tab, 0, n / 2, R);
	copier(tab, n / 2, n, S);
	triDicoArticle(R, n / 2, choix);
	triDicoArticle(S, n - n / 2, choix);
	fusion(R, n / 2, S, n - (n / 2), tab, choix);
	free(R);
	free(S);
}

/*-------------------------------------------- Recherche Article Designation ------------------------------------*/

int rechercherDicoArticle(char rechmodele[], Article *tab[], int nbc, int *trouve, int rechID)
{
	if(rechID == -1)
		triDicoArticle(tab,nbc,2);
	else
		triDicoArticle(tab,nbc,1);
	
	
	int inf = 0, sup = nbc - 1, m;
	while (inf <= sup)
	{
		m = (inf + sup) / 2;
		if (rechID == -1)
		{
			if ((strcmp(rechmodele, tab[m]->designation)) == 0)
			{
				*trouve = 1;
				return m;
			}
			if ((strcmp(rechmodele, tab[m]->designation)) < 0)
				sup = m - 1;
			else
				inf = m + 1;
		}
		else
		{
			if (rechID == tab[m]->idarticle)
			{
				*trouve = 1;
				return m;
			}
			if (rechID < tab[m]->idarticle)
				sup = m - 1;
			else
				inf = m + 1;
		}
		
	}
	*trouve = 0;
	return inf;
}

/*-------------------------------------------- Supprimer Article -------------------------------------------------------*/

int supprimeArticle(Article **tabArt, int nb)
{
	char rechdesig_art[50];
	int pos, trouve, i;
	printf("Saisir le nom d'un article : \t");
	scanf("%s%*c", rechdesig_art);
	printf("%s\n", rechdesig_art);
	pos = rechercherDicoArticle(rechdesig_art, tabArt, nb, &trouve,-1);
	if (trouve == 0)
	{
		printf("Article non trouvé \n");
		return nb;
	}
	for (i = pos; i < nb; i++)
		tabArt[i] = tabArt[i + 1];
	nb = nb - 1;
	afficherTabArticle(tabArt, nb);
	return nb;
}

/*-------------------------------------------- Ajouter Article -------------------------------------------------------*/

Article saisieArticle(int tailleArt)
{
	Article a;
	printf("Saisir le nom d'un nouvel article : \t");
	fgets(a.designation, 50, stdin);
	a.designation[strlen(a.designation) - 1] = '\0';
	printf("Prix unitaire : ");
	scanf("%f%*c", &a.prixunitaire);
	printf("Quantité initiale: ");
	scanf("%d%*c", &a.quantite);
	a.idarticle = tailleArt + 1;
	return a;
}

int ajouterArticle(Article *tabArt[], int tailleArt)
{
	Article a;
	int trouve, pos;
	triDicoArticle(tabArt, tailleArt, 1);
	a = saisieArticle(tabArt[tailleArt - 1]->idarticle);
	triDicoArticle(tabArt, tailleArt, 2);
	pos = rechercherDicoArticle(a.designation, tabArt, tailleArt, &trouve,-1);
	if (trouve == 1)
	{
		printf("Erreur: Article déjà enregistré \n");
		return tailleArt;
	}
	tabArt[tailleArt] = (Article *)malloc(sizeof(Article));
	*(tabArt[tailleArt]) = a;
	tailleArt = tailleArt + 1;
	triDicoArticle(tabArt, tailleArt, 2);
	printf("Ajout de l'article réussi.");
	return tailleArt;
}
