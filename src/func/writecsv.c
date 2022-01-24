#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../mesFonctions.h"

void writecsv(Automaton *newAutomaton){
    char *filename = (char*) malloc (40);
    char filewan [100];
    printf("Rentrez le nouveau nom de fichier : (.csv)\n");
    scanf("%s", &filewan);
    printf("filename :  %s\n", filewan);
    filename = filewan;

    char * Name = newAutomaton->name;
    char * Transition = (char *) malloc( 100 );
    int nombreetats = newAutomaton->numOfStates;
    int nombresymbole = newAutomaton->numOfSymbols;
    int nombtransition= newAutomaton->numOfTransitions;
    ///
    char *listeetats= (char *) malloc( 100 );   
    char *listesymbol= (char *) malloc( 100 );  
    int nombreetatsinit;
    int nombreetatsfinaux; 
    char *listeetatsinit= (char *) malloc( 100 ); 
    char *listetatsfinaux= (char *) malloc( 100 );

    listeetats[0]='\0';
    printf("Test conditionnement des données %d \n", newAutomaton->numOfStates);
    for(int k =1; k< newAutomaton->numOfStates+1;k++){
        if(k<newAutomaton->numOfStates){
        strcat(listeetats,strcat(&newAutomaton->states[k]->name, ","));
        printf(" Liste états ::::%s \n", listeetats);}
        else if(k==newAutomaton->numOfStates){
            strcat(listeetats,&newAutomaton->states[k]->name);
            printf(" Liste états ::::%s \n", listeetats);}
        }
    

    Transition[0]='\0';
    listesymbol[0]='\0';

    for(int i=1; i< newAutomaton->numOfTransitions+1; i++){
    
        strcat(Transition,&newAutomaton->transitions[i]->leftState->name);
        strcat(Transition,"."); //attention strc ne fonctionne pas comme ca
        strcat(Transition, &newAutomaton->transitions[i]->symbol);
        strcat(Transition,"."); 
        strcat(Transition, &newAutomaton->transitions[i]->nextState->name);
        if(i<newAutomaton->numOfTransitions){
            strcat(Transition, ",");
        }
    
        printf("TRANSITION : %s \n ", &newAutomaton->transitions[i]->leftState->name);
        printf("TRANSITION : %s \n ", &newAutomaton->transitions[i]->symbol);
        printf("TRANSITION : %s \n ", &newAutomaton->transitions[i]->nextState->name);

        if(i <newAutomaton->numOfTransitions){
            char *temp= &newAutomaton->transitions[i]->symbol;
        strcat(listesymbol, strcat(temp, ","));}
        else if(i==newAutomaton->numOfTransitions){
            strcat(listesymbol,&newAutomaton->transitions[i]->symbol);
        }
        printf(" Symbol :::%s \n", listesymbol);
    }

    listeetatsinit[0]='\0';
    listetatsfinaux[0]='\0';
    for(int e=1; e<newAutomaton->numOfStates+1; e++){
        if(newAutomaton->states[e]->isInitial==true){
            nombreetatsinit++;
            strcat(listeetatsinit,&newAutomaton->states[e]->name);}

        
        if(newAutomaton->states[e]->isFinal==true){
            nombreetatsfinaux++;
            strcat(listetatsfinaux, &newAutomaton->states[e]->name);}
            
        
    }
    printf("Liste états initiaux ::: %s \n", listeetatsinit);
    printf("Liste états finaux ::: %s \n", listetatsfinaux);



    size_t fullSize;
    fullSize = nombreetatsinit*2 + 3 +  nombreetatsfinaux*2 + 3 +  nombtransition*2 + 1+  sizeof( Name ) + 1;
    char *fulltext = (char*) malloc (fullSize*2);
    FILE* file ;
    file=fopen(filename,"w+");
    //concaténation des éléments en un seul char 
    char *tmp;
    strcpy( fulltext, Name);
    strcat( fulltext, "; " );
    asprintf(&tmp, "%d", nombreetats);
    strcat( fulltext, tmp);
    strcat( fulltext, "; " );
    asprintf(&tmp, "%d", nombresymbole);
    strcat( fulltext, tmp);
    strcat( fulltext, "; ");
    asprintf(&tmp, "%d", nombtransition);
    strcat( fulltext, tmp);
    strcat( fulltext, "; ");
    strcat( fulltext, listeetats);
    strcat( fulltext, "; ");
    strcat( fulltext, Transition);
    strcat( fulltext, "; ");
    strcat( fulltext, listesymbol);
    strcat( fulltext, "; ");
    asprintf(&tmp, "%d", nombreetatsinit);
    strcat( fulltext, tmp);
    strcat( fulltext, "; ");
    strcat( fulltext, listeetatsinit);
    strcat( fulltext, "; ");
    asprintf(&tmp, "%d", nombreetatsfinaux);
    strcat( fulltext, tmp);
    strcat( fulltext, "; ");
    strcat( fulltext, listetatsfinaux);
    strcat( fulltext, "; ");
    printf("Creation de %s .............\n", filename);
    printf(" AVEC : %s \n", fulltext);
    fprintf(file,fulltext);
    fclose(file);
    printf("Modification ......\n");

    modifier(newAutomaton);
}

