#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../mesFonctions.h"


int appartient(){
    char *string = (char *) malloc(strlen(string));
    char *alphabet = (char *) malloc(strlen(alphabet));

    printf("Enter string\n");
    scanf("%s", string);

    printf("Enter your alphabet\n");
    scanf("%s", alphabet);


    bool answer;
    char *compteurdepresence = (char *) malloc(40);
    for (int k =0; k<strlen(string); k++){
        for(int i = 0; i<strlen(alphabet); i++){
            if (string[k]==alphabet[i])
            {   
                compteurdepresence[k]= 1;                
            }else if(compteurdepresence[k]!=1){
                compteurdepresence[k]=0;
            }
        }
    }
    for (int i = 0; i < strlen(string); i++)
    {
        if(compteurdepresence[i]==0)
            return 0;
        else
            answer= 1;
    }
    if(answer==1)
        return answer;
}

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

bool vide() { 

    char *word1 = (char *) malloc(strlen(word1));
    printf("\t Choisir un mot :\n");
    scanf("%s[^\n]", word1);

    
    if(word1[0] != '\0') return false;

    return true;

}

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
