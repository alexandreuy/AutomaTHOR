#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../mesFonctions.h"

Automaton *dataCharge()
{
  Automaton *newAutomaton = automatonInitializer();
  State *newState = stateInitializer();
  Transition *newTransition = transitionsInitializer();

  printf("Data Chargement...\n");
  printf("------------------\n");
  newAutomaton->name = "test";
  printf("Default name : %s \n", newAutomaton->name);

  // State A
  newState->name = "A";
  printf("New State : %s \n", newState->name);
  newState->isInitial = true;
  newState->isFinal = false;
  newAutomaton->states[0] = newState;

  // Transition Symbol a
  newTransition->symbol = "a";
  newTransition->leftState = newState;

  // State B
  newState = stateInitializer();
  newState->name = "B";
  printf("New State : %s \n", newState->name);
  newState->isInitial = false;
  newState->isFinal = false;
  newAutomaton->states[1] = newState;

  // Push
  newTransition->nextState = newState;
  newAutomaton->transitions[0] = newTransition;

  //------------------------------

  // Transition Symbol b
  newTransition = transitionsInitializer();
  newTransition->symbol = "b";
  newTransition->leftState = newState;

  // State C
  newState = stateInitializer();
  newState->name = "C";
  printf("New State : %s \n", newState->name);
  newState->isInitial = false;
  newState->isFinal = true;
  newAutomaton->states[2] = newState;

  newTransition->nextState = newState;
  newAutomaton->transitions[1] = newTransition;

  // Transition Symbol c
  newTransition = transitionsInitializer();
  newTransition->symbol = "c";
  newTransition->leftState = newState;

  newTransition->nextState = newState;
  newAutomaton->transitions[2] = newTransition;

  // Transition Symbol z
  newTransition = transitionsInitializer();
  newTransition->symbol = "z";
  newTransition->leftState = newState;

  newTransition->nextState = newState;
  newAutomaton->transitions[3] = newTransition;

  // Transition Symbol c
  newTransition = transitionsInitializer();
  newTransition->symbol = "c";
  newTransition->leftState = newState;

  // State D
  newState = stateInitializer();
  newState->name = "D";
  printf("New State : %s \n", newState->name);
  newState->isInitial = false;
  newState->isFinal = true;
  newAutomaton->states[3] = newState;

  newTransition->nextState = newState;
  newAutomaton->transitions[4] = newTransition;

  // Transition Symbol c
  newTransition = transitionsInitializer();
  newTransition->symbol = "d";
  newTransition->leftState = newState;

  // State E
  newState = stateInitializer();
  newState->name = "E";
  printf("New State : %s \n", newState->name);
  newState->isInitial = false;
  newState->isFinal = true;
  newAutomaton->states[4] = newState;

  newTransition->nextState = newState;
  newAutomaton->transitions[5] = newTransition;

  newAutomaton->numOfStates = 5;
  newAutomaton->numOfTransitions =6;
  newAutomaton->numOfSymbols = 5;

  newAutomaton->symbols[0] = "a";
  newAutomaton->symbols[1] = "b";
  newAutomaton->symbols[2] = "c";
  newAutomaton->symbols[3] = "d";
  newAutomaton->symbols[4] = "z";

  //  printf("Transitions number : %ld\n", (sizeof(newAutomaton->transitions)/sizeof(long))+1);
  int cpt = (sizeof(newAutomaton->transitions) / sizeof(long)) + 1;
  // for (int i = 0; i < 6; i++)
  // {
  //   printf("\n[ %s ] . %s . [ %s ]\n[ %d ]-[ %d ] | [ %d ]-[ %d ]",
  //          newAutomaton->transitions[i]->leftState->name,
  //          newAutomaton->transitions[i]->symbol,
  //          newAutomaton->transitions[i]->nextState->name,
  //          newAutomaton->transitions[i]->leftState->isInitial,
  //          newAutomaton->transitions[i]->leftState->isFinal,
  //          newAutomaton->transitions[i]->nextState->isInitial,
  //          newAutomaton->transitions[i]->nextState->isFinal
  //         );
  // }

  for (int i = 0; i < newAutomaton->numOfTransitions ; i++)
  {
    printf("\n[ %s ] . %s . [ %s ]",
           newAutomaton->transitions[i]->leftState->name,
           newAutomaton->transitions[i]->symbol,
           newAutomaton->transitions[i]->nextState->name
          );
  }

  //  printf("\n%ld",(sizeof(newAutomaton->transitions) / sizeof(long)) + 1 );

  //  questionsAnswer(newAutomaton);

  return newAutomaton;
}