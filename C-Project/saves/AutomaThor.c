#include <stdio.h> //Input Output
#include <stdlib.h>
#include <stdbool.h> //For booleans
#include <string.h> //String

typedef struct State
{
  char name[100];
  bool isInitial; //Initial or Final
  bool isFinal; //Initial or Final
  int numOfTransitions;
  struct Transition *Transitions[100]; //Table of transitions
}State;

typedef struct Transition
{
  char symbol[100]; //Letter
  State *nextStates[100]; //Table of destination states
}Transition;

typedef struct Automaton
{
  int numOfStates;
  State *initStates[100];
  State *finalStates[100];
  State *states[100];
  char name[100];
}Automaton;

/*
Functions
*/

/* Transition Generator */
Automaton* transitionMaker(Automaton* newAutomaton)
{
  Transition* newTransition = (Transition*)malloc(sizeof(Transition));
  int n;
  char ch[100];

  printf("---\n");
  printf("Adding transitions\n");
  printf("---\n");
  printf("---\n");

  printf("List of your states\n");
  printf("%d\n", newAutomaton->numOfStates);
  
  printf("---\n");
  printf("---\n");
  printf("Adding transitions between states\n");

  return newAutomaton;
}

/* State Generator */
Automaton* stateMaker(Automaton* newAutomaton)
{
  bool _newState;
  char ch[100];
  int cpt = 0;

  printf("---\n");
  printf("States Construction\n");
  printf("---\n");
  printf("---\n");

  do
  {
    State* newState = (State*)malloc(sizeof(State));
    printf("[ State %d ]\n", cpt+1);
    printf("Name / Symbol : ");
    scanf("%s", newState->name);
    printf("Initial State (y or n) ? : ");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
      newState->isInitial = true;
    else
      newState->isInitial = false;
    printf("Final State (y or n) ? : ");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
      newState->isFinal = true;
    else
      newState->isFinal = false;
    
    newAutomaton->numOfStates = cpt+1; 
    newAutomaton->states[cpt] = newState;
    // return newAutomaton;
    // printf("[ %s ]\n", newAutomaton->states[cpt]);
    // printf("Votre indice %d comporte: %s \n", cpt, newAutomaton->states[cpt]->name);
    // for (int i = 0; i < newAutomaton->numOfStates; i++)
    // {
    //   // printf("[ %p ]\n", (newAutomaton->states)+i); // Good
    //   newAutomaton->states[i] = newState;
    //   // printf("[ %s ]\n", &(*(newAutomaton->states))+i);
    // }
  
    for (int i = 0; i < newAutomaton->numOfStates; i++)
    {
      // printf("[ %p ]\n", (newAutomaton->states)+i); // Good
      printf("[ %s ]\n", newAutomaton->states[i]->name);
    }
    printf("Add a new state (y or n) ?\n");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
    {
      _newState = true;
      cpt++;
    }
    else
      _newState = false;
    // printf("Number of transitions : ");
    // scanf("%d", &newState->numOfTransitions);
    // printf("State Symbol: %s\n", newState->symbol);
    // printf("Is Initial : %d", newState->isInitial);
    // printf("Is Final : %d", newState->isFinal);
    // printf("Num Of Transitions : %d", newState->numOfTransitions);
  } while (_newState);
  // printf("Final cpt : %d", cpt);
  newAutomaton = transitionMaker(newAutomaton);

  return newAutomaton;
}

/* Automaton Generator */
Automaton* automatonMaker()
{
  Automaton* newAutomaton = (Automaton*)malloc(sizeof(Automaton));
  int n;
  char ch[100];
  printf("Loading the Automaton Maker...\n");
  printf("---\n");
  printf("Automaton Informations\n");
  printf("---\n");
  printf("---\n");
  printf("Name : ");
  scanf("%s", newAutomaton->name);
  printf("Number of states : ");
  scanf("%d", &newAutomaton->numOfStates);

  newAutomaton = stateMaker(newAutomaton);
  // printf("Automata Name : %s \n", newAutomaton->name);
  // printf("Automata Num of States : %d", newAutomaton->numOfStates);
  return newAutomaton;
}

void assistedEntryMode()
{
  printf("\n");
  printf("---\n");
  Automaton* newAutomaton = automatonMaker();
}




int main()
{
  system("cls");
  printf("\e[1;1H\e[2J");
  int choice;

  // printf("\n");
  // printf("\n");
  // //printf("    __________________________________________________");
  // //printf("    --------------------------------------------------");
	// printf("W E L C O M E  T O  T H E  A U T O M A T H O R\n");
  // //printf("    --------------------------------------------------");
  // //printf("    __________________________________________________");
  // printf("\n");
  // printf("\n");
  // printf("___Youpersonal Automaton Editor___\n");
  // printf("\n");

  // printf("!!Please follow the instructions below !!!\n");
  // printf("\n");
  
  printf("Please select an entry model for you automate\n");
  printf("\n");
  printf("1. Assisted Entry Mode\n");
  printf("________________________________\n");
  printf("2. Semi-Assisted Entry Mode\n");
  printf("________________________________\n");
  printf("3. Self-Entry Mode\n");
  printf("________________________________\n");
  printf("4. File Import Mode\n");
  printf("________________________________\n");
  printf("\n");
  printf("-----\n");

  scanf("%d", &choice);
  // choice = atoi(entry);

  switch (choice)
  {
    case 1:
      system("cls");
      printf("Assisted Entry Mode\n");
      // stateMaker(automatonMaker());
      assistedEntryMode();
      break;
    case 2:
      /* code */
      break;
    case 3:
      /* code */
      break;
    case 4:
      /* code */
      break;
  }
  

	return 0;
}


/*      





                                                              * *
                                                            * * *
                                                          * * *  
                                                      -------
                                                   _________
                                                 _________
                                               _________
                                             _________
            _______                        _________ 
          * * * * *                      _________
        * * *       *                  _________
      * * * * *       *              _________
    * * * * * * *       *          _________
  * * * * * * * * *       *      _________
  * * * * * * * * * *       *  _________
  * * * * * * * * * * *   * * * * * * *
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