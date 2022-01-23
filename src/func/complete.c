#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../mesFonctions.h"

// Verify if an AEF is complete
bool isComplete(Automaton *automaton)
{
    // char **tab = getTransitionOfState(automaton->transitions, "C", automaton->numOfTransitions);

    for (int i = 0; i < automaton->numOfStates; i++)
    {
        int stateTransition = getSizeOfTab(getTransitionOfState(automaton->transitions, automaton->states[i]->name, automaton->numOfTransitions));

        if (stateTransition != automaton->numOfSymbols)
            return false;
    }

    return true;
}

// get a tab with all the  transition  symbols missing of a state
char** symbolsMissing(char** tabSymbolStateTransition, char** symbols, int numOfSymbols){
    
    char** tab = malloc(sizeof(char*));
    bool present = false;
    int cpt =0;

    // Boucle sur tous les symboles de l'automate
    for(int i=0; i < numOfSymbols; i++){
        // printf("\nLes symboles : %s\n", *&(symbols[i]));
        for(int j=0; j < getSizeOfTab(tabSymbolStateTransition);j++){
            // printf("\nSymboles de C : %s\n", *&(tabSymbolStateTransition[j]));
            if(*&(symbols[i]) == *&(tabSymbolStateTransition[j])) {
                present =true; 
                break;

            }
            else {
                present = false;
            } 
        }
        if(!present){
            *&(tab[cpt]) = *&(symbols[i]);
            cpt++;

        }
    }

    return tab;

}

// Verifiy if the P state is already created
int isPStateExist(Automaton *automaton){
    bool isCreate = false;

    for(int i = 0; i < automaton->numOfStates;i++){
        if(automaton->states[i]->name == "P") return i;
    }

    return 0;
}

// Make an AEF determinist
Automaton *makeItComplete(Automaton *automaton)
{
    
    for(int i = 0 ; i < automaton->numOfStates; i++){
        // Récupère les symboles manquants d'un état
        char** tab = symbolsMissing(getTransitionOfState(automaton->transitions, automaton->states[i]->name, automaton->numOfTransitions), automaton->symbols, automaton->numOfSymbols);
        int length = getSizeOfTab(tab);
        for(int j =0; j < length; j++){
            int positionP = isPStateExist(automaton);
            if( positionP == 0) {  // Création état poubelle
                State *newState = stateInitializer();
                newState->name = "P";
                newState->isInitial = false;
                newState->isFinal = false;
                automaton->states[automaton->numOfStates] = newState;
                // Récupération symboles manquants de l'état poubelle
                char** symbolsInexistent = symbolsMissing(getTransitionOfState(automaton->transitions, newState->name, automaton->numOfTransitions), automaton->symbols, automaton->numOfSymbols);
                for(int z =0; z < getSizeOfTab(symbolsInexistent); z++){
                    // Pour chaque symbole manquant de l'état poubelle je vais créer une transition
                    Transition *newTransition = transitionsInitializer();
                    newTransition->leftState = newState;
                    newTransition->nextState = newState;
                    newTransition->symbol = *&(symbolsInexistent[z]);
                    automaton->transitions[automaton->numOfTransitions] = newTransition;
                    automaton->numOfTransitions++;
                }
                positionP = automaton->numOfStates;
                automaton->numOfStates++;
            }
            // Création des transitions avec les symboles manquants d'un état
            Transition *newTransition = transitionsInitializer();
            newTransition->leftState = automaton->states[i];
            newTransition->nextState = automaton->states[positionP];
            newTransition->symbol = *&(tab[j]);
            automaton->transitions[automaton->numOfTransitions] = newTransition;
            automaton->numOfTransitions++;
        }

    }
    
    return automaton;

}
// void main()
// {
//     // isComplete(dataCharge());

//     Automaton* automate = makeItComplete(dataCharge());

//     for (int i = 0; i < automate->numOfTransitions ; i++)
//     {
//     printf("\n[ %s ] . %s . [ %s ]",
//            automate->transitions[i]->leftState->name,
//            automate->transitions[i]->symbol,
//            automate->transitions[i]->nextState->name
//           );
//     }
//     printf("\nComplet : %d\n", isComplete(automate));

// }