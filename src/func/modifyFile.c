#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../mesFonctions.h"


Automaton* modifier(Automaton* newAutomaton){
    //this function modify data from the automata
    //modify name
    int choix;
    printf("Que voulez vous modifier ? \n");
    printf("Attention, aux modifications incohérentes ! \n");
    printf("1- Nom de l'automate \n");
    printf("2- Nombre d'etats \n");
    printf("3- Nombre de transition \n");
    printf("4- Nombre de symbols \n");
    printf("5- Etats\n");
    printf("6- Transitions \n");
    printf("7- Sauvegarde\n");
    printf("0- Rien \n");
    scanf("%d", &choix);
    printf("Vous avez fait le choix %d \n", choix);

    switch(choix){
    case 1:
        printf("Modification du nom de l'automate \n");
        changename(newAutomaton);
        break;
    case 2:
        printf("Modification du nombre d'états\n");
            modifnbetats(newAutomaton);
        break;
    case 3:
        printf("Modification du nombre de transition \n");
          modifnbtrans(newAutomaton);
        break;
    case 4:
        printf("Modification du nombre de symbols \n");
        modifnbsymbol(newAutomaton);
        break;
    case 5:
        printf("Modification des états \n");
            modifstates(newAutomaton);
        break;
    case 6:
        printf("Modification des transitions \n");
        changetransition(newAutomaton);
        break;
    case 7:
        writecsv(newAutomaton);
        break;
    case 0: 
        printf("Retour au menu principal \n");
        launchFunction(principal_displayMenu());
        break;
    default:
        modifier(newAutomaton);
        break;
    }
}

void changename(Automaton* newAutomaton){
    char *newname[100];
    printf("Le nom actuel de l'automate est : %s \n", newAutomaton->name);
    printf("Quel est le nouveau nom de l'automate ? \n");
    scanf("%s", &newname);
    newAutomaton->name = newname;
    printf("Nouveau nom : %s \n", newAutomaton->name);
    modifier(newAutomaton);
}        

void modifnbetats(Automaton *newAutomaton){
    printf("Le nombe actuel d'état est de : %d \n", newAutomaton->numOfStates);
    printf("Quel est le nouveau nombre d'état ? \n");
    int nbstate;
    scanf("%d", &nbstate);
    newAutomaton->numOfStates=nbstate;
    printf("Nouveau nombre de états %d \n", nbstate);
    modifier(newAutomaton);
}

void modifnbtrans(Automaton *newAutomaton){
    printf("Le nombe actuel de transitions est de : %d \n", newAutomaton->numOfTransitions);
    printf("Quel est le nouveau nombre de transition ? \n");
    int nbtrans;
    scanf("%d", &nbtrans);
    newAutomaton->numOfTransitions=nbtrans;
    printf("Nouveau nombre de transition %d \n", newAutomaton->numOfTransitions);
    modifier(newAutomaton);
}

void modifnbsymbol(Automaton *newAutomaton){
    printf("Le nombe actuel de symbols est de : %d \n", newAutomaton->numOfSymbols);
    printf("Quel est le nouveau nombre de symbols ? \n");
    int nbsymbols;
    scanf("%d", &nbsymbols);
    newAutomaton->numOfSymbols=nbsymbols;
    printf("Nouveau nombre de symbols %d \n", newAutomaton->numOfSymbols);
    modifier(newAutomaton);
}

void modifstates(Automaton *newAutomaton){
    printf("Voici les états de l'automate : \n");
    for(int k =1; k<newAutomaton->numOfStates+1; k++){
        printf("States %d: %c ", k, newAutomaton->states[k]->name);
        if(newAutomaton->states[k]->isFinal)
            printf(" et est final \n");
        if(newAutomaton->states[k]->isInitial)
            printf(" et est inital \n");
    }
    printf("Selectionnez le numéro de l'état à modifier \n");
    int choix;
    scanf("%d", &choix);
    printf("Nom de l'état %d : \n", choix);
    char nom;
    scanf(" %c",&nom);
    newAutomaton->states[choix]->name = nom;
    printf("Nouveau nom de l'état : %c \n", newAutomaton->states[choix]->name);
    int choix1 = 2;
    printf("Est-il initial ?(0-oui, 1-non) \n");
    scanf("%d", &choix1);
        if (choix1==0){
            newAutomaton->states[choix]->isInitial=true;
        }else if(choix1==1){
            newAutomaton->states[choix]->isInitial=false;
        }
    choix1=2;
    printf("Est-il final ?(0-oui, 1-non) \n");
    scanf("%d", &choix1);
        if (choix1==0){
            newAutomaton->states[choix]->isFinal=true;
        }else if(choix1==1){
            newAutomaton->states[choix]->isFinal=false;
        }
    printf("States %d: %c ", choix, newAutomaton->states[choix]->name);
        if(newAutomaton->states[choix]->isFinal)
            printf(" et est final \n");
        if(newAutomaton->states[choix]->isInitial)
            printf(" et est inital \n");
            modifier(newAutomaton);
}
/*
void modiftransition(Automaton *newAutomaton){
    printf("Voici les transitions de l'automate \n");
    for (int i = 1; i < newAutomaton->numOfTransitions; i++)
    {
        printf("Etats gauche ");
    }
    

}*/


void affichagetransition(Automaton *newAutomate){
    printf("Voici les transitions : \n");
    for(int k=1; k<newAutomate->numOfTransitions+1; k++) {
        printf("\n TRANSITION NUM %d \n", k);
            printf("\n -> Transiton : %c \n", newAutomate->transitions[k]->symbol);
            printf("Gauche : %c \n", newAutomate->transitions[k]->leftState->name);
            printf("DROITE : %c \n", newAutomate->transitions[k]->nextState->name);
    }
}

void changetransition(Automaton *newAutomate){  /////////////des prob dans la fonction 
    int choix; 
    char *leftstate;
    char *symbol; 
    char *nextstate;
    affichagetransition(newAutomate);
    printf("Quelle est le numéro de transition à modifier ? \n");
    scanf("%d",&choix);
    printf("Quel est l'état de départ ? \n"); 
    scanf("%s", &leftstate);
    printf("Quel est l'état final de la transition ? \n");
    scanf("%s",&nextstate); 
    printf("Quel symbol attribuer à la transition ?\n");
    scanf("%s", &symbol);
    //printf("Voici la nouvelle transition au numéro %d : %s de %s à %s ", choix,symbol,leftstate,nextstate);
    //newAutomate->transitions[choix]->leftState->name =leftstate;   
    State *newstateleft = stateInitializer();
    State *newnextstate = stateInitializer();
    //on vérifie les états parmi les initiaux et finaux pour caractériser correctement les états avant l'attribution de la transition
    
   newstateleft->name = leftstate;
   newnextstate->name = nextstate;
   newAutomate->transitions[choix]->symbol = symbol;
   newAutomate->symbols[choix] =symbol;
   
   for(int t =1; t<newAutomate->numOfStates+1; t++){
       if(newstateleft->name==newAutomate->states[t]->name && newAutomate->states[t]->isInitial == true){
           newstateleft->isInitial=true;
       }
       if(newnextstate->name==newAutomate->states[t]->name && newAutomate->states[t]->isInitial==true){
           newnextstate->isInitial=true;
       }
       if(newstateleft->name==newAutomate->states[t]->name && newAutomate->states[t]->isFinal == true){
           newstateleft->isFinal=true;
       }
       if(newnextstate->name==newAutomate->states[t]->name && newAutomate->states[t]->isFinal==true){
           newnextstate->isFinal=true;
       }
       
   } 
    int verif=0;
    int verif1=0;
   for (int i = 1; i < newAutomate->numOfStates+1; i++)
   {    printf("%c , %c , vérif : %d \n",newstateleft->name,newAutomate->states[i]->name, verif);
       if(strcmp(&newstateleft->name,&newAutomate->states[i]->name)==0){
           verif=1;
       }
       if(strcmp(&newnextstate->name,&newAutomate->states[i]->name)==0){
           verif1=1;
       }
   }
   if(verif!=1 || verif1!=1){        ///vérification existence de l'état
    printf("Impossible d'associer une transition à un état inexistant, veuillez crer l'etat avant.\n");
    newAutomate->transitions[choix]->symbol = symbol;
    newAutomate->symbols[choix] =symbol;
    modifier(newAutomate);
    verif=0;
   }
   
     /*              ///A VERIFIER LA PERTINENCE
   int verif=0;
   for (int i = 1; i < newAutomate->numOfStates+1; i++)
   {
       if(newstateleft->name==newAutomate->states[i]->name){
           verif=1;
       }
   }
   if(verif==1){        ///vérification existence de l'état
    newAutomate->numOfStates=newAutomate->numOfStates+1;
    newAutomate->states[newAutomate->numOfStates]=newstateleft;
    verif=0;
   }
   for (int i = 1; i < newAutomate->numOfStates+1; i++)
   {
       if(newnextstate->name==newAutomate->states[i]->name){
           verif=1;
       }
   }
   if(verif==1){        ///vérification existence de l'état
    newAutomate->numOfStates=newAutomate->numOfStates+1;
    newAutomate->states[newAutomate->numOfStates]=newnextstate;
    verif=0;
   }*/                                 //A VERIFIER LA PERTINENCE
   
    newAutomate->transitions[choix]->leftState = newstateleft;
    newAutomate->transitions[choix]->nextState = newnextstate;
    affichagetransition(newAutomate);

    modifier(newAutomate);
}


///ajouter etat
///ajouter transition
//update symbol selon nouvelle transition