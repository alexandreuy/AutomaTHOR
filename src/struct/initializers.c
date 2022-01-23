#include "../mesFonctions.h"

/* Automaton initializer */
Automaton *automatonInitializer()
{
    Automaton *newAutomaton = (Automaton *)malloc(sizeof(Automaton));
    newAutomaton->numOfStates = 0;
    newAutomaton->numOfTransitions = 0;
    newAutomaton->numOfSymbols = 0;
    newAutomaton->name = calloc(sizeof(char), 25);
    newAutomaton->states = (State **)malloc(100 * sizeof(State *));
    newAutomaton->transitions = (Transition **)malloc(100 * sizeof(Transition *));
    // newAutomaton->symbols = calloc(sizeof(char *), 100);
    newAutomaton->symbols = malloc(100 * sizeof(char *));
    return newAutomaton;
}

/* State Initializer */
State *stateInitializer()
{
    State *newState = (State *)malloc(sizeof(State));
    newState->name = calloc(sizeof(char *), 25); // Last modif
    newState->isInitial = true;                  // Initial or Final
    newState->isFinal = true;                    // Initial or Final
    return newState;
}

/* Transitions Initializer */
Transition *transitionsInitializer()
{
    Transition *newTransition = (Transition *)malloc(sizeof(Transition));
    newTransition->symbol = calloc(sizeof(char *), 3); // Letter
    newTransition->leftState = stateInitializer();
    newTransition->nextState = stateInitializer();
    return newTransition;
}
