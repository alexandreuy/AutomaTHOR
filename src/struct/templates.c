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

  // printf("Transitions number : %ld\n", (sizeof(newAutomaton->transitions)/sizeof(long))+1);
  int cpt = (sizeof(newAutomaton->transitions) / sizeof(long)) + 1;
  // for (int i = 0; i < cpt; i++)
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

  for (int i = 0; i < cpt; i++)
  {
    printf("\n[ %s ] . %s . [ %s ]",
           newAutomaton->transitions[i]->leftState->name,
           newAutomaton->transitions[i]->symbol,
           newAutomaton->transitions[i]->nextState->name
          );
  }

  printf("\n%ld",(sizeof(newAutomaton->transitions) / sizeof(long)) + 1 );

  questionsAnswer(newAutomaton);

  return newAutomaton;
}