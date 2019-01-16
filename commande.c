#include "commande.h"
#include <time.h>

void saisirCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    char nomClient[50];
    Article *commandeArt;
    LigneCommande commandeEnAttente,commandeEnCours;
    int idArt, quantite, i, posArt, posClient, trouve, reste;
    srand(time(NULL)); 
    system("clear");
    printf("Entrer le nom du client:");
    scanf("%s", nomClient);
    triDicoClient(tabClient, nbClient, 2);
    posClient = rechercherDicoClient(nomClient, tabClient, nbClient, &trouve, -1);
    if (!trouve)
    {
        printf("Client non trouvée. Abandon.\n");
        return;
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
    reste = commandeArt->quantite - quantite;
    if (reste < 0) //stock est insuffisante
    {
        printf("Insuffisante de stock pour cette commande.\n");
        // Traitement des commande en cours
        if(commandeArt->quantite!=0)
        {
        commandeEnCours.quantite = commandeArt->quantite;
        commandeEnCours.article = commandeArt;
        commandeEnCours.idCommande = random()%1000;
        commandeEnCours.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandesEnCours=ajouterCommande(tabClient[posClient].commandesEnCours, commandeEnCours);
        printf("Mis en commande de l'article (%d en stock)\n", quantite - reste);
        printf("La commande en cours port la numéro %d\n", commandeEnCours.idCommande);
        }
        //Traitement des commande en attente
        commandeArt->quantite = 0;
        reste = reste * -1;
        commandeEnAttente.quantite = reste;
        commandeEnAttente.article = commandeArt;
        commandeEnAttente.idCommande = random()%1000;
        commandeEnAttente.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandesEnAttente = ajouterCommande(tabClient[posClient].commandesEnAttente, commandeEnAttente);

        printf("Mis en attente %d produits\n", reste);
        printf("La commande en attente porte la commande numéro %d\n", commandeEnAttente.idCommande);
    }
    else if (reste >= 0)
    {
        commandeArt->quantite = reste;
        commandeEnCours.quantite = quantite;
        commandeEnCours.article = commandeArt;
        commandeEnCours.idCommande = random()%1000;
        commandeEnCours.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandesEnCours=ajouterCommande(tabClient[posClient].commandesEnCours, commandeEnCours);
        printf("Commande Client réussi.\n%d de %s commandé, il sera pret dans les 2 jours\n", quantite, commandeArt->designation);
    }
}

void saisirLigneCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt, FILE *flot,int ligne)
{
    char nomClient[50];
    Article *commandeArt;
    LigneCommande commandeEnAttente,commandeEnCours;
    int idArt, quantite, i, posArt, posClient, trouve, reste;

    fscanf(flot, "%s", nomClient);

    fscanf(flot, "%d", &idArt);
    fscanf(flot, "%d", &quantite);
    triDicoClient(tabClient, nbClient, 2);
    posClient = rechercherDicoClient(nomClient, tabClient, nbClient, &trouve, -1);
    if (!trouve)
    {
        printf("Ligne %d: Client %s introuvable. Ligne Ignore.\n",ligne,nomClient);
        return;
    }
    trouve = 0;
    posArt = rechercherDicoArticle('\0', tabArt, nbArt, &trouve, idArt);
    if (!trouve)
    {
        printf("Ligne %d: Article de ID %d introuvable. Ligne Ignore.\n",ligne,idArt);
        return;
    }
    commandeArt = tabArt[posArt];
    reste = commandeArt->quantite - quantite;
    if (reste < 0)
    {
        printf("Ligne %d: Insuffisante de stock pour cette commande. ",ligne);
        // Traitement des commande en cours
        if(commandeArt->quantite!=0)
        {
        commandeEnCours.quantite = commandeArt->quantite;
        commandeEnCours.article = commandeArt;
        commandeEnCours.idCommande = random()%1000;
        commandeEnCours.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandesEnCours=ajouterCommande(tabClient[posClient].commandesEnCours, commandeEnCours);
        printf("Mis en commande %d produit. ", quantite - reste);
        }
        commandeArt->quantite = 0;
        reste = reste * -1;
        commandeEnAttente.quantite = reste;
        commandeEnAttente.article = commandeArt;
        commandeEnAttente.idCommande = random()%1000;
        commandeEnAttente.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandesEnAttente = ajouterCommande(tabClient[posClient].commandesEnAttente, commandeEnAttente);

        printf("Mis en attente %d produits\n", reste);
    }
    else if (reste >= 0)
    {
        commandeArt->quantite = reste;
        commandeEnCours.quantite = quantite;
        commandeEnCours.article = commandeArt;
        commandeEnCours.idCommande = random()%1000;
        commandeEnCours.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandesEnCours=ajouterCommande(tabClient[posClient].commandesEnCours, commandeEnCours);
    }
}

void lireFichierCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    FILE *flot;
    int i=1;
    system("clear");
    printf("Chargement de fichier en cours...\n");
    flot = fopen("commandes.don", "r");
    if (flot == NULL)
    {
        printf("Problème d'ouverture du fichier");
        return;
    }
    printf("Traitement des lignes...\n");
    while (!feof(flot))
    {
        saisirLigneCommande(tabClient, nbClient, tabArt, nbArt, flot,i);
        i=i+1;
    }
    printf("Chargement effectuée\n");
    fclose(flot);
}




//-------------------Reappro------------------------


Ensemble verifCommandeEnAttente(Ensemble commandes,Article * commandeArt,int *quantite,Client tabClient[],int pos)
{
    LigneCommande enCours;
    if(*quantite==0)
    {
        return commandes;
    }
   if (commandes == NULL)
		return commandes;
    if(commandes->v.article->idarticle==commandeArt->idarticle)
    {
        if(commandes->v.quantite<*quantite)
        {
            *quantite=*quantite-commandes->v.quantite;
            printf("La commande de numero %d de client %d va passer en cours.\n",commandes->v.idCommande,commandes->v.idClient);
            tabClient[pos].commandesEnCours=ajouterCommande(tabClient[pos].commandesEnCours,commandes->v);
            commandes=supprimerEnTete(commandes);
        }
        else
        {
            enCours=commandes->v;
            enCours.quantite=*quantite;
            printf("La commande de numero %d de client %d va passer en cours partiellement (%d produits retirés).\n",commandes->v.idCommande,commandes->v.idClient,*quantite);
           tabClient[pos].commandesEnCours=ajouterCommande(tabClient[pos].commandesEnCours,enCours);
            commandes->v.quantite=commandes->v.quantite-*quantite;
            *quantite=0;
        }
        
        
    }
    if (commandes == NULL)
		return commandes;
	commandes->suiv = verifCommandeEnAttente(commandes->suiv, commandeArt,quantite,tabClient,pos);
	return commandes;
}

void verifTabClientCommande(Client tabClient[], int nbClient, Article *commandeArt,int *quantite)
{
    for(int i = 0; i < nbClient; i++)
    {
        if(!commandeEstVide(tabClient[i].commandesEnAttente))
        {
            tabClient[i].commandesEnAttente=verifCommandeEnAttente(tabClient[i].commandesEnAttente,commandeArt,quantite,tabClient,i);
            afficherCommande(tabClient[i].commandesEnCours);
        }
    }
    
}

void saisirReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    char nomClient[50];
    Article *commandeArt;
    LigneCommande commandeEnAttente;
    int idArt, quantite, i, posArt, posClient, trouve=0, reste;
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
    verifTabClientCommande(tabClient,nbClient,commandeArt,&quantite);
    commandeArt->quantite=commandeArt->quantite+quantite;
    printf("%d produits va etre entreé en stock\n",quantite);
    
}

// void saisirLigneReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt, FILE *flot,int ligne)
// {
//     char nomClient[50];
//     Article *commandeArt;
//     LigneCommande commandeEnAttente;
//     int idArt, quantite, i, posArt, posClient, trouve, reste;
//     fscanf(flot, "%d", &idArt);
//     fscanf(flot, "%d", &quantite);
//     triDicoClient(tabClient, nbClient, 2);
//     posClient = rechercherDicoClient(nomClient, tabClient, nbClient, &trouve, -1);
//     if (!trouve)
//     {
//         printf("%d: Client %s introuvable. Ligne Ignore.\n",ligne,nomClient);
//         return;
//     }
//     trouve = 0;
//     posArt = rechercherDicoArticle('\0', tabArt, nbArt, &trouve, idArt);
//     if (!trouve)
//     {
//         printf("%d: Article de ID %d introuvable. Ligne Ignore.\n",ligne,idArt);
//         return;
//     }
//     commandeArt = tabArt[posArt];
//     reste = commandeArt->quantite - quantite;
//     if (reste < 0)
//     {
//         commandeArt->quantite = 0;
//         reste = reste * -1;
//         commandeEnAttente.quantite = reste;
//         commandeEnAttente.article = commandeArt;
//         commandeEnAttente.idCommande = random() / 100;
//         commandeEnAttente.idClient = tabClient[posClient].idClient;
//         tabClient[posClient].commandes = ajouterCommande(tabClient[posClient].commandes, commandeEnAttente);
//         printf("Mis en attente pour l'article %s le reste de la commande(%d en attente)\n", commandeArt->designation, reste);
//     }
//     else if (reste >= 0)
//     {
//         commandeArt->quantite = reste;
//     }
// }

// void lireFichierReappro(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
// {
//     FILE *flot;
//     int i=1;
//     flot = fopen("commandes.don", "r");
//     if (flot == NULL)
//     {
//         printf("Problème d'ouverture du fichier");
//         return;
//     }
//     while (!feof(flot))
//     {
//         saisirLigneCommande(tabClient, nbClient, tabArt, nbArt, flot,i);
//         i=i+1;
//     }
//     printf("Chargement effectuée\n");
//     fclose(flot);
// }