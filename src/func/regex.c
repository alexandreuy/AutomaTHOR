#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../mesFonctions.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
// Conversion https://qastack.fr/cs/2016/how-to-convert-finite-automata-to-regular-expressions

int saveInAFile(char *regEx)
{
    FILE *fichier = NULL;
    char *filePath = malloc(sizeof(char));
    int maxLgth = 300;
    printf("--- FILE SAVING ---\n"); // Print choosen mode

    printf("__________\n");
    printf("Your path : ");
    scanf("%s", filePath);

    // fgetc(stdin);
    printf("-----\n");
    printf("---\n");
    printf("Your regEX : %s\n", regEx);

    fichier = fopen(filePath, "w");
    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        fputs(regEx, fichier); // Écriture du caractère A
        fclose(fichier);       // On ferme le fichier qui a été ouvert
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Error while trying to open the file !!!");
        return EXIT_FAILURE;
    }
    printf("\n\n"); 
    // system("clear");
    sleep(3);
    printf("SAVED !!!\n\n");
    sleep(5);
    system("clear");

    return 0;
}

char *editARegEx(char *regExToEdit)
{
    char *toEdit = malloc(sizeof(regExToEdit));
    int test = 0;
    int ans;
    do
    {
        printf("\n__________\n");
        printf("Enter the new regEX : ");
        scanf("%s", toEdit);
        printf("You entered : %s\n", toEdit);
        printf("\n");
        printf("Continue ?\n");
        printf("y (1), n (0)\n");
        scanf("%d", &ans);
        if (ans == 1)
        {
            regExToEdit = toEdit;
            test = 1;
            printf("Saved !!!\n");
            system("clear");
        }
    } while (test == 0);

    saveInAFile(toEdit);

    return toEdit;
}

void regExEdSelector(char *regEx, int choice)
{
    switch (choice)
    {
    case 1:
        system("clear");             // clear the windows command line
        printf("--- Edition ---\n"); // Print choosen mode
        editARegEx(regEx);           // load the mode
        break;
    case 2:
        system("clear");                       // clear the windows command line
        printf("--- Saving your REGEX ---\n"); // Print choosen mode
        saveInAFile(regEx);
        break;
    default:
        exit(0);
    }
}

int regExEdMenu(char *regEx)
{
    int choice; // To choose a menu option

    printf("Please select an option\n");
    printf("\n");

    /* Manually enter a regEx
     */
    printf("1. Edit your REGEX\n");
    printf("________________________________\n\n");

    /* Import a regEx from a file
     */
    printf("2. Save the REGEX in a file\n");
    printf("________________________________\n");

    /* Quit or Reload
     */
    printf("\nPress another key to quit\n");
    // printf("Reload (R or r)\n");
    printf("________________________________\n");

    /* Your selection
     */
    printf("\n---");
    printf("\nYour selection : ");

    scanf("%d", &choice); // Getting your choice
    return choice;
}

int editor(char *regEx)
{
    system("clear");
    printf("---[ LET'S EDIT YOUR REG'EX' ]---\n");
    printf("\n");

    printf("---\n");
    printf("Your regEX : %s\n", regEx);

    regExEdSelector(regEx, regExEdMenu(regEx));

    return 0;
}

/* ________________________
Regex Menu
---------------------------
---------------------------*/
int regExMenu()
{
    system("clear");
    printf("---[ REGULAR EXPRESSIONS EDITOR ]---\n");
    printf("\n");
    /* Welcome Screen with a menu */
    int choice; // To choose a menu option

    printf("Please select an entry model for you automate\n");
    printf("\n");

    /* Manually enter a regEx
     */
    printf("________________________________\n");
    printf("1. Enter a regular expression\n");
    printf("e.g. (a+b)*ab(a+b*)\n");
    printf("________________________________\n");
    /* Import a regEx from a file
     */
    printf("2. Import a regular expression from a file\n");
    printf("________________________________\n");


    printf("3. Back\n");
    printf("________________________________\n");

    /* Quit or Reload
     */
    printf("\nPress another key to quit\n");
    // printf("Reload (R or r)\n");
    printf("________________________________\n");

    /* Your selection
     */
    printf("\n---");
    printf("\nYour selection : ");

    scanf("%d", &choice); // Getting your choice
    return choice;
}

bool parityMatch(char *regEx, char bef, char aft)
{
    bool ans = true;
    char *p;
    p = strchr(regEx, bef);
    char *q;
    q = strchr(regEx, aft);
    int a, b;
    printf("%s and %s\n", p, q);

    while ((p != NULL) || (q != NULL))
    {
        a = p - regEx + 1;
        b = q - regEx + 1;

        printf("%d\n", b - a);

        if ((b - a) == 1)
        {
            printf("\n[ ERROR : Bad operators position ]\n");
            ans = false;
            break;
        }
        else
        {
            p = strchr(p++, bef);
            q = strchr(p++, aft);
        }
        // printf("%s and %s\n", p, q);
    }
    return ans;
}

bool isCorrect(char *regEx)
{
    bool answ = false;
    char symbols[] = {'(', ')', '+', '*'};
    int i = 0;
    int pos_tab = 0;
    char tab_alpha[27];
    bool validator[] = {true, true, true, true, true, true};

    for (i = 'a'; i <= 'z'; i++)
    {
        tab_alpha[pos_tab] = i;
        pos_tab++;
    }

    char *p;
    int cpt = 0;

    // 1. There's no character other than the alphabet, parentheses, and the + and * symbols.
    for (i = 0; i < strlen(regEx); i++)
    {
        if ((strchr(tab_alpha, regEx[i]) != NULL) || (strchr(symbols, regEx[i]) != NULL))
        {
            cpt++;
        }
    }
    if (cpt != strlen(regEx))
    {
        printf("\n[ ERROR : Bad Character ]\n");
        answ = false;
        validator[0] = false;
    }
    else
    {
        printf("\nValid regEx !!!\n\n");
        answ = true;
    }

    // 2. The +, *, and ) doesn't start the regEx.
    for (int i = 1; i < sizeof(symbols); i++)
    {
        p = strchr(regEx, symbols[i]);
        // printf("%ld\n", p - regEx + 1);
        if (p - regEx + 1 == 1)
        {
            printf("\n[ ERROR : Bad operators position ]\nThe +, *, and ) can't start the regEx.\n");

            answ = false;
            validator[1] = false;
            break;
        }
    }

    // 3. The + and the ( doesn't end the regEx.
    for (int i = 1; i < sizeof(symbols); i++)
    {
        p = strchr(regEx, symbols[i]);
        if (i == 0 || i == 2)
        {
            if (p - regEx + strlen(regEx) == 1)
            {
                printf("\n[ ERROR : Bad operators position ]\nThe + and the ( can't end the regEx.\n");
                answ = false;
                validator[2] = false;
                break;
            }
        }
    }

    // 4. The + isn't placed before a *.
    // if (!parityMatch(regEx, '+', '*') || !parityMatch(regEx, '+', ')') || !parityMatch(regEx, '(', '+') || !parityMatch(regEx, '(', ')') || !parityMatch(regEx, '(', '*'))
    // {
    //     answ = false;
    //     validator[3] = false;
    // }

    // 5. There are as many opening parentheses as there are closing parentheses.
    // 6. parentheses are useed the right way. *+
    return answ;
}

/* ________________________
Manual Mode
---------------------------
---------------------------*/
int manualMode()
{
    char *regEX;

    do
    {
        printf("__________\n");
        printf("Your regEX : ");
        scanf("%s", regEX);
        printf("You entered : %s\n", regEX);
        printf("\n");

        sleep(3);
        system("clear");
    } while (!isCorrect(regEX));

    printf("Loading the editor...\n");
    sleep(5);
    editor(regEX);
    return EXIT_FAILURE;
}

/* ________________________
FIle IMport Mode
---------------------------
---------------------------*/
int fileImportMode()
{
    FILE *fichier = NULL;
    char *filePath = malloc(sizeof(char));
    char *regEX = malloc(300 * sizeof(char));
    int maxLgth = 300;
    printf("__________\n");
    printf("Your path : ");
    scanf("%s", filePath);

    // fgetc(stdin);
    printf("-----\n");
    printf("Your regEX : ");

    fichier = fopen(filePath, "r");
    if (fichier != NULL)
    {
        // On peut lire et écrire dans le fichier
        fgets(regEX, maxLgth, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
        printf("%s", regEX);            // On affiche la chaîne
        fclose(fichier);                // On ferme le fichier qui a été ouvert
    }
    else
    {
        // On affiche un message d'erreur si on veut
        printf("Error while trying to open the file !!!");
        return EXIT_FAILURE;
    }
    printf("\n");
    printf("\n");
    printf("Loading the Menu...");
    sleep(5);

    if (isCorrect(regEX))
        editor(regEX);
    return 0;
}

/* ________________________
Selector
---------------------------
---------------------------*/
void MenuSelector(int choice)
{
    switch (choice)
    {
    case 1:
        system("clear");                 // clear the windows command line
        printf("--- Manual Mode ---\n"); // Print choosen mode
        manualMode();                    // load the mode
        break;
    case 2:
        system("clear");              // clear the windows command line
        printf("File import Mode\n"); // Print choosen mode
        fileImportMode();
        break;
    case 3 :
        system("clear");              // clear the windows command line
        printf("Back\n"); // Print choosen mode
        launchFunction(principal_displayMenu());
        break;
    default:
        exit(0);
    }
}

// int main(int argc, const char *argv[])
// {
//     MenuSelector(regExMenu());
//     return 0;
// }