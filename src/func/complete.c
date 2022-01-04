#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../mesFonctions.h"

bool isPresent(char **tab, char *symbol, int numberOfTransitions)
{

    for (int i = 0; i < numberOfTransitions; i++)
    {
        if (*&(tab[i]) == symbol)
        {
            return true;
        }
    }

    return false;
}

int getNumberOfTransition(char **tab, int numberOfTransitions)
{
    int compteur = 0;

    for (int i = 0; i < numberOfTransitions; i++)
    {
        if (*&(tab[i]) != NULL)
        {
            compteur++;
        }
    }
    return compteur;
}

// Récupère un tableau avec les symboles de transitions sans doublons
char **getTransitionOfState(Transition **tabTransition, char *name, int numberOfTransitions)
{
    char **tab = malloc(100);

    for (int i = 0; i < numberOfTransitions; i++)
    {
        if (strcmp(tabTransition[i]->leftState->name, name) == 0 && !isPresent(tab, tabTransition[i]->symbol, numberOfTransitions))
        {

            *(&tab[i]) = (tabTransition[i]->symbol);
        }
    }

    return tab;
}

bool isComplete(Automaton *automaton)
{

    for (int i = 0; i < automaton->numOfStates; i++)
    {
        int stateTransition = getNumberOfTransition(getTransitionOfState(automaton->transitions, automaton->states[i]->name, automaton->numOfTransitions), automaton->numOfTransitions);

        if (stateTransition != automaton->numOfSymbols)
            return false;
    }

    return true;
}

char** symbolsMissing(char** tabSymbolStateTransition, int numOfTransitions , char** symbols, int numOfSymbols){

    char** tab = symbols;
    int count = 0;
    bool notFound = false;

    for(int i =0 ; i < numOfSymbols; i++){
        

    }

}

Automaton *makeItComplete(Automaton *automaton)
{
    
    char** tab = symbolsMissing(getTransitionOfState(automaton->transitions, "C", automaton->numOfTransitions), automaton->numOfTransitions , automaton->symbols, automaton->numOfSymbols);
    // printf("\n%s", tab)
    for(int i = 0 ; i < automaton->numOfStates; i++){
        // char** tab = symbolsMissing(getTransitionOfState(automaton->transitions, automaton->states[i]->name, automaton->numOfTransitions), automaton->numOfTransitions , automaton->symbols, automaton->numOfSymbols);

    }
    

}

void main()
{

    makeItComplete(dataCharge());
    // printf("\nComplet : %d\n", isComplete(dataCharge()));

}