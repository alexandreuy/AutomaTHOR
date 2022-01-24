    #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../mesFonctions.h"


bool isUnitaryCircular(Automaton *automaton){
    
    char** tab = initialSate(automaton->states, automaton->numOfStates);

    int length = getSizeOfTab(tab);

    for(int i =0; i < length; i++){
        // printf("\nStates Initial : %s\n", *&(tab[i]));
        for(int j = 0; j < automaton->numOfTransitions;j++){
            // printf("\n%s\n", *&(automaton->transitions[j]->nextState->name));
            if(*&(tab[i]) == *&(automaton->transitions[j]->nextState->name))
                return false;
        }

    }
    return true;

}


// void main()
// {
//     printf("\n%d\n", isUnitaryCircular(dataCharge()));
// }