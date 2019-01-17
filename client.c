#include "client.h"

/*-------------------------------------------- Afficher le tableau des clients --------------------------------------------------------*/

void afficherTabClient(Client tabClient[], int nbClient)
{
	int i = 0;
	printf("Liste des Clients\n");
	printf("━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("   ID\t┃Civilité  ┃Nom            ┃Prénom         ┃Cdes En Attente┃Cdes En Cours┃Adresse \n");
	printf("━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	for (i = 0; i < nbClient; i++)
		printf("%d\t┃%-10s┃%-15s┃%-15s┃%-15d┃%-13d┃%s\n", tabClient[i].idClient, tabClient[i].civilite, tabClient[i].nom, tabClient[i].prenom, longueur(tabClient[i].commandesEnAttente),longueur(tabClient[i].commandesEnCours),tabClient[i].adresse);
	printf("━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("Nombre de client : %d \n", nbClient);
}

/*-------------------------------------------- Chargement du tableau de client --------------------------------------------------------*/

Client saisirClient(FILE *flot)
{
	Client c;
	fscanf(flot, "%d", &c.idClient);
	fscanf(flot, "%s", c.civilite);
	fscanf(flot, "%s", c.nom);
	fscanf(flot, "%s ", c.prenom);
	fgets(c.adresse, 50, flot);
	c.adresse[strlen(c.adresse) - 1] = '\0';
	c.commandesEnAttente = NULL;
	c.commandesEnCours = NULL;
	return c;
}

Client *chargeTabClient(Client *tabClient, int *nbClient)
{
	FILE *flot;
	int i = 0, tMax = 1;
	flot = fopen("clients.don", "r");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		fclose(flot);
		return NULL;
	}
	tabClient = (Client *)malloc(sizeof(Client));
	if (tabClient == NULL)
	{
		printf("Problème malloc\n");
		fclose(flot);
		return NULL;
	}
	while (!feof(flot))
	{
		if (i == tMax)
		{
			tabClient = (Client *)realloc(tabClient, tMax * sizeof(Client) + 1 * sizeof(Client));
			tMax = tMax + 1;
		}
		tabClient[i] = saisirClient(flot);

		i = i + 1;
	}
	*nbClient = i;
	// afficherTabClient(tabClient,i);
	fclose(flot);

	return tabClient;
}

/*-------------------------------------------- Tri dico --------------------------------------------------------*/

int testPosClient(Client R, Client S, int choix)
{

	switch (choix)
	{
	case 1:
		return R.idClient - S.idClient;
		break;
	case 2:
		return strcmp(R.nom, S.nom);
		break;
	case 3:
		return strcmp(R.prenom, S.prenom);
		break;

	default:
		break;
	}
}

void copierClient(Client tab[], int i, int j, Client R[])
{
	int t = 0;
	while (i < j)
	{
		R[t] = tab[i];
		i = i + 1;
		t = t + 1;
	}
}

void fusionClient(Client R[], int n, Client S[], int m, Client t[], int trieID)
{
	int i = 0, j = 0, k = 0, testOrdre;
	while (i < n && j < m)
	{
		if (testPosClient(R[i], S[j], trieID) < 0)
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

void triDicoClient(Client tab[], int n, int trieID)
{
	Client *R, *S;
	if (n == 1)
		return;
	R = (Client *)malloc((n / 2) * sizeof(Client));
	S = (Client *)malloc((n - (n / 2)) * sizeof(Client));
	if (R == NULL || S == NULL)
	{
		printf("Problème malloc");
		return;
	}
	copierClient(tab, 0, n / 2, R);
	copierClient(tab, n / 2, n, S);
	triDicoClient(R, n / 2, trieID);
	triDicoClient(S, n - n / 2, trieID);
	fusionClient(R, n / 2, S, n - (n / 2), tab, trieID);
	free(R);
	free(S);
}

/*-------------------------------------------- Recherche dico --------------------------------------------------------*/

int rechercherDicoClient(char *rechnom, Client tab[], int nbc, int *trouve, int rechID)
{
	if(rechID==-1)
	{
		triDicoClient(tab,nbc,2);
	}
	else
	{
		triDicoClient(tab,nbc,1);
	}
	int inf = 0, sup = nbc - 1, m;
	while (inf <= sup)
	{
		m = (inf + sup) / 2;
		if (rechID == -1)
		{
			if ((strcmp(rechnom, tab[m].nom)) == 0)
			{
				*trouve = 1;
				return m;
			}
			if ((strcmp(rechnom, tab[m].nom)) < 0)
				sup = m - 1;
			else
				inf = m + 1;
		}
		else
		{
			if (rechID == tab[m].idClient)
			{
				*trouve = 1;
				return m;
			}
			if (rechID < tab[m].idClient)
				sup = m - 1;
			else
				inf = m + 1;
		}
	}
	*trouve = 0;
	return inf;
}

/*-------------------------------------------- SupprimerUnClient --------------------------------------------------------*/

int supprimeClient(Client *tabClient, int nb)
{
	char rechdesig_art[50];
	int pos, trouve, i;
	printf("Saisir le nom du client : \t");
	scanf("%s%*c", rechdesig_art);
	pos = rechercherDicoClient(rechdesig_art, tabClient, nb, &trouve, -1);
	if (trouve == 0)
	{
		printf("Client non trouvé \n");
		return nb;
	}
	for (i = pos; i < nb; i++)
		tabClient[i] = tabClient[i + 1];
	tabClient = (Client *)realloc(tabClient, nb * sizeof(Client) - 1 * sizeof(Client));
	nb = nb - 1;
	printf("Client Supprimmé.\n");
	return nb;
}

/*-------------------------------------------- Ajouter un client -------------------------------------------------------*/
Client saisieClient(int nb)
{
	Client c;
	printf("Civilité de nouveau client (Mr ou Mme): ");
	scanf("%s%*c", c.civilite);
	while(strcmp(c.civilite,"Mr")!=0 && strcmp(c.civilite,"Mme")!=0 ){
		printf("Civilité de nouveau client (Mr ou Mme): ");
		scanf("%s%*c", c.civilite);
	}
	printf("Nom de nouveau client : ");
	scanf("%s%*c", c.nom);
	printf("Prénom de nouveau client: ");
	scanf("%s%*c", c.prenom);
	printf("Saisir l'adresse de nouveau client :");
	fgets(c.adresse, 50, stdin);
	c.adresse[strlen(c.adresse) - 1] = '\0';
	c.idClient = nb + 1;
	return c;
}

Client * ajouterClient(Client tabClient[], int *nbClient)
{
	Client a;
	int trouve, pos;
	triDicoClient(tabClient, *nbClient, 1);
	a = saisieClient(tabClient[*nbClient - 1].idClient);
	triDicoClient(tabClient, *nbClient, 2);
	pos = rechercherDicoClient(a.nom, tabClient, *nbClient, &trouve, -1);
	if (trouve == 1)
	{
		printf("Erreur: Client déjà enregistré \n");
		return tabClient;
	}
	tabClient = (Client *)realloc(tabClient, *nbClient * sizeof(Client) + 1 * sizeof(Client));
	tabClient[*nbClient] = a;
	*nbClient = *nbClient + 1;
	triDicoClient(tabClient, *nbClient, 2);
	printf("Ajout du client réussi.\n");
	return tabClient;
}

void afficherConsultClient(Client client)
{
	system("clear");
	printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃\t\t\tConsultation Client\t\t\t\t  ┃\n");
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃ID:      %d\t\t\t\t\t\t\t\t  ┃\n",client.idClient);
	printf("┃Nom:     %-64s┃\n",client.nom);
	printf("┃Prenom:  %-64s┃\n",client.prenom);
	printf("┃Address: %-64s┃\n",client.adresse);
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃\t\t\tCommandes En Attentes\t\t\t\t  ┃\n");
	printf("┣━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━┳━━━━━━━━━━━━┫\n");
	printf("┃idCommande┃Désignation Article          ┃Prix Unit.┃Quantité┃Prix Total  ┃\n");
	printf("┣━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━╋━━━━━━━━━━━━┫\n");
	afficherCommande(client.commandesEnAttente);
	printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	printf("┃\t\t\tCommandes En Cours\t\t\t\t  ┃\n");
	printf("┣━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━┳━━━━━━━━━━━━┫\n");
	printf("┃idCommande┃Désignation Article          ┃Prix Unit.┃Quantité┃Prix Total  ┃\n");
	printf("┣━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━╋━━━━━━━━━━━━┫\n");
	afficherCommande(client.commandesEnCours);
	printf("┗━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━┻━━━━━━━━━━━━┛\n");
}

void consulterClient(Client tabClient[],int nbClient)
{
	char rechdesig_art[50];
	int pos, trouve, i,choix;
	printf("Saisir le nom du client : \t");
	scanf("%s%*c", rechdesig_art);
	triDicoClient(tabClient,nbClient,2);
	pos = rechercherDicoClient(rechdesig_art, tabClient, nbClient, &trouve, -1);
	afficherConsultClient(tabClient[pos]);
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
		if(pos==-1)
		{
			pos=nbClient-1;
		}
		if(pos==nbClient)
		{
			pos=0;
		}
		afficherConsultClient(tabClient[pos]);
		printf("Appuyer sur ← ou → pour naviguer\n");
		printf("Appuyer sur entrer pour sortir\n");
	}
}



/*-------------------------------------------- Sauvegarder un client -------------------------------------------------------*/

void sauvegardeClient(Client c,FILE * flot){
	fprintf(flot,"%d %s %s %s %s\n",c.idClient,c.civilite,c.nom,c.prenom,c.adresse);
}

void sauvegardeTabClient(Client tab[],int tmax){
	int i;
	FILE *flot;
	flot = fopen("clientss.don", "w");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		return;
	}
	for(i=0;i<tmax;i++){
		sauvegardeClient(tab[i],flot);
	}
	printf("sauvegarde client effectuée");
	fclose(flot);
}

/*-------------------------------------------- Modification client -------------------------------------------------------*/

Client * modification(Client *tabClient,int taille)
{
	Client c;
	int id,pos,trouve;
	char choix;
	printf("Veuillez entrer le nom d'un client :");
	fgets(c.nom,10,stdin);
	c.nom[strlen(c.nom)-1]='\0';
	pos=rechercherDicoClient(c.nom,tabClient,taille,&trouve,-1);
	while(trouve==0)
	{
		printf("Client non enregistré\n");
		return tabClient ;
	}
	printf("\nVoici le client %s %s :\n",c.nom,c.prenom);
	afficherConsultClient(tabClient[pos]);
	printf("\nConfirmez vous que vous souhaitez modifier ce client?(O/N)");
	scanf("%c%*c",&choix);
	if(choix=='O'||choix=='o')
	{
		c=tabClient[pos];
		printf("Voulez vous modifier la civilité ? (O/N)\n");
		scanf("%c%*c",&choix);
		if (choix=='o' || choix=='O')
		{
			printf("Saisir la nouvelle civilité\t");
			scanf("%s%*c",c.civilite);
			while(strcmp(c.civilite,"Mr")!=0 && strcmp(c.civilite,"mr")!=0 && strcmp(c.civilite,"Mme")!=0 && strcmp(c.civilite,"mme")!=0)
			{
				printf("Civilité inconnue, veuillez entrer de nouveau la civilité (Mr ou Mme) :\t");
				scanf("%s%*c",c.civilite);
			}
		}
		printf("Voulez vous modifier le nom ? (O/N)\n");
		scanf("%c%*c",&choix);
		if (choix=='o' || choix=='O')
		{
			printf("Saisir le nouveau nom\t");
			fgets(c.nom,10,stdin);
			c.nom[strlen(c.nom)-1]='\0';
		}
		printf("Voulez vous modifier le prénom ? (O/N)\n");
		scanf("%c%*c",&choix);
		if (choix=='o' || choix=='O')
		{
			printf("Saisir le nouveau prénom\t");
			fgets(c.prenom,10,stdin);
			c.prenom[strlen(c.prenom)-1]='\0';
		}
		printf("Voulez vous modifier l'adresse ? (O/N)\n");
		scanf("%c%*c",&choix);
		if (choix=='o' || choix=='O')
		{
			printf("Saisir l'adresse'\t");
			fgets(c.adresse,70,stdin);
			c.adresse[strlen(c.adresse)-1]='\0';
		}
		tabClient[pos]=c;
		return tabClient;
	}
	printf("vous n'avez pas modifié le client %s %s\n",c.nom,c.prenom);		
	return tabClient;
}