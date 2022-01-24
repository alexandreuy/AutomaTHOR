#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../mesFonctions.h"

Automaton *importcsv(){
    Automaton *newAutomaton = automatonInitializer();
    char *filename = (char*) malloc (100);
    FILE *file = (char*) malloc (40);
    char *token;
    char line[200];
    int cpt = 0;
    char* listetat= (char*) malloc (100);
    char* listinitstate= (char*) malloc (100);
    char* listfinalstate= (char*) malloc (100);
    char *listransitions= (char*) malloc (100);
    char *listesymboles= (char*) malloc (100);
    int numbfinalstate, numbinitstate;

    printf("\n Importation mode ...\n");
    printf("\n Veuillez saisir le path du fichier a importer : \n");
    scanf("%s", filename);
    printf("filename :  %s\n", filename);
    file = fopen(filename, "r");
    if(file == NULL){
        perror("Unable to open the file.");
        exit(1);
    }
    while(fgets(line, sizeof(line), file)){        
        token = strtok(line, ";");
        int cpt1 = 0;
        while(cpt1<10){
            // nom automate
            if(cpt1== 0){
                newAutomaton->name=token;
                printf("Nom automate : %s \n", newAutomaton->name);
                token = strtok(NULL, ";");
                cpt1++;
            }

            /// nombre états
            if(cpt1== 1){
                newAutomaton->numOfStates = atoi(token);
                printf("Nombre états : %d \n", newAutomaton->numOfStates);
                token = strtok(NULL, ";");
                cpt1++;
            }
            // nombre de symbols
            if(cpt1== 2){
                newAutomaton->numOfSymbols=atoi(token);
                printf("Nombre symbols : %d \n", newAutomaton->numOfSymbols);
                token = strtok(NULL, ";");
                cpt1++;
            }
            ////// nombre de transitions
            if(cpt1== 3){
                newAutomaton->numOfTransitions=atoi(token);
                printf("Nombre transitions : %d \n", newAutomaton->numOfTransitions);               
                    token = strtok(NULL, ";");
                    cpt1++;
            }
            //Listes états
            if(cpt1== 4){
                    listetat = token;
                    printf("Liste des états %s \n", listetat);
                    token = strtok(NULL, ";");
                    cpt1++;
            }
            //// listes des transitions
            if(cpt1== 5){
                    listransitions=token;
                    printf("Liste transition %s \n", listransitions);
                    token = strtok(NULL, ";");
                    cpt1++;
            }
            ////listes des symbols
            if(cpt1== 6){
                    listesymboles=token;
                   //affectationsymbol(newAutomaton,token);
                   printf("Liste symboles %s \n", listesymboles);
                    token = strtok(NULL, ";");
                    cpt1++;
            }
            //nombre états initiaux
            if(cpt1== 7){
                    numbinitstate=atoi(token);
                    printf("Nombre états initiaux %d \n", numbinitstate);
                    token = strtok(NULL, ";");
                    cpt1++;
            }
            ///liste états initiaux 
            if(cpt1== 8){
                    listinitstate=token;
                    printf("Liste états initiaux %s \n", listinitstate);
                    token = strtok(NULL, ";");
                    cpt1++;
            }
            ////nombre états finaux
            if(cpt1== 9){
                    numbfinalstate=atoi(token);
                    printf("Nombre états finaux %d \n", numbfinalstate);
                    token = strtok(NULL, ";");
                    cpt1++;
            }
            /// liste états finaux
            if(cpt1== 10){
                    listfinalstate=token;
                    printf("Liste états finaux %s \n", listfinalstate);
                    token = strtok(NULL, ";");
                    cpt1++;
            }
        }
    }
    //création de la liste d'états
    affectationstate(newAutomaton, listetat, numbinitstate,listinitstate,numbfinalstate,listfinalstate);
    ///création des transitions
   // affectationtransition(newAutomaton,token);
    ///Création du tableau de symbol
    //affichageautomate(newAutomaton);
    affectotransition(newAutomaton, listransitions, numbinitstate, numbfinalstate, listfinalstate, listinitstate);
    affichageteststates(newAutomaton);
    affectationsymbol(newAutomaton, listesymboles);
    fclose(file);

    Suiteprocess(newAutomaton);
}
void Suiteprocess(Automaton *newAutomaton){
    int choice;
    //system("clear");
    printf("Que voulez-vous faire ? \n");
    printf("1- Modifier l'automate\n");
    printf("2- Sauvgarde du csv\n");
    printf("3- Retour au menu principale \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        modifier(newAutomaton);
        break;
    case 2:
        writecsv(newAutomaton);
        break;
    case 3:
        launchFunction(principal_displayMenu());
        break;
    default:
        Suiteprocess(newAutomaton);
        break;
    }
}


void affectationstate(Automaton *newAutomaton, char* listetat, int numbinistate, char *listinitstate, int numbfinalstate, char *listfinalstate){
    printf("AFFECTATON DES ETATS => nombre %d\n",newAutomaton->numOfStates);
    int cmpt=0;
    for(int k=1; k < ((newAutomaton->numOfStates)*2);k++){
        if(k%2!=0)
        {
            //printf("TOKEN == %c \n", listetat[k-1]);
            State *newState = stateInitializer();
            newState->name= listetat[k-1];
            
            cmpt++; 
            ///vérification de l'état si initial ou final
            int verif1 = 0;
            int verif2 =0;
            //les états sont par défaut init et finaux(true) donc on compare pour toute la liste de états finaux, 
            //si il y en 1 qui est égal sur la totalité (else vérif =1) alirs il est final ou ini//si mon état fait parti des état initiauxt
            /*printf("Taille %d \n", strlen(initstate));
            printf("Taille2 %d \n", numbinistate);
            printf("Listinitstate [k] = %c \n", listinitstate[1-1]);*/
            for(int i=1; i< numbinistate*2;i++){
                printf("Listinitstate [k] = %c contre %c\n", listinitstate[i-1], listetat[k-1]);
                if(listetat[k-1] =! listinitstate[i-1])  {
                   
                    newState->isInitial=false;}
                    /*
                char* str1;
                char* str2;
                strcpy(str1,listetat[k-1] );
                strcpy(str2,listinitstate[i-1]);
                int answ=strcmp(str1, str2);
                printf("OKKKKK %d", answ);*/
                else if(listetat[k-1]==listinitstate[i-1])      ////PROBLEME DE COMPARAISON DE CHARS
                        {
                            printf("OKKKKK");
                            verif1=1;}
            }
                if (verif1==1){
                    verif1=0;
                    newState->isInitial=true;
                   // printf("ETAT => %c est initial \n", newState->name);
                }

            for(int p=1; p< (numbfinalstate*2) -1;p++){
                if(listetat[p-1]=!listfinalstate[p-1])  {
                    newState->isFinal=false;}
                    else if (listetat[p-1]==listfinalstate[p-1])
                        {verif2=1;}
                
                if (verif2==1){
                    verif2=0;
                    newState->isFinal=true;
                    //printf("%c est final \n", newState->name);
                }}
                                //        &
           //printf("Etat loaded == %c \n", newState->name);
           newAutomaton->states[cmpt] = newState;
           printf("Etat loaded == %c \n", newAutomaton->states[cmpt]->name);
        }
    }
    printf("Création des états fini .....\n");
}

void affichageteststates(Automaton *newAutomaton){
    printf("Vérification des données importes par affichages ------------------- \n");
    printf("Nom %s \n", newAutomaton->name);
    printf("Num of states %d \n", newAutomaton->numOfStates);
    printf("Num of transitions %d \n", newAutomaton->numOfTransitions);
    printf("Num of Symbols %d \n", newAutomaton->numOfSymbols);
    printf("Tableaux des états ::: \n");
    for(int k = 1; k< newAutomaton->numOfStates+1;k++){
        printf("Name state : %c \n", newAutomaton->states[k]->name);
        if(newAutomaton->states[k]->isInitial==true){
            printf("IS INITIAL\n");}
        if(newAutomaton->states[k]->isFinal==true){
            printf("IS FINAL\n");}
    }    
        
    }
    

//      pour tester func/Classeurtest.csv
void affectationsymbol(Automaton *newAutomaton, char* listessymbole){
    //printf("Affectation symbol\n");
    char **Symbols=malloc(100 * sizeof(char *));
    //printf("Nombre de symbol : %d\n", newAutomaton->numOfSymbols);
    int cmpt =0;
    for(int k=0;k<newAutomaton->numOfSymbols*2;k++){
            if(k%2==0){
                cmpt++;
                //printf("Liste symb de %d => %c \n", k, listessymbole[k]);
                Symbols[cmpt]= listessymbole[k];
               // printf("Symbol de %d => %c \n", cmpt, Symbols[cmpt]);}
            }
            newAutomaton->symbols = Symbols;
}
}


void affectotransition(Automaton *newAutomaton,char *token, int numbinitstate, int numbfinalstate, char * listfinalstate, char* listinitstate){
    //fonctions d'affectations / création des transitions
    printf("Importation des transitions ... \n ");
    int compteurposition =0;
    int compteurtransition =0;
    for(int k =0; k<strlen(token); k++){   
        compteurposition++;
        if(k%2==0){  //on prend un caractère sur deux pour compenser les séparateurs 
        Transition* newtransition = transitionsInitializer();
        compteurtransition++;
        printf("Gauche : %c \n", token[k]); //caractère 1 :état gauche, 2 : séparateur
        createstatetotransition(newAutomaton,newtransition, token[k], 1, numbinitstate, numbfinalstate, listfinalstate, listinitstate);   
        printf("TRANS : %c \n", token[k+2]); // caractère 3 : symbole transition, 4 : transition
        newAutomaton->symbols[compteurtransition] = token[k+2];
        createstatetotransition(newAutomaton,newtransition, token[k+2], 2,numbinitstate, numbfinalstate, listfinalstate, listinitstate);
        printf("DROITE : %c \n", token[k+4]);//caractère 5 : état droite, 6 : séparateur
        createstatetotransition(newAutomaton,newtransition, token[k+4], 3,numbinitstate, numbfinalstate, listfinalstate, listinitstate);
        k=k+5;
        newAutomaton->transitions[compteurtransition]=newtransition;
        }
    }
    
}

void createstatetotransition(Automaton * newAutomaton, Transition *newTransition, char *namestate, int choix , int numbinitstate, int numbfinalstate, char * listfinalstate, char* listinitstate){
    
    if(choix == 1){ // création de l'état de gauche
    State *newstate = stateInitializer();
    printf("TOKEN GAUCHE = %c \n", namestate);
    newstate->name=namestate;
    newstate->isInitial = false;
    newstate->isFinal = false;
    for(int q =0; q<numbinitstate; q++){ //on vérifie si l'état est dans les états initaux si oui on la caractérise
        if(newstate->name == listinitstate[q]){
            printf("TOKEN GAUCHE EST INITIAL \n");
            newstate->isInitial = true;
        }
    }
    for(int q =0; q<numbfinalstate; q++){ //on vérifie si l'état est dans les états finaux si oui on la caractérise
        if(newstate->name == listfinalstate[q]){
            printf("TOKEN GAUCHE EST FINAL \n");
            newstate->isFinal = true;
        }
    }
    newTransition->leftState=newstate;}

    if(choix == 2){
    newTransition->symbol=namestate;}

    if(choix == 3){ //création de l'état de droite
    State *newstate = stateInitializer();
    printf("TOKEN DROITE = %c \n", namestate);
    newstate->name=namestate;
    newstate->isInitial = false;
    newstate->isFinal = false;
    for(int q =0; q<numbinitstate; q++){//on vérifie si l'état est dans les états initaux si oui on la caractérise
        if(newstate->name == listinitstate[q]){
            printf("TOKEN DROITE EST INITIAL \n");
            newstate->isInitial = true;
        }
    }
    for(int q =0; q<numbfinalstate; q++){     //on vérifie si l'état est dans les états finaux si oui on la caractérise
        if(newstate->name == listfinalstate[q]){
            printf("TOKEN DROITE EST FINAL \n");
            newstate->isFinal = true;
        }
    }
    newTransition->nextState=newstate;}
}