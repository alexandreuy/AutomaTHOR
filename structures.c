#include "headers.c"

typedef struct State
{
  char *name; //Letter
  bool isInitial; //Initial or Final
  bool isFinal; //Initial or Final
} State;

typedef struct Transition
{
  char *symbol; //Letter
  State *leftState;
  State *nextState; //Table of destination states
} Transition;

typedef struct Automaton
{
  char *name;
  int numOfStates;
  State **initStates;
  State **finalStates;
  State **states;
  Transition **transitions;
  char **symbols; //Letter
} Automaton;