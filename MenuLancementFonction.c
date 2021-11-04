#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#include "mesFonctions.h"

void launchFunction(int choix){
    system("clear");
    switch(choix){
        case 1:
            printf("\tVous avez choisi Manipuler mot d'un alphabet\n");
            printf("\n");
            launchAlphabetFunction(alphabet_displayMenu());
        break;
        case 4:
            printf("\tAu revoir et à bientôt sur AutomaTHOR !\n");
            return;
        break;
        default:
            printf("\t Nous avons pas compris votre choix... Réessayez\n");
            printf("\n");
            launchFunction(principal_displayMenu());

        break;  
    }

}

void launchAlphabetFunction(int choix){
    system("clear");
    switch(choix){
        case 1:
            // TO DO
            // Waiting for JB code ..
        break;
        case 2:
            printf("\tVous avez choisi Calculer la puissance d'un mot\n");

            printf("%s\n", puis());

        break;

        case 3:
            printf("\tVous avez choisi Vérifier si un mot est vide\n");
            printf("%d\n", vide());
        break;

        case 4: 
            printf("\tVous avez choisi de concaténer deux mots\n");
            printf("%s\n", concat());
        break;

        case 5:
            printf("\tVous avez choisi de calculer le mirroir d'un mot\n");
            printf("%s\n", miroir());
        break;

        case 6:
            printf("\tVous avez choisi de vérifier si un mot est fini\n");
            printf("%d\n", estFini());
        break;
    
        case 7:
            launchFunction(principal_displayMenu());
        break;

        default:
            printf("\tNous avons pas compris votre choix... Réessayez\n");
            printf("\n");
            launchAlphabetFunction(alphabet_displayMenu());
            
        break;  
    }

}