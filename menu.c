#include"menu.h"

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