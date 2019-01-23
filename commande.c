#include "commande.h"
#include <time.h>

void calculCommande(Client tabClient[], int posClient, Article *commandeArt, int quantite, int idCommande)
{
    LigneCommande commandeEnAttente, commandeEnCours;
    int reste = commandeArt->quantite - quantite;
    if (reste < 0) //stock est insuffisante pour la commande
    {

        if (commandeArt->quantite > 0) // Traitement des commande en cours
        {
            //La commande va etre séparé en 2 parties, un partie pour vider le stock donc en cours, et le reste qui va etre en attente
            commandeEnCours.quantite = commandeArt->quantite;
            commandeEnCours.article = commandeArt;
            commandeEnCours.idCommande = random() % 1000;
            commandeEnCours.idClient = tabClient[posClient].idClient;
            tabClient[posClient].commandesEnCours = ajouterCommande(tabClient[posClient].commandesEnCours, commandeEnCours);
        }
        // Creation de commande en attente
        commandeArt->quantite = 0;
        reste = abs(reste);
        commandeEnAttente.quantite = reste;
        commandeEnAttente.article = commandeArt;
        if (idCommande == 0) //si idCommande n'est pas fourni (Cas de la creation de commande client dans le program)
            commandeEnAttente.idCommande = random() % 1000;
        else
            commandeEnAttente.idCommande = idCommande;
        commandeEnAttente.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandesEnAttente = ajouterCommande(tabClient[posClient].commandesEnAttente, commandeEnAttente);
    }
    else if (reste >= 0) //stock est suffisante pour la commande
    {
        //Creation d'un commande en cours
        commandeArt->quantite = reste;
        commandeEnCours.quantite = quantite;
        commandeEnCours.article = commandeArt;
        commandeEnCours.idCommande = random() % 1000;
        commandeEnCours.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandesEnCours = ajouterCommande(tabClient[posClient].commandesEnCours, commandeEnCours);
    }
}

Client * saisirCommande(Client tabClient[], int *nbClient, Article *tabArt[], int nbArt)
{
    char nomClient[50];
    Article *commandeArt;
    int idArt, quantite, i, posArt, posClient, trouve, reste;
    srand(time(NULL));
    system("clear");
    printf("Entrer le nom du client:");
    scanf("%s", nomClient);
    triDicoClient(tabClient, *nbClient, 2);
    posClient = rechercherDicoClient(nomClient, tabClient, *nbClient, &trouve, -1);
    if (!trouve)
    {
        printf("Client non trouvée.Créeons ce client.\n");
        tabClient=ajouterClient(tabClient,nbClient);
        posClient=*nbClient-1;
    }
    trouve = 0;
    while (!trouve)
    {
        printf("Entrer l'identifiant de l'article:");
        scanf("%d", &idArt);
        posArt = rechercherDicoArticle('\0', tabArt, nbArt, &trouve, idArt);
        if (!trouve)
            printf("Article non trouvée. Retaper;\n");
    }
    commandeArt = tabArt[posArt];
    printf("Entrer la quantité de l'article demandée:");
    scanf("%d", &quantite);
    printf("Calcul de la réalisation des commandes..."),
    calculCommande(tabClient, posClient, commandeArt, quantite, 0);
    printf("Réussi\n");
    printf("Commande entreé avec succès...");
    return tabClient;
}

//-------------------Reappro------------------------

ListeCommande verifCommandeEnAttente(ListeCommande commandes, Article *commandeArt, int *quantite, Client tabClient[], int pos)
{
    LigneCommande enCours;
    if (*quantite == 0)
    {
        return commandes;
    }
    if (commandes == NULL)
        return commandes;
    if (commandes->v.article->idArticle == commandeArt->idArticle)
    {
        if (commandes->v.quantite < *quantite)
        {
            *quantite = *quantite - commandes->v.quantite;
            tabClient[pos].commandesEnCours = ajouterCommande(tabClient[pos].commandesEnCours, commandes->v);
            commandes = supprimerEnTete(commandes);
        }
        else
        {
            enCours = commandes->v;
            enCours.quantite = *quantite;
            tabClient[pos].commandesEnCours = ajouterCommande(tabClient[pos].commandesEnCours, enCours);
            commandes->v.quantite = commandes->v.quantite - *quantite;
            *quantite = 0;
        }
    }
    if (commandes == NULL)
        return commandes;
    commandes->suiv = verifCommandeEnAttente(commandes->suiv, commandeArt, quantite, tabClient, pos);
    return commandes;
}

void verifTabClientCommande(Client tabClient[], int nbClient, Article *commandeArt, int *quantite)
{
    for (int i = 0; i < nbClient; i++)
    {
        if (!commandeEstVide(tabClient[i].commandesEnAttente))
        {
            tabClient[i].commandesEnAttente = verifCommandeEnAttente(tabClient[i].commandesEnAttente, commandeArt, quantite, tabClient, i);
        }
    }
}

void saisirReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    Article *commandeArt;
    int idArt, quantite, i, posArt, posClient, trouve = 0, reste;
    system("clear");
    while (!trouve)
    {
        printf("Entrer l'identifiant de l'article:");
        scanf("%d", &idArt);
        posArt = rechercherDicoArticle('\0', tabArt, nbArt, &trouve, idArt);
        if (!trouve)
            printf("Article non trouvée. Retaper;\n");
    }
    commandeArt = tabArt[posArt];
    printf("Entrer la quantité de l'article livrés:");
    scanf("%d", &quantite);
    printf("Véification des commandes en attente...\n");
    verifTabClientCommande(tabClient, nbClient, commandeArt, &quantite);
    commandeArt->quantite = commandeArt->quantite + quantite;
}

//------------
LigneCommande lireLigneCommande(FILE *flot, Article *tabArt[], int nbArt)
{
    LigneCommande v;
    Article *art;
    int pos, trouve, idArt;
    fscanf(flot, "%d%d%d%d", &v.idCommande, &idArt, &v.idClient, &v.quantite);
    pos = rechercherDicoArticle('\0', tabArt, nbArt, &trouve, idArt);
    if (!trouve) //Article non trouvee, passer au prochain lignecommande
        v.article = NULL;
    else
        v.article = tabArt[pos];
    return v;
}

void remplirTabLigneCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    FILE *flot;
    LigneCommande commande;
    int trouve, pos;
    flot = fopen(nomFichCommande, "r");
    if (flot == NULL)
    {
        printf("Problème d'ouverture du fichier");
        return;
    }

    while (!feof(flot))
    {
        commande = lireLigneCommande(flot, tabArt, nbArt);

        pos = rechercherDicoClient('\0', tabClient, nbClient, &trouve, commande.idClient);
        if (!trouve || commande.article == NULL) //Client non trouvee ou article non trouvee, passer au prochain lignecommande
        {
            commande = lireLigneCommande(flot, tabArt, nbArt);
            continue;
        }

        calculCommande(tabClient, pos, commande.article, commande.quantite, commande.idCommande);
    }
}

void saisirLigneReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt, FILE *flot)
{
    Article *commandeArt;
    int idArt, quantite, i, posArt, posClient, trouve = 0, reste;
    fscanf(flot,"%d", &idArt);
    posArt = rechercherDicoArticle('\0', tabArt, nbArt, &trouve, idArt);
    if (!trouve)
        return;
    commandeArt = tabArt[posArt];
    fscanf(flot,"%d", &quantite);
    verifTabClientCommande(tabClient, nbClient, commandeArt, &quantite);
    commandeArt->quantite = commandeArt->quantite + quantite;
}

void lireFichierReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    FILE *flot;
    int i = 1;
    system("clear");
    flot = fopen(nomFichLivraison, "r");
    if (flot == NULL)
    {
        printf("Problème d'ouverture du fichier");
        return;
    }
    while (!feof(flot))
    {
        saisirLigneReappro(tabClient,nbClient,tabArt,nbArt,flot);
        i = i + 1;
    }
    printf("Chargement effectuée\n");
    fclose(flot);
}

void supprimerCommandeEnAttente(Client tabClient[], int nbClient)
{
    int idCommande;
    printf("Veuillez entrer l'identifiant de la commande:\n");
    scanf("%d",&idCommande);
    for(int i=0;i<nbClient;i++)
    {
        supprimerCommande(tabClient[i].commandesEnAttente,idCommande);
    }
    printf("Commande Supprimée si il existe...\n");
    


}

ListeCommande sauvegardeCommande(ListeCommande e,FILE *flot)
{
	if (e == NULL)
	{
		return e;
	}	
	fprintf(flot,"%d %d %d %d\n", e->v.idCommande, e->v.article->idArticle, e->v.idClient,e->v.quantite);
	e->suiv=sauvegardeCommande(e->suiv,flot);
	return e;
}

void sauvegardeListeCommandes(Client tabClient[],int nbClient){
	int i;
	FILE *flot;
	flot = fopen(nomFichCommande, "w");
	if (flot == NULL)
	{
		printf("Problème d'ouverture du fichier");
		return;
	}
	for(i = 0; i < nbClient; i++)
	{
		sauvegardeCommande(tabClient[i].commandesEnAttente,flot);
	}
	printf("sauvegarde ligne commande effectuée");
	fclose(flot);
}