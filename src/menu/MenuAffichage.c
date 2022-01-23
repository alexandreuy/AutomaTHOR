
#include <stdio.h>
#include <stdlib.h>
#include "../mesFonctions.h"


int principal_displayMenu(){

    printf("\t________________________________\n");
    printf("\t________________________________\n");

    int choix;
    printf("\n");
    printf("\t1. Play with alphabet\n");
    printf("\t________________________________\n");
    printf("\t2. Play with AEF\n");
    printf("\t________________________________\n");
    printf("\t3. Play with regex\n");
    printf("\t________________________________\n");
    printf("\t4. Quit\n");
    printf("\t________________________________\n");
    printf("\n");
    printf("\tHow can we help you ?\n");

    scanf("%d", &choix);

    return choix;
}

int alphabet_displayMenu(){

    int choix;

    printf("\t1. Appartient à l'alphabet\n");
    printf("\t________________________________\n");
    printf("\t2. Puissance d'un mot\n");
    printf("\t________________________________\n");
    printf("\t3. Vérifier si un mot est vide\n");
    printf("\t________________________________\n");
    printf("\t4. Concaténer deux mots\n");
    printf("\t________________________________\n");
    printf("\t5. Calculer le mirroir d'un mot\n");
    printf("\t________________________________\n");
    printf("\t6. Vérifier si une chaîne de caractère représente un mot fini\n");
    printf("\t________________________________\n");
    printf("\t7. Retour\n");
    printf("\n");
    printf("\tHow can we help you ? \n");
    scanf("%d", &choix);

    return choix;
    
}

int aef_displayMenu()
{
    printf("---[ FSA EDITOR ]---\n");
    printf("\n");
    /* Welcome Screen with a menu */
    int choice; // To choose a menu option

    printf("Please select an entry model for you automate\n");
    printf("\n");

    /* Full assisted entry mode.
      You'll be guide through questions for all steps.
    */
    printf("1. Assisted Entry Mode\n");
    printf("________________________________\n");
    /* Semi assisted entry mode.
      You'll be asked to enter a specific data format step by step.
    */
    printf("2. Semi-Assisted Entry Mode\n");
    printf("________________________________\n");
    /* Self entry mode.
      You'll be asked to enter in "only one line" with a specific format.
    */
    printf("3. Self-Entry Mode\n");
    printf("________________________________\n");
    /* Semi assisted entry mode.
      You'll be asked to give a file name (absolute path).
    */
    printf("4. File Import Mode\n");
    printf("________________________________\n");

    /* Automatic DataCharge
     */
    printf("5. Back\n");
    printf("________________________________\n");

    /* Quit or Reload
     */
    // printf("\nQuit (Q or q)\n");
    // printf("Reload (R or r)\n");
    // printf("________________________________\n");

    /* Your selection
     */
    printf("\n---");
    printf("\nYour selection : ");

    scanf("%d", &choice); // Getting your choice
    return choice;
}












