
#include <stdio.h>
#include <stdlib.h>
#include "mesFonctions.h"

int principal_displayMenu(){

    int choix;
    printf("\n");
    printf("\t1. Manipuler mot d'un alphabet\n");
    printf("\t2. Jouer avec les AEF\n");
    printf("\t3. Jouer avec les Expressions Régulières\n");
    printf("\t4. Quitter\n");
    printf("\n");
    printf("\tQu'est-ce que vous souhaitez faire ?\n");

    scanf("%d", &choix);

    return choix;
}

int alphabet_displayMenu(){

    int choix;

    printf("\t1. Appartient à l'alphabet\n");
    printf("\t2. Puissance d'un mot\n");
    printf("\t3. Vérifier si un mot est vide\n");
    printf("\t4. Concaténer deux mots\n");
    printf("\t5. Calculer le mirroir d'un mot\n");
    printf("\t6. Vérifier si une chaîne de caractère représente un mot fini\n");
    printf("\t7. Retour\n");
    printf("\n");
    printf("\tQu'est-ce que vous souhaitez faire ? :\n");
    scanf("%d", &choix);

    return choix;
    
}











