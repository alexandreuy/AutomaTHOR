#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../mesFonctions.h"

void assistedEntryMode()
{
  printf("\n");
  printf("---\n");
  Automaton *newAutomaton = automatonMaker();
}

// Transitions Positions test
bool isInAFinalTransition(Automaton *newAutomaton, char *yourWord)
{
  bool test = 0;
  int cpt = (sizeof(newAutomaton->transitions) / sizeof(newAutomaton->transitions[0]));
  for (int i = 0; i <= cpt; i++)
  {
    // printf("\nValue of I : %d", i);
    // printf("\nYour Word : %s", yourWord);
    // printf("\nIn table : %s", newAutomaton->transitions[i]->symbol);
    // printf("\nFinal State : %d", newAutomaton->transitions[i]->nextState->isFinal);
    if (newAutomaton->transitions[i]->nextState->isFinal)
    {
      // printf("\nGo !!!\n");
      if (!strcmp(newAutomaton->transitions[i]->symbol, yourWord))
      {
        printf("\nIs in a final transition\n");
        test = 1;
      }
      else
      {
        printf("\nIs not in a final transition\n");
        // return false;
        // printf("\nValeur de la différence : %d", strcmp(yourWord, newAutomaton->transitions[i]->symbol));
      }
    }
    else
    {
      // printf("\nSorry !!!\n");
    }
  }
  return test;
}

bool isInAnInitialTransition(Automaton *newAutomaton, char *yourWord)
{
  bool test = 0;
  int cpt = (sizeof(newAutomaton->transitions) / sizeof(newAutomaton->transitions[0]));

  for (int i = 0; i <= cpt; i++)
  {
    // printf("\nValue of I : %d", i);
    // printf("\nYour Word : %s", yourWord);
    // printf("\nIn table : %s", newAutomaton->transitions[i]->symbol);
    if (newAutomaton->transitions[i]->leftState->isInitial)
    {
      // printf("\nGo !!!\n");
      if (!strcmp(newAutomaton->transitions[i]->symbol, yourWord))
      {
        printf("\nIs in an initial transition\n");
        test = 1;
      }
      else
      {
        printf("\nIs not in an initial transition\n");
        // return false;
        // printf("\nValeur de la différence : %d", strcmp(yourWord, newAutomaton->transitions[i]->symbol));
      }
    }
    else
    {
      // printf("\nSorry !!!\n");
    }
  }
  return test;
}

void recByAEF(Automaton *newAutomaton, char *word)
{
  State *stateReader = stateInitializer();
  Transition *transitionReader = transitionsInitializer();
  // bool goAhead = false;
  // int cpt = sizeof(newAutomaton->initStates) / sizeof(long);
  // int stateCpt = sizeof(newAutomaton->initStates) / sizeof(long);
  // int trCpt = sizeof(newAutomaton->transitions) / sizeof(long);

  int trCpt;

  char *myWord = calloc(sizeof(char), 25);
  // myWord = "abc";
  printf("Enter your word, please\n");
  printf("---\n");
  scanf("%s", myWord);
  printf("______________\n");

  // trCpt = (sizeof(myWord) / sizeof(long)) + 1;
  trCpt = strlen(myWord);

  printf("Your Word : %s \n", myWord);
  // printf("%d\n", trCpt);
  printf("\n");
  printf("\n");

  // printf("%s\n", &myWord[0]);
  // printf("%s\n", myWord);
  // printf("%c\n", myWord[trCpt - 3]);
  isInAFinalTransition(newAutomaton, &myWord[trCpt - 1]);
  isInAnInitialTransition(newAutomaton, &myWord[trCpt - trCpt]);
}

void questionsAnswer(Automaton *newAutomaton)
{
  // screanCleaner();
  printf("_________________\n");
  printf("Questions Answer \n");
  printf("-----------------\n");
  printf("3. Word Recognition by a FSA\n");
  recByAEF(newAutomaton, "abc");
}