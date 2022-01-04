#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

typedef struct State
{
    char *name;     // Letter
    bool isInitial; // Initial or Final
    bool isFinal;   // Initial or Final
} State;

typedef struct Transition
{
    char *symbol; // Letter
    State *leftState;
    State *nextState; // Table of destination states
} Transition;

typedef struct Automaton
{
    char *name;
    int numOfStates;
    int numOfTransitions;
    int numOfSymbols;
    State **states;
    Transition **transitions;
    char **symbols; // Letter
} Automaton;