#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
    Article *taba[100];
    int nba;
    nba = remplirTabArticle(taba, 100);
    menuPrinciple(taba,nba);
    printf("Il marche!\n");
    return 0;
}