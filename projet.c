#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#define true 1
#define false 0

// char *remove_white_spaces(char *str)
// {
//     int i, len = 0,j;  

//     //Calculating length of the array  
//     len = strlen(str);  

      
//     //Checks for space character in array if its there then ignores it and swap str[i] to str[i+1];  
//     for(i = 0; i < len; i++){  
//         if(str[i] == ' '){  
//             for(j=i;j<len;j++)  
//             {  
//             //     str[j]=str[j+1];  
//             }  
//         len--;  
//         }  
//     }  

//     return str;
// }

bool vide(char *word) {
    // word = remove_white_spaces(word);

    return word == "";
}

// estFini("aaab")=true
// estFini("a*aa*bd*a")=false
bool estFini(char *word){

    return strstr(word, "*");
}


// concat("aaab","aa")=aaabaa
char* concat(char* word1,char* word2){
    int finalWordSize = strlen(word1) + 1 + strlen(word2) + 1;

    char* concatenateWord = (char *) malloc(finalWordSize);

    strcat(concatenateWord, word1);
    strcat(concatenateWord, word2);

    return concatenateWord;
    
}

// puis("ab",3)=ababab
// puis("ab",0)= ""
char *puis(char *word, int exponent) {
        char *finalWord = (char *) malloc(strlen(word) + 1 * exponent);

        if(exponent == 0) finalWord = "";

        else {
            int i = 0;
            while( i < exponent){
                finalWord = concat(finalWord, word);
                i++;
            }
        }

        return finalWord;

}


// miroir("aaab")=baaa
char *miroir(char* word){
    char *mirrorWord = (char *) malloc(strlen(word) + 1 );
    int i = 0;

    while(i < strlen(word)){
        mirrorWord[strlen(word) - i - 1 ] = word [i];
        i++;
    }

    return mirrorWord;
}

int menuAffichage_principal(){

    int choix;

    printf("\t1. Manipuler mot d'un alphabet\n");
    printf("\t2. Manipuler un AEF\n");
    printf("\t3. Manipuler des Expressions Régulières\n");
    printf("\t4. Quitter\n");
    printf("\tChoix :\n");
    scanf("%d", &choix);

    return choix;
}

int menuAffichage_alphabet(){

    int choix;

    printf("\t1. Appartient à l'alphabet\n");
    printf("\t2. Puissance d'un mot\n");
    printf("\t3. Vérifier si un mot est vide\n");
    printf("\t4. Concaténer deux mots\n");
    printf("\t5. Concaténer deux mots\n");
    printf("\t6. Retour\n");

    printf("\tChoix :\n");
    scanf("%d", &choix);

    return choix;
    
}



void main(void)
{

//    printf("%s\n", concat("aaab","aa"));

//    printf("%s\n", miroir("aaaaaaaab"));

//    printf("%s\n", puis("ab", 10));

    // printf("%d\n", estFini("aaab"));
    // printf("%d\n", estFini("aaa*b"));

//    printf("%s\n", remove_white_spaces("fds ffs  dfs  q  "));

    // printf("%s\n", vide("fdsf fsdfsq"));

    int choix=1;

    while(choix){

        menuAffichage_principal();
        printf("\tChoix :\n");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                printf("\n");
                printf("\tVous avez choisi Manipuler mot d'un alphabet\n");
                printf("\n");
                break;


            case 2:
                printf("\n");
                printf("\tVous avez choisi Manipuler un AEF\n");
                printf("\n");
                break;

            case 3:
                printf("\n");
                printf("\tVous avez choisi Manipuler des Expressions Régulières\n");
                printf("\n");
                break;

            case 4:
                printf("\n");
                printf("Au revoir !\n");
                printf("\n");
                return;

                break;

            default:
                printf("\n");
                printf("Oups... Nous avons pas compris votre choix\n");
                printf("\n");
            
        }





    }


}

