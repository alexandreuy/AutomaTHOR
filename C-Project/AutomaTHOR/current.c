#include <stdio.h> //Input Output

#include <stdlib.h>

#include <stdbool.h> //For booleans

#include <string.h> //String

typedef struct State
{
  char *name;
  bool isInitial; //Initial or Final
  bool isFinal;   //Initial or Final
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

/*
Functions
*/

void lineBar()
{
  printf("---\n");
}

void stepBar()
{
  printf("---\n");
  printf("---\n");
}

void screanCleaner()
{
  system("cls");
  printf("\e[1;1H\e[2J");
}

/* Automaton initializer */
Automaton *automatonInitializer()
{
  Automaton *newAutomaton = (Automaton *)malloc(sizeof(Automaton));
  newAutomaton->numOfStates = 0;
  newAutomaton->name = calloc(sizeof(char), 25);
  newAutomaton->initStates = (State **)malloc(100 * sizeof(State *));
  newAutomaton->finalStates = (State **)malloc(100 * sizeof(State *));
  newAutomaton->states = (State **)malloc(100 * sizeof(State *));
  newAutomaton->transitions = (Transition **)malloc(100 * sizeof(Transition *));
  newAutomaton->symbols = calloc(sizeof(char *), 25);
  return newAutomaton;
}

/* State Initializer */
State *stateInitializer()
{
  State *newState = (State *)malloc(sizeof(State));
  newState->name = calloc(sizeof(char), 25);
  newState->isInitial = true; //Initial or Final
  newState->isFinal = true;   //Initial or Final
  return newState;
}

/* Transitions Initializer */
Transition *transitionsInitializer()
{
  Transition *newTransition = (Transition *)malloc(sizeof(Transition));
  newTransition->symbol = calloc(sizeof(char), 3); //Letter
  newTransition->leftState = stateInitializer();
  newTransition->nextState = stateInitializer();
  return newTransition;
}

/* Transition Generator */
Automaton *transitionMaker(Automaton *newAutomaton)
{
  // newTransition = transitionsInitializer();
  char *ch;
  int cpt = 0;
  bool _newTransition = false;

  printf("---\n");
  printf("Adding transitions\n");
  printf("---\n");
  printf("---\n");

  printf("List of your %d states\n", newAutomaton->numOfStates);
  for (int i = 0; i < newAutomaton->numOfStates; i++)
  {
    printf("[ %s ] ", newAutomaton->states[i]->name);
  }

  do
  {
    Transition *newTransition = (Transition *)malloc(sizeof(Transition));
    newTransition = transitionsInitializer();
    bool next = false;
    printf("\n---\n");
    printf("Transition Symbol : ");
    scanf("%s", newTransition->symbol);

    // %[^\n]%
    // printf("---\n");
    printf("[ ] . %s . [ ]\n", newTransition->symbol);
    do
    {
      ch = calloc(sizeof(char), 3 * newAutomaton->numOfStates);
      printf("From (Existing state name) : ");
      scanf("%s", ch);
      // printf("%s", ch);
      for (int i = 0; i < newAutomaton->numOfStates; i++)
      {
        if (!strcmp(ch, newAutomaton->states[i]->name))
        {
          newTransition->leftState->name = ch;
          printf("[ %s ] . %s . [  ]\n", newTransition->leftState->name, newTransition->symbol);
          next = true;
          break;
        }
      }
      if (!next)
      {
        // screanCleaner();
        printf("Non Esxisting State\n");
      }
    } while (!next);

    next = false;

    do
    {
      ch = calloc(sizeof(char), 3 * newAutomaton->numOfStates);
      printf("To (Existing state name) : ");
      scanf("%s", ch);
      for (int i = 0; i < newAutomaton->numOfStates; i++)
      {
        if (!strcmp(ch, newAutomaton->states[i]->name))
        {
          newTransition->nextState->name = ch;
          newAutomaton->transitions[cpt] = newTransition;
          printf("[ %s ] . %s . [ %s ]\n", newTransition->leftState->name, newTransition->symbol, newTransition->nextState->name);
          next = true;
          break;
        }
      }
      if (!next)
      {
        // screanCleaner();
        printf("Non Esxisting State\n");
      }
    } while (!next);

    ch = calloc(sizeof(char), 3 * newAutomaton->numOfStates);

    printf("\nAdd a new transition (y or n) ? ");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
    {
      newTransition = transitionsInitializer();
      _newTransition = true;
      cpt++;
    }
    else
    {
      _newTransition = false;
    }

    // printf("\n %d", cpt);

    for (int i = 0; i < cpt; i++)
    {
      printf("[ %s ] . %s . [ %s ]\n",
             newAutomaton->transitions[i]->leftState->name,
             newAutomaton->transitions[i]->symbol,
             newAutomaton->transitions[i]->nextState->name);
    }

  } while (_newTransition);

  for (int i = 0; i <= cpt; i++)
  {
    printf("[ %s ] . %s . [ %s ]\n",
           newAutomaton->transitions[i]->leftState->name,
           newAutomaton->transitions[i]->symbol,
           newAutomaton->transitions[i]->nextState->name);
  }

  return newAutomaton;
}

/* State Generator */
Automaton *stateMaker(Automaton *newAutomaton)
{
  bool _newState = true;
  int cpt = 0;
  char *ch = calloc(sizeof(char), 25);

  printf("---\n");
  printf("States Construction\n");
  printf("---\n");
  printf("---\n");

  do
  {
    State *newState = stateInitializer();
    printf("[ State %d ]\n", cpt + 1);
    printf("Name / Symbol : ");
    scanf("%s", newState->name);
    printf("Initial State (y or n) ? : ");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
    {
      newState->isInitial = true;
      newAutomaton->initStates[cpt] = newState;
    }
    else
      newState->isInitial = false;
    printf("Final State (y or n) ? : ");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
    {
      newState->isFinal = true;
      newAutomaton->finalStates[cpt] = newState;
    }
    else
      newState->isFinal = false;

    newAutomaton->numOfStates = cpt + 1;
    newAutomaton->states[cpt] = newState;

    for (int i = 0; i < newAutomaton->numOfStates; i++)
    {
      printf("[ %s ]", newAutomaton->states[i]->name);
    }

    printf("\nAdd a new state (y or n) ? ");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
    {
      _newState = true;
      cpt++;
    }
    else
      _newState = false;

  } while (_newState);
  // printf("Final cpt : %d", cpt);
  newAutomaton = transitionMaker(newAutomaton);

  return newAutomaton;
}

/* Automaton Generator */
Automaton *automatonMaker()
{
  Automaton *newAutomaton = automatonInitializer();

  printf("Loading the Automaton Maker...\n");
  printf("---\n");
  printf("Automaton Informations\n");
  printf("---\n");
  printf("---\n");
  printf("Name : ");
  scanf("%s", newAutomaton->name);
  // printf("\nYour name : %s\n", newAutomaton->name);
  printf("Number of states : ");
  scanf("%d", &newAutomaton->numOfStates);
  // printf("Automata Num of States : %d\n", newAutomaton->numOfStates);

  newAutomaton = stateMaker(newAutomaton);

  return newAutomaton;
}

void assistedEntryMode()
{
  printf("---\n");
  Automaton *newAutomaton = automatonMaker();
}

// ________________________________________________________
// DAta Chargement

bool isInAFinalTransition(Automaton *newAutomaton, char *yourWord)
{
  for (size_t i = 0; i < sizeof(newAutomaton->transitions); i++)
  {
    if (!strcmp(yourWord, newAutomaton->transitions[i]->symbol))
    {
      printf("Is in a final transition\n");
      break;
      return true;
    }
  }
  printf("Is not in a final transition\n");
  return false;
}

bool isInAnInitialTransition(Automaton *newAutomaton, char *yourWord)
{
  for (int i = 0; i < sizeof(newAutomaton->transitions); i++)
  {
    if (!strcmp(yourWord, newAutomaton->transitions[i]->leftState->name))
    {
      printf("Is in an initial transition\n");
      break;
      return true;
    }
  }
  printf("Is not in an initial transition\n");
  return false;
}

void recByAEF(Automaton *newAutomaton, char *word)
{
  State *stateReader = stateInitializer();
  Transition *transitionReader = transitionsInitializer();
  bool goAhead = false;
  int cpt = sizeof(newAutomaton->initStates) / sizeof(long);
  int stateCpt = sizeof(newAutomaton->initStates) / sizeof(long);
  int trCpt = sizeof(newAutomaton->transitions) / sizeof(long);

  char *myWord = calloc(sizeof(char), 25);
  // myWord = "abc";
  printf("Enter your word, please\n");
  printf("---\n");
  scanf("%ms", &myWord);
  printf("______________\n");

  printf("Your Word : %s \n", myWord);
  printf("\n");
  printf("\n");
  printf("\n");

  // We check the presence in a final state transition
  isInAFinalTransition(newAutomaton, myWord);
}

void questionsAnswer(Automaton *newAutomaton)
{
  screanCleaner();
  printf("_________________\n");
  printf("Questions Answer \n");
  printf("-----------------\n");
  printf("3. Word Recognition by a FSA\n");
  recByAEF(newAutomaton, "abc");
}

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
  newState->isFinal = false;
  newAutomaton->states[2] = newState;

  newTransition->nextState = newState;
  newAutomaton->transitions[1] = newTransition;

  // printf("Transitions number : %ld\n", (sizeof(newAutomaton->transitions)/sizeof(long))+1);
  int cpt = (sizeof(newAutomaton->transitions) / sizeof(long)) + 1;
  for (int i = 0; i < cpt; i++)
  {
    printf("[ %s ] . %s . [ %s ]\n",
           newAutomaton->transitions[i]->leftState->name,
           newAutomaton->transitions[i]->symbol,
           newAutomaton->transitions[i]->nextState->name);
  }

  questionsAnswer(newAutomaton);

  return newAutomaton;
}

/* ________________________
Principal Menu Function
--------------------------- 
---------------------------*/
int principalMenu()
{
  /* Welcome Screen with a menu */
  int choice; // To choose a menu option

  printf("Please select an entry model for you automate\n");
  printf("\n");

  /* Full assisted entry mode. 
    You'll be guide through questions for all steps.
  */
  printf("1. Assisted Entry Mode\n");
  printf("________________________________\n");
  /* Semi assisted entry mode. 
    You'll be asked to enter a specific data format step by step.
  */
  printf("2. Semi-Assisted Entry Mode\n");
  printf("________________________________\n");
  /* Self entry mode. 
    You'll be asked to enter in "only one line" with a specific format.
  */
  printf("3. Self-Entry Mode\n");
  printf("________________________________\n");
  /* Semi assisted entry mode. 
    You'll be asked to give a file name (absolute path).
  */
  printf("4. File Import Mode\n");
  printf("________________________________\n");

  /* Automatic Filling in
  */
  printf("0. Fill in\n");
  printf("________________________________\n");

  stepBar();
  scanf("%d", &choice); // Getting your choice
  return choice;
}

void selector(int choice)
{
  switch (choice)
  {
  case 1:
    system("cls");                   // clear the windows command line
    printf("Assisted Entry Mode\n"); // Print choosen mode
    assistedEntryMode();             // load the assisted mode entry function
    break;
  case 2:
    /* code */
    break;
  case 3:
    /* code */
    break;
  case 4:
    /* code */
  case 0:
    /* code */
    dataCharge();
    break;
  }
}

/* ________________________
Main Function
--------------------------- 
---------------------------*/
int main()
{

  selector(principalMenu());

  return 0;
}

// A-a-A-b-c
// a*ba
// ab
// aab

/*      
                                                              * *
                                                            * * *
                                                          * * *  
                                                      -------
                                                   _________
                                                 _________
                                               _________
                                             _________
                                           _________ 
          __________                     _________
        * * * * * * *                  _________
      * * * * *       *              _________
    * * * * * * *       *          _________
  * * * * * * * * *       *      _________
  * * * * * * * * * *       *  _________
  * * * * * * * * * * * * * * * * * * *
    * * * * * * * * * * * * * * * * * 
      * * * * * * * * * * * * * * * *
        * * * * * * * * * * * * * * * *
          * * * * * * * * * * *        *
          * * * * * * * * * * * *        *
          * * * * * * * * * * * * *        *
            * * * * * * * * * * * * *        *
              * * * * * * * * * * * * * * * * *
                    * * * * * * * *          *
                      * * * * * *          *
                        * * * *          *  
           ---------------* * *--------* ------------------- 
          ______________________________________________    







ctrl + Maj + ù

                          
{* * * * *}
{_________}
{---------}

*/