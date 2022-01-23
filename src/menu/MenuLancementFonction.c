#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../mesFonctions.h"

void launchFunction(int choice){
    system("clear");
    switch(choice){
        case 1:
            printf("\tYou choose play with alphabet\n");
            printf("\t________________________________\n");
            printf("\t________________________________\n");            
            printf("\n");
            launchAlphabetFunction(alphabet_displayMenu());
        break;
        case 2:
            printf("\tYou choose play with AEF\n");
            printf("\t________________________________\n");
            printf("\t________________________________\n");
            printf("\n");
            launchAEFFunction(aef_displayMenu());
        break;
        case 3 :
            printf("\tYou choose play with regex\n");
            printf("\t________________________________\n");
            printf("\t________________________________\n");
            printf("\n");
            MenuSelector(regExMenu());

        break;
        case 4:
            printf("\n \t See you soon on AutomaTHOR !\n");
            return;
        break;
        default:
            printf("\t Please retry... with a valid choice\n");
            printf("\n");
            launchFunction(principal_displayMenu());

        break;  
    }

}

void launchAlphabetFunction(int choice){
    system("clear");
    switch(choice){
        case 1:
            printf("\tYou choose Calculer la puissance d'un mot\n");
            printf("%d\n", appartient());
        break;
        case 2:
            printf("\tYou choose Calculer la puissance d'un mot\n");
            printf("%s\n", puis());

        break;

        case 3:
            printf("\tYou choose Vérifier si un mot est vide\n");
            printf("%d\n", vide());
        break;

        case 4: 
            printf("\tYou choose de concaténer deux mots\n");
            printf("%s\n", concat());
        break;

        case 5:
            printf("\tYou choose de calculer le mirroir d'un mot\n");
            printf("%s\n", miroir());
        break;

        case 6:
            printf("\tYou choose vérifier si un mot est fini\n");
            printf("%d\n", estFini());
        break;
    
        case 7:
            launchFunction(principal_displayMenu());
        break;

        default:
            printf("\t Please retry... with a valid choice\n");            
            printf("\n");
            launchAlphabetFunction(alphabet_displayMenu());
            
        break;  
    }

}


void launchAEFFunction(int choice)
{
    system("clear");              // clear the windows command line

    switch (choice)
    {
    case 1:
        system("clear");                 // clear the windows command line
        printf("\tAssisted Entry Mode\n"); // Print choosen mode
        assistedEntryMode();             // load the assisted mode entry function
        break;
    case 2:
        system("clear");                      // clear the windows command line
        printf("\tSemi-Assisted Entry Mode\n"); // Print choosen mode
        break;
    case 3:
        system("clear");             // clear the windows command line
        printf("\tSelf-Entry Mode\n"); // Print choosen mode
        break;
    case 4:
        system("clear");              // clear the windows command line
        printf("\tFile Import Mode\n"); // Print choosen mode
    case 5:
        // dataCharge();
        system("clear");
        printf("Back");
        launchFunction(principal_displayMenu());
        break;
    }
}