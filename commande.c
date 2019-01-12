#include "commande.h"

void saisirCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    char nomClient[50];
    Article *commandeArt;
    LigneCommande commandeEnAttente;
    int idArt, quantite, i, posArt, posClient, trouve, reste;
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
    if (reste < 0)
    {
        commandeArt->quantite = 0;
        reste = reste * -1;
        commandeEnAttente.quantite = reste;
        commandeEnAttente.article = commandeArt;
        commandeEnAttente.idCommande = random();
        commandeEnAttente.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandes = ajouterCommande(tabClient[posClient].commandes, commandeEnAttente);
        printf("Insuffisante de stock pour ce article.\n");
        printf("Vidé le stock de l'article (%d en stock)\n", quantite - reste);
        printf("Mis en attente le reste (%d en attente)\n", reste);
        printf("Il porte la commande numéro %d\n", commandeEnAttente.idCommande);
    }
    else if (reste >= 0)
    {
        commandeArt->quantite = reste;
        printf("Commande Client réussi.\n%d de %s commandé, il sera pret dans les 2 jours\n", quantite, commandeArt->designation);
    }
}

void saisirLigneCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt, FILE *flot)
{
    char nomClient[50];
    Article *commandeArt;
    LigneCommande commandeEnAttente;
    int idArt, quantite, i, posArt, posClient, trouve, reste;

    fscanf(flot, "%s", nomClient);

    fscanf(flot, "%d", &idArt);
    fscanf(flot, "%d", &quantite);
    triDicoClient(tabClient, nbClient, 2);
    posClient = rechercherDicoClient(nomClient, tabClient, nbClient, &trouve, -1);
    if (!trouve)
    {
        printf("Client %s introuvable. Ligne Ignore.\n",nomClient);
        return;
    }
    trouve = 0;
    posArt = rechercherDicoArticle('\0', tabArt, nbArt, &trouve, idArt);
    if (!trouve)
    {
        printf("Article de ID %d introuvable. Ligne Ignore.\n",idArt);
        return;
    }
    commandeArt = tabArt[posArt];
    reste = commandeArt->quantite - quantite;
    if (reste < 0)
    {
        commandeArt->quantite = 0;
        reste = reste * -1;
        commandeEnAttente.quantite = reste;
        commandeEnAttente.article = commandeArt;
        commandeEnAttente.idCommande = random() / 100;
        commandeEnAttente.idClient = tabClient[posClient].idClient;
        tabClient[posClient].commandes = ajouterCommande(tabClient[posClient].commandes, commandeEnAttente);
        printf("Mis en attente pour l'article %s le reste de la commande(%d en attente)\n", commandeArt->designation, reste);
    }
    else if (reste >= 0)
    {
        commandeArt->quantite = reste;
    }
}

void lireFichierCommande(Client tabClient[], int nbClient, Article *tabArt[], int nbArt)
{
    FILE *flot;
    int i;
    flot = fopen("commandes.don", "r");
    if (flot == NULL)
    {
        printf("Problème d'ouverture du fichier");
        return;
    }
    while (!feof(flot))
    {
        saisirLigneCommande(tabClient, nbClient, tabArt, nbArt, flot);
    }
    printf("Chargement effectuée\n");
    fclose(flot);
}