#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../mesFonctions.h"

bool doublonVerification(Transition **tabTransition, char *name, int numberOfTransitions)
{
    char **tab = malloc(100);

    for (int i = 0; i < numberOfTransitions; i++)
    {
        if (strcmp(tabTransition[i]->leftState->name, name) == 0)
        {
            if(isPresent(tab, tabTransition[i]->symbol, numberOfTransitions)) return true;
            
            else *(&tab[i]) = (tabTransition[i]->symbol);
        }
    }

    return false;
}

int numberOfInitialState(Automaton *automaton)
{
    int count = 0;

    for (int i = 0; i < automaton->numOfStates; i++)
    {
        if(automaton->states[i]->isInitial) count+=1;
         
    }
    return count;
}

bool isDeterminist(Automaton *automaton)
{
    if (numberOfInitialState(automaton) > 1)
        return false;

    for (int i = 0; i < automaton->numOfStates; i++)
    {
        bool try = doublonVerification(automaton->transitions, automaton->states[i]->name, automaton->numOfTransitions);

        if (try)
            return false;
    }

    return true;
}


// bool deterministe(Automaton *newAutomaton){
//     // renvoie faux si non déterministe et true si déterministe 
//     char * transition[100]; 
//     int answer; 
//     for(int k=0; k<newAutomaton->numOfTransitions; k++){ 
//         newAutomaton->transitions[k]->symbol=transition[k];

//         printf("\n%s", transition[k]);
//     }

//     for(int q =1; q<newAutomaton->numOfTransitions;q++){
//         for(int i=1; i<newAutomaton->numOfTransitions; i++){
//             //                  même symbole                                                       transition d'un même point de départ
//             if(newAutomaton->transitions[q]->symbol==newAutomaton->transitions[i]->symbol  && newAutomaton->transitions[q]->leftState==newAutomaton->transitions[i]->leftState){
//                 //printf("C'est un automate non -déterministe \n");
//                 return true;
//             }
//             else{
//                 //printf("C'est un automate déterministe \n");
//                 answer=1;
//             }
//         }
//     }
//     if(answer==1){
//         return false;
//     }
// }

// void main()
// {

//     printf("\nDeterministe : %d\n", deterministe(dataCharge()));
// }