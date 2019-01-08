#include "menu.h"
void yellow {
  printf("\033[1;33m");
}
void afficheMenuArticle(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tMenu Article\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Affichage la liste des article\t\t┃\n");
    printf("┃\t2.  Adjouter un article\t\t\t\t┃\n");
    printf("┃\t3.  Enlever un article\t\t\t\t┃\n");
    printf("┃\t4.  Modifier un article\t\t\t\t┃\n");
    printf("┃\t5.  Afficher les article en rupture\t\t┃\n");
    printf("┃\t10. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void afficheMenuClient(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tMenu Client\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Affichage la liste des client\t\t┃\n");
    printf("┃\t2.  Adjouter un client\t\t\t\t┃\n");
    printf("┃\t3.  Enlever un client\t\t\t\t┃\n");
    printf("┃\t4.  Modifier un client\t\t\t\t┃\n");
    printf("┃\t10. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void afficheChoixTriArticle(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\tAfficher Article\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Afficher par ID\t\t\t\t┃\n");
    printf("┃\t2.  Afficher par designation\t\t\t\t┃\n");
    printf("┃\t3.  Afficher par prix\t\t\t\t┃\n");
    printf("┃\t4.  Afficher par quantité\t\t\t\t┃\n");
    printf("┃\t10. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

void afficheChoixTriClient(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\t\t\t[0;33mAfficher Client\t\t\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Afficher par ID\t\t\t\t┃\n");
    printf("┃\t2.  Afficher par nom\t\t\t\t┃\n");
    printf("┃\t3.  Afficher par prénom\t\t\t\t┃\n");
    printf("┃\t4.  Afficher par address\t\t\t\t┃\n");
    printf("┃\t10. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}

int afficheMenuPrinciple(void)
{
    system("clear");
    printf("\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃\tGestion des Client et Article et Commande\t┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃\t1.  Article\t\t\t\t\t┃\n");
    printf("┃\t2.  Client\t\t\t\t\t┃\n");
    printf("┃\t3.  Commande\t\t\t\t\t┃\n");
    printf("┃\t4.  Reapprovisonnement\t\t\t\t┃\n");
    printf("┃\t10. Quitter\t\t\t\t\t┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

    return 10;
}

int choixMenu(void)
{
    int n;
    printf("\n Option choisie : ");
    scanf("%d%*c", &n);
    return n;
}

void menuChoixTriClient(Client tabClient[], int *nbClient)
{
    int choix;
    while (choix != 10)
    {
        afficheChoixTriClient();
        choix = choixMenu();
        system("clear");
        switch (choix)
        {
        case 1:
            triDicoClient(tabClient, *nbClient, 1);
            afficherTabClient(tabClient, *nbClient);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 10;
            break;

        case 2:
            triDicoClient(tabClient, *nbClient, 1);
            afficherTabClient(tabClient, *nbClient);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 10;
            break;

        case 3:
            triDicoClient(tabClient, *nbClient, 1);
            afficherTabClient(tabClient, *nbClient);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 10;
            break;

        case 4:
            triDicoClient(tabClient, *nbClient, 1);
            afficherTabClient(tabClient, *nbClient);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            choix = 10;
            break;

        case 10:
            break;

        default:
            printf("Mauvais saisi");
            break;
        }
    }
}

void menuClient(Client tabClient[], int *nbClient)
{
    int choix;
    afficheMenuClient();
    choix = choixMenu();
    if (choix == 10)
        return;
    switch (choix)
    {
    case 1:
        menuChoixTriClient(tabClient, nbClient);
        break;

    case 2:
        triDicoClient(tabClient, *nbClient, 0);
        *nbClient = adjouterClient(tabClient, *nbClient);
        printf("Appuyer sur une touche pour afficher les changement...\n");
        getchar();
        afficherTabClient(tabClient, *nbClient);
        printf("Appuyer sur une touche pour continuer...\n");
        getchar();
        break;

    case 3:
        triDicoClient(tabClient, *nbClient, 0);
        *nbClient = supprimeClient(tabClient, *nbClient);
        triDicoClient(tabClient, *nbClient, 1);
        printf("Appuyer sur une touche pour afficher les changement...\n");
        getchar();
        afficherTabClient(tabClient, *nbClient);
        printf("Appuyer sur une touche pour continuer...\n");
        getchar();
        break;

    case 10:
        break;

    default:
        printf("Mauvais saisi");
        break;
    }
    menuClient(tabClient, nbClient);
}

void menuArticle(Article *tabArt[], int *tailleArt)
{
    int choix;
    while (choix != 10)
    {
        afficheMenuArticle();
        choix = choixMenu();
        system("clear");
        switch (choix)
        {
        case 1:
            afficherTabArticle(tabArt, *tailleArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            break;

        case 3:
            triDicoArticle(tabArt, *tailleArt, 2);
            *tailleArt = adjouterArticle(tabArt, *tailleArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            break;

        case 4:
            triDicoArticle(tabArt, *tailleArt, 2);
            *tailleArt = supprimeArticle(tabArt, *tailleArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            break;

        case 5:
            triDicoArticle(tabArt, *tailleArt, 1);
            afficherTabArticleRupture(tabArt, *tailleArt);
            printf("Appuyer sur une touche pour continuer...\n");
            getchar();
            break;

        case 10:
            break;

        default:
            printf("Mauvais saisi");
            break;
        }
    }
}

void menuPrinciple(Article *tabArt[], int *tailleArt, Client tabClient[], int *nbClient)
{
    int choix;
    while (choix != 10)
    {
        afficheMenuPrinciple();
        choix = choixMenu();
        switch (choix)
        {
        case 1:
            menuArticle(tabArt, tailleArt);
            break;

        case 2:
            menuClient(tabClient, nbClient);
            break;

        case 10:
            break;

        default:
            break;
        }
    }
}
/*-------------------------------------------- Menu (v2) --------------------------------------------------------*/
