Client saisirClient(FILE *flot){
	Client c;
    fscanf(flot,"%d",&c.idClient);
    fscanf(flot,"%s",c.civilite);
    fscanf(flot,"%s",c.nom);
    fscanf(flot,"%s",c.prenom);
    fgets(c.adresse,50,flot);
    c.adresse[strlen(c.adresse)-1]='\0';
	return c;
}

Client * chargeTabClient(int * tmax){
	FILE *flot;
	int i;
	Client * tab;
	flot=fopen("Client.txt","r");
	if(flot==NULL){
		printf("Probleme ouverture");
		fclose(flot);
		return NULL;
	}
	fscanf(flot,"%d",tmax);
	tab=(Client *)malloc((*tmax)*sizeof(Client));
	if (tab==NULL){
		printf("Pb malloc\n");
		fclose(flot);
		return NULL;
	}
	for(i=0;i<*tmax;i++)
		tab[i]=saisirClient(flot);
	fclose(flot);
	return tab;
}

void afficherTabClient(Client tab[],int nbclient){
	int i;
	printf("\t Nombre de client : %d \n",nbclient);
	printf("idClient civilite nom prenom \t\t adresse \n");
	printf("---------------------------------------------------------------------------------------------\n");
	for (i=0;i<nbclient;i++)
		printf("%d \t %s %s %s \t %s \n",tab[i].idClient,tab[i].civilite,tab[i].nom,tab[i].prenom,tab[i].adresse);
}