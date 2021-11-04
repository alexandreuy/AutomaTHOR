#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../mesFonctions.h"

#define true 1
#define false 0


char *puis() {

    int exponent;

    printf("\tChoisissez un mot:\n");
    char *word = (char *) malloc(strlen(word));
    scanf("%s", word);

    printf("\tChoisissez un exposant:\n");
    scanf("%d", &exponent);

    char *finalWord = (char *) malloc(strlen(word) + 1 * exponent);

    if(exponent == 0) finalWord = "";

    else {
        int i = 0;
        while( i < exponent){
            finalWord = strcat(finalWord, word);
            i++;
        }
    }

    return finalWord;

}

// bool vide() {
//     // word = remove_white_spaces(word);

//     char str[100];
//     printf("\t Choisir un mot :\n");
//     fgets(str, 100, stdin);


//     return false;

// }

char *concat(){
    printf("\tChoisissez un premier mot:\n");
    char *word1 = (char *) malloc(strlen(word1));
    scanf("%s", word1);

    printf("\tChoisissez un second mot:\n");
    char *word2 = (char *) malloc(strlen(word2));
    scanf("%s", word2);


    int finalWordSize = strlen(word1) + 1 + strlen(word2) + 1;

    char* concatenateWord = (char *) malloc(finalWordSize);

    strcat(concatenateWord, word1);
    strcat(concatenateWord, word2);

    return concatenateWord;
    
}

char *miroir(){

    printf("\tChoisissez un mot:\n");
    char *word = (char *) malloc(strlen(word));
    scanf("%s", word);

    
    char *mirrorWord = (char *) malloc(strlen(word) + 1 );
    int i = 0;

    while(i < strlen(word)){
        mirrorWord[strlen(word) - i - 1 ] = word [i];
        i++;
    }

    return mirrorWord;
}


bool estFini(){

    printf("\tChoisissez un mot:\n");
    char *word = (char *) malloc(strlen(word));
    scanf("%s", word);


    if (strstr(word, "*")) return true;

    return false;
}
