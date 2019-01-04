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
	printf("\t Nombre de client : %d \n",nbClient);
	printf("ID\tCivilité\tnom\t\tprenom \t\t adresse \n");
	printf("---------------------------------------------------------------------------------------------\n");
	for (i=0;i<nbClient;i++)
		printf("%d\t%s\t\t%s\t\t%s\t\t%s\n",tabClient[i].idClient,tabClient[i].civilite,tabClient[i].nom,tabClient[i].prenom,tabClient[i].adresse);
}

Client * chargeTabClient(Client *tabClient,int *nbClient){
	FILE *flot;
	int i=0,tMax=1;
	flot=fopen("clients.don","r");
	if(flot==NULL){
		printf("Probleme ouverture");
		fclose(flot);
		return NULL;
	}
	 tabClient=(Client *)malloc(sizeof(Client));
	if (tabClient==NULL){
		printf("Pb malloc\n");
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

void copierClient(Client tab[], int i, int j, Client R[]){
	int t=0;
	while(i<j){
		R[t]=tab[i];
		i=i+1;
		t=t+1;
	}
}

void fusionClient(Client  R[], int n, Client  S[], int m ,Client  t[]){
	int i=0, j=0, k=0;
	while(i<n && j<m){
		if ((strcmp(R[i].nom,S[j].nom))<0){
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

void triDicoClient(Client tab[], int n){
	Client *R,*S;
	if (n==1)
		return;
	R=(Client*)malloc((n/2)*sizeof(Client));
	S=(Client*)malloc((n-(n/2))*sizeof(Client));
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
