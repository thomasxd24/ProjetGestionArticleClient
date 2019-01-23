#include "article.h"

/*-------------------------------------------- Chargement TAB ---------------------------------------------------*/

Article saisirArticle(FILE *flot)
{
	Article a;
	fscanf(flot, "%d%f%d ", &a.idArticle, &a.prixunitaire, &a.quantite);

	fgets(a.designation, 50, flot);
	a.designation[strlen(a.designation) - 2] = '\0'; // -2 parce que il faut encore eliminer le \n sinon il ne marche pas
	return a;
}

int remplirTabArticle(Article *tab[], int tmax)
{
	FILE *flot;
	int i = 0;
	Article a;
	flot = fopen(nomFichArt, "r");
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
	printf("%d\t┃%.2f\t┃%d\t ┃%s\n", a.idArticle, a.prixunitaire, a.quantite, a.designation);
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

void sauvegardeArticle(Article a, FILE *flot)
{
	fprintf(flot, "\n%d %.2f %d %s", a.idArticle, a.prixunitaire, a.quantite, a.designation);
}

void sauvegardeTabArticle(Article *tab[], int tmax)
{
	int i;
	FILE *flot;
	flot = fopen(nomFichArt, "w");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		return;
	}
	for (i = 0; i < tmax; i++)
	{
		sauvegardeArticle(*tab[i], flot);
	}
	fclose(flot);
}
/*-------------------------------------------- Trie Dico Article ------------------------------------------------*/
int testTriArticle(Article *R, Article *S, int choix)
{

	switch (choix)
	{
	case 1:
		return R->idArticle - S->idArticle;
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

int rechercherDicoArticle(char designation[], Article *tab[], int nbc, int *trouve, int rechID)
{
	if (rechID == -1) //on recherche par nom
		triDicoArticle(tab, nbc, 2);
	else
		triDicoArticle(tab, nbc, 1);

	int inf = 0, sup = nbc - 1, m;
	while (inf <= sup)
	{
		m = (inf + sup) / 2;
		if (rechID == -1)//on recherche par nom
		{
			if ((strcmp(designation, tab[m]->designation)) == 0)
			{
				*trouve = 1;
				return m;
			}
			if ((strcmp(designation, tab[m]->designation)) < 0)
				sup = m - 1;
			else
				inf = m + 1;
		}
		else
		{
			if (rechID == tab[m]->idArticle)
			{
				*trouve = 1;
				return m;
			}
			if (rechID < tab[m]->idArticle)
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
	pos = rechercherDicoArticle(rechdesig_art, tabArt, nb, &trouve, -1);
	if (trouve == 0)
	{
		printf("Article non trouvé \n");
		return nb;
	}
	free(tabArt[pos]);
	for (i = pos; i < nb; i++)
		tabArt[i] = tabArt[i + 1];
	nb = nb - 1;
	printf("Article supprimé.\n");
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
	a.idArticle = tailleArt + 1;
	return a;
}

int ajouterArticle(Article *tabArt[], int tailleArt)
{
	Article a;
	int trouve, pos;
	triDicoArticle(tabArt, tailleArt, 1);
	a = saisieArticle(tabArt[tailleArt - 1]->idArticle);
	triDicoArticle(tabArt, tailleArt, 2);
	pos = rechercherDicoArticle(a.designation, tabArt, tailleArt, &trouve, -1);
	if (trouve == 1)
	{
		printf("Erreur: Article déjà enregistré (Désignation déjà existant)\n");
		return tailleArt;
	}
	tabArt[tailleArt] = (Article *)malloc(sizeof(Article));
	*(tabArt[tailleArt]) = a;
	tailleArt = tailleArt + 1;
	triDicoArticle(tabArt, tailleArt, 2);
	printf("Ajout de l'article réussi.\n");
	return tailleArt;
}

/*-------------------------------------------- Modification article -------------------------------------------------------*/

Article **modificationArt(Article **tabArt, int taille)
{
	Article a;
	int id, pos, trouve;
	char choix;
	printf("Veuillez entrer le nom d'un article :");
	fgets(a.designation, 50, stdin);
	a.designation[strlen(a.designation) - 1] = '\0';
	pos = rechercherDicoArticle(a.designation, tabArt, taille, &trouve, -1);
	if (trouve == 0)
	{
		printf("Article non enregistré\n");
		return tabArt;
	}
	printf("\nVoici l'article' %s:\n", a.designation);
	printf("━━━━━━━━┳━━━━━━━┳━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("ID\t┃Prix\t┃Quantite┃Designation \n");
	printf("━━━━━━━━╋━━━━━━━╋━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━\n");
	afficherArticle(*tabArt[pos]);
	printf("\nConfirmez vous que vous souhaitez modifier ce article?(O/N)");
	scanf("%c%*c", &choix);
	if (choix == 'O' || choix == 'o')
	{
		a = *tabArt[pos];
		printf("Voulez vous modifier le prix unitaire ? (O/N) ");
		scanf("%c%*c", &choix);
		if (choix == 'o' || choix == 'O')
		{
			printf("Saisir le nouveau prix unitaire\t");
			scanf("%f%*c", &a.prixunitaire);
		}
		printf("Voulez vous modifier la quantite ? (O/N) ");
		scanf("%c%*c", &choix);
		if (choix == 'o' || choix == 'O')
		{
			printf("Saisir la nnouvelle quantite\t");
			scanf("%d%*c", &a.quantite);
		}
		printf("Vous avez modifié l'article\n");
		*tabArt[pos] = a;
		return tabArt;
	}
	printf("vous n'avez pas modifié le client %s \n", a.designation);
	return tabArt;
}

void afficherClientCommande(Client client, LigneCommande commande)
{
	char nomEntier[150];
	sprintf(nomEntier, "%s. %s %s", client.civilite, client.nom, client.prenom);
	printf("┃%d\t   ┃%-40s┃%-21d┃\n", commande.idCommande, nomEntier, commande.quantite);
}

ListeCommande verifArtDansCommandes(Article *article, ListeCommande commandes, int *trouve, Client client)
{
	if (commandes == NULL)
		return commandes;
	if (commandes->v.article->idArticle == article->idArticle)
		afficherClientCommande(client, commandes->v);
	commandes->suiv = verifArtDansCommandes(article, commandes->suiv, trouve, client);
	return commandes;
}

void afficherArticleCommande(Article *article, Client tabClient[], int nbClient, int choixCommande)
{
	int trouve = 0;
	for (int i = 0; i < nbClient; i++)
	{
		if (choixCommande == 1)
		{
			if (tabClient[i].commandesEnAttente != NULL)
				verifArtDansCommandes(article, tabClient[i].commandesEnAttente, &trouve, tabClient[i]);
		}
		else
		{
			if (tabClient[i].commandesEnCours != NULL)
				verifArtDansCommandes(article, tabClient[i].commandesEnCours, &trouve, tabClient[i]);
		}
	}
}

void afficherConsultArticle(Article *article, Client tabClient[], int nbClient)
{
	system("clear");
	printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃\t\t\tConsultation Article\t\t\t\t  ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃ID: %-69d┃\n", article->idArticle);
	printf("┃Désignation: %-60s┃\n", article->designation);
	printf("┃Prix:  %-66.2f┃\n", article->prixunitaire);
	printf("┃Quantité en stock: %-54d┃\n", article->quantite);
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃\t\t\tCommandes En Attentes\t\t\t\t  ┃\n");
	printf("┣━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃idCommande┃Nom Client                              ┃Quantité Commandé    ┃\n");
	printf("┣━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━┫\n");
	afficherArticleCommande(article, tabClient, nbClient, 1);
	printf("┣━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃\t\t\tCommandes En Cours\t\t\t\t  ┃\n");
	printf("┣━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃idCommande┃Nom Client                              ┃Quantité Commandé    ┃\n");
	printf("┣━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━┫\n");
	afficherArticleCommande(article, tabClient, nbClient, 2);
	printf("┗━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void consulterArticle(Article *tabArt[], int nbArt, Client tabClient[], int nbClient)
{
	char rechdesig_art[50];
	int pos, trouve, i, choix = 0;
	printf("Rechercher un article par désignation: ");
	scanf("%s%*c", rechdesig_art);
	pos = rechercherDicoArticle(rechdesig_art, tabArt, nbArt, &trouve, -1);
	afficherConsultArticle(tabArt[pos], tabClient, nbClient);
	printf("Appuyer sur ← ou → pour naviguer\n");
	printf("Appuyer sur entrer pour sortir\n");
	while (choix != 10)
	{
		choix = getch();
		if (choix == 68)
		{
			pos = pos - 1;
		}
		else if (choix == 67)
		{
			pos = pos + 1;
		}
		if (pos==-1) {
			pos=nbClient;
		}
		if (pos==nbClient) {
			pos=0;
		}
		
		
		afficherConsultArticle(tabArt[pos], tabClient, nbClient);
		printf("Appuyer sur ← ou → pour naviguer\n");
		printf("Appuyer sur entrer pour sortir\n");
	}
}