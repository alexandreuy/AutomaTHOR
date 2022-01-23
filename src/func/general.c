#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../mesFonctions.h"

// Get a tab with all the initialState
char** initialSate(State** states, int numOfStates){
    int i =0;
    int cpt = 0;
    char** state = malloc(sizeof(char*));

    while(i < numOfStates){
        if(states[i]->isInitial){
            state[cpt] = states[i]->name;
            cpt++;
        }
        i++;
    }
    *&(state[cpt]) = NULL;
    return state;
}

// Get the number of initial state of an automate
int numberOfInitialState(Automaton *automaton)
{
    int count = 0;

    for (int i = 0; i < automaton->numOfStates; i++)
    {
        if(automaton->states[i]->isInitial) count+=1;
         
    }
    return count;
}

// verify if an symbol already exists in a tab
bool isPresent(char **tab, char *symbol, int length)
{

    for (int i = 0; i < length; i++)
    {
        if (*&(tab[i]) == symbol)
        {
            return true;
        }
    }

    return false;
}


// get the size of a tab
int getSizeOfTab(char **tab)
{
    int i =0;
    int compteur =0;
    while(*&(tab[i])!= NULL){
        compteur++;
        i++;
    }
    return compteur;
}

// get a tab with symbols transition of a state without duplicate symbols
char **getTransitionOfState(Transition **tabTransition, char *name, int numberOfTransitions)
{
    char **tab = malloc(100);
    int i = 0;
    int cpt =0;
    while(i < numberOfTransitions){
         if (strcmp(tabTransition[i]->leftState->name, name) == 0 && !isPresent(tab, tabTransition[i]->symbol, numberOfTransitions))
        {  
            *(&tab[cpt]) = (tabTransition[i]->symbol); 
            cpt++;   
        }
        i++; 
    }

    *(&tab[cpt]) = NULL;
    return tab;
}