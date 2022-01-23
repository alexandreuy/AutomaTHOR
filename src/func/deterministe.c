#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../mesFonctions.h"

// Verify if there are same symbols transition for a state
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


// verify if an AEF is determinist
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


// get the position on the state tab of the initial state
int getPositionInitState(State** states, int numOfStates)
{

    for(int i = 0; i < numOfStates; i++){
        if(*&(states[i]->isInitial)) return i;
    }

    return 0;
}

// Not working yet
Automaton* makeItDeterminist(Automaton* automate){
    
    Automaton *newAutomaton = automatonInitializer();
    newAutomaton->name = "Determinist";

    int positionInitState = getPositionInitState(automate->states, automate->numOfStates);

    // Création de l'état initial
    State *newState = stateInitializer();
    newState->name = automate->states[positionInitState]->name;
    newState->isInitial = automate->states[positionInitState]->isInitial;
    newState->isFinal = automate->states[positionInitState]->isFinal;
    newAutomaton->states[newAutomaton->numOfStates] = automate->states[positionInitState];
    newAutomaton->numOfStates = newAutomaton->numOfStates++;
    

    // for(int i = 0; i < automate->numOfStates;i++){
    //     char** transitionsSymbols = getTransitionOfState(automate->transitions, "C", automate->numOfTransitions);
    //     for(int j = 0; j < getSizeOfTab(transitionsSymbols); j++){
    //         for(int k = 0; k < automate->numOfTransitions; k++){
    //             if(strcmp(*&(transitionsSymbols[j]), automate->transitions[k]->symbol) == 0 && automate->transitions[k]->leftState->name == "C"){
    //                 printf("\n[ %s ] . %s . [ %s ]",
    //                 automate->transitions[k]->leftState->name,
    //                 automate->transitions[k]->symbol,
    //                 automate->transitions[k]->nextState->name
    //                 );      
    //             }
    //         }
    //     }
    // }



    return newAutomaton;
    
}

// void main()
// {
//     makeItDeterminist(dataCharge());

//     // printf("\nDeterministe : %d\n", isDeterminist(dataCharge()));
// }