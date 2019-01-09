#include"client.h"

Client saisirClient(FILE *flot){
	Client c;
    fscanf(flot,"%d",&c.idClient);
    fscanf(flot,"%s",c.civilite);
    fscanf(flot,"%s",c.nom);
    fscanf(flot,"%s",c.prenom);
    fgets(c.adresse,50,flot);
    c.adresse[strlen(c.adresse)-2]='\0';


	return c;
}

void afficherTabClient(Client tabClient[],int nbClient){
	int i=0;
	printf("Liste des Clients\n");
	printf("━━━━━━━━┳━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("   ID\t┃Civilité  ┃Nom            ┃Prénom         ┃Adresse \n");
	printf("━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	for (i=0;i<nbClient;i++)
		printf("%d\t┃%-10s┃%-15s┃%-15s┃%s\n",tabClient[i].idClient,tabClient[i].civilite,tabClient[i].nom,tabClient[i].prenom,tabClient[i].adresse);
	printf("━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("Nombre de client : %d \n",nbClient);
}

Client * chargeTabClient(Client *tabClient,int *nbClient){
	FILE *flot;
	int i=0,tMax=1;
	flot=fopen("clients.don","r");
	if(flot==NULL){
		printf("Problème d'ouverture du fichier");
		fclose(flot);
		return NULL;
	}
	 tabClient=(Client *)malloc(sizeof(Client));
	if (tabClient==NULL){
		printf("Problème malloc\n");
		fclose(flot);
		return NULL;
	}
	while(!feof(flot)){
		if(i==tMax)
		{
			tabClient=(Client *)realloc(tabClient,tMax*sizeof(Client)+1*sizeof(Client));
			tMax=tMax+1;
		}
		tabClient[i]=saisirClient(flot);

		i=i+1;
	}
	*nbClient=i;
			// afficherTabClient(tabClient,i);
	fclose(flot);

	return tabClient;
}




/*-------------------------------------------- RecherheDicoClient --------------------------------------------------------*/

int testPosClient(Client R, Client S,int choix)
{
	
	switch (choix)
	{
		case 1:
			return R.idClient-S.idClient;
			break;
		case 2:
			return strcmp(R.nom,S.nom);
			break;
		case 3:
			return strcmp(R.prenom,S.prenom);
			break;
	
		default:
			break;
	}
}

void copierClient(Client tab[], int i, int j, Client R[]){
	int t=0;
	while(i<j){
		R[t]=tab[i];
		i=i+1;
		t=t+1;
	}
}

void fusionClient(Client  R[], int n, Client  S[], int m ,Client  t[],int trieID){
	int i=0, j=0, k=0, testOrdre;
	while(i<n && j<m){
		if(trieID)
			testOrdre=R[i].idClient-S[j].idClient;
		else
			testOrdre=strcmp(R[i].nom,S[j].nom);
		
		if (testOrdre<0){
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

void triDicoClient(Client tab[], int n,int trieID){
	Client *R,*S;
	if (n==1)
		return;
	R=(Client *)malloc((n/2)*sizeof(Client));
	S=(Client *)malloc((n-(n/2))*sizeof(Client));
	if (R==NULL || S==NULL){
		printf("Problème malloc");
		return;
	}
	copierClient(tab,0,n/2,R);
	copierClient(tab,n/2,n,S);
	triDicoClient(R,n/2,trieID);
	triDicoClient(S,n-n/2,trieID);
	fusionClient(R,n/2,S,n-(n/2),tab,trieID);
	free(R);
	free(S);
}

int rechercherDicoClient(char * rechnom,Client tab[], int nbc,int *trouve){
	int inf=0, sup=nbc-1, m;
	while (inf<=sup){
		m=(inf+sup)/2;
		if((strcmp(rechnom,tab[m].nom))==0){
			*trouve=1;
			return m;
		}
		if((strcmp(rechnom,tab[m].nom))<0)
			sup=m-1;
		else
			inf=m+1;
	}
	*trouve=0;
	return inf;
}

/*-------------------------------------------- SupprimerUnClient --------------------------------------------------------*/

int supprimeClient(Client * tabClient,int nb){
	char rechdesig_art[50];
	int pos,trouve,i;
	printf("Saisir le nom du client : \t");
	scanf("%s%*c",rechdesig_art);
	pos=rechercherDicoClient(rechdesig_art,tabClient,nb,&trouve);
	if (trouve==0){
		printf("Client non trouvé \n");
		return nb;
	}
	for (i=pos;i<nb;i++)
		tabClient[i]=tabClient[i+1];
	tabClient=(Client *)realloc(tabClient,nb*sizeof(Client)-1*sizeof(Client));
	nb=nb-1;
	printf("Client Supprimmé.\n");
	return nb;
}

/*-------------------------------------------- Ajouter Article -------------------------------------------------------*/
Client saisieClient(int nb){
	Client c;
	printf("Civilité de nouveau client: ");
	scanf("%s%*c",c.civilite);
	printf("Nom de nouveau client : ");
	scanf("%s%*c",c.nom);
	printf("Prénom de nouveau client: ");
	scanf("%s%*c",c.prenom);
	printf("Saisir l'adresse de nouveau client :");
	fgets(c.adresse,50,stdin);
	c.adresse[strlen(c.adresse)-1]='\0';
	c.idClient=nb+1;
	return c;

}

int adjouterClient(Client tabClient[], int nbClient)
{
	Client a;
	int trouve,pos;
	triDicoClient(tabClient,nbClient,1);
	a=saisieClient(tabClient[nbClient-1].idClient);
	triDicoClient(tabClient,nbClient,0);
	pos=rechercherDicoClient(a.nom,tabClient,nbClient,&trouve);
	if(trouve==1){
		printf("Erreur: Client déjà enregistré \n");
		return nbClient;
	}
	tabClient=(Client *)realloc(tabClient,nbClient*sizeof(Client)+1*sizeof(Client));
	tabClient[nbClient]=a;
	nbClient=nbClient+1;
	triDicoClient(tabClient,nbClient,2);
	printf("Ajout du client réussi.\n");
	return nbClient;
	

}
