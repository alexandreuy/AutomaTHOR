#include <stdio.h> //Input Output

#include <stdlib.h>

#include <stdbool.h> //For booleans

#include <string.h> //String

typedef struct State {
  char * name;
  bool isInitial; //Initial or Final
  bool isFinal; //Initial or Final
  int numOfTransitions;
  struct Transition ** Transitions; //Table of transitions
}
State;

typedef struct Transition {
  char * symbol; //Letter
  State * leftState;
  State * nextState; //Table of destination states
}
Transition;

typedef struct Automaton {
  char * name;
  int numOfStates;
  State ** initStates;
  State ** finalStates;
  State ** states;
  Transition ** transitions;
}
Automaton;

/*
Functions
*/

void lineBar() {
  printf("---\n");
}

void stepBar() {
  printf("---\n");
  printf("---\n");
}

void screanCleaner() {
  system("cls");
  printf("\e[1;1H\e[2J");
}

/* Automaton initializer */
Automaton * automatonInitializer() {
  Automaton * newAutomaton = (Automaton * ) malloc(sizeof(Automaton));
  newAutomaton -> numOfStates = 0;
  newAutomaton -> name = calloc(sizeof(char), 25);
  newAutomaton -> initStates = (State ** ) malloc(100 * sizeof(State * ));
  newAutomaton -> finalStates = (State ** ) malloc(100 * sizeof(State * ));
  newAutomaton -> states = (State ** ) malloc(100 * sizeof(State * ));
  newAutomaton -> transitions = (Transition ** ) malloc(100 * sizeof(Transition * ));
  return newAutomaton;
}

/* State Initializer */
State * stateInitializer() {
  State * newState = (State * ) malloc(sizeof(State));
  newState -> name = calloc(sizeof(char), 25);
  newState -> isInitial = true; //Initial or Final
  newState -> isFinal = true; //Initial or Final
  newState -> numOfTransitions = 0;
  newState -> Transitions = (Transition ** ) malloc(100 * sizeof(Transition * )); //Table of transitions
  return newState;
}

/* Transitions Initializer */
Transition * transitionsInitializer() {
  Transition * newTransition = (Transition * ) malloc(sizeof(Transition));
  newTransition -> symbol = calloc(sizeof(char), 3); //Letter
  newTransition -> leftState = stateInitializer();
  newTransition -> nextState = stateInitializer();
  return newTransition;
}

/* Transition Generator */
Automaton * transitionMaker(Automaton * newAutomaton) {
  // newTransition = transitionsInitializer();
  char * ch;
  int cpt = 0;
  bool _newTransition = false;

  printf("---\n");
  printf("Adding transitions\n");
  printf("---\n");
  printf("---\n");

  printf("List of your %d states\n", newAutomaton -> numOfStates);
  for (int i = 0; i < newAutomaton -> numOfStates; i++) {
    printf("[ %s ] ", newAutomaton -> states[i] -> name);
  }

  do {
    Transition * newTransition = (Transition * ) malloc(sizeof(Transition));
    newTransition = transitionsInitializer();
    bool next = false;
    printf("\n---\n");
    printf("Transition Symbol : ");
    scanf("%s", newTransition -> symbol);

    // printf("---\n");
    printf("[ ] . %s . [ ]\n", newTransition -> symbol);
    do {
      ch = calloc(sizeof(char), 3 * newAutomaton -> numOfStates);
      printf("From (Existing state name) : ");
      scanf("%s", ch);
      // printf("%s", ch);
      for (int i = 0; i < newAutomaton -> numOfStates; i++) {
        if (!strcmp(ch, newAutomaton -> states[i] -> name)) {
          newTransition -> leftState -> name = ch;
          printf("[ %s ] . %s . [  ]\n", newTransition -> leftState -> name, newTransition -> symbol);
          next = true;
          break;
        }
      }
      if (!next) {
        // screanCleaner();
        printf("Non Esxisting State\n");
      }
    } while (!next);

    next = false;

    do {
      ch = calloc(sizeof(char), 3 * newAutomaton -> numOfStates);
      printf("To (Existing state name) : ");
      scanf("%s", ch);
      for (int i = 0; i < newAutomaton -> numOfStates; i++) {
        if (!strcmp(ch, newAutomaton -> states[i] -> name)) {
          newTransition -> nextState -> name = ch;
          newAutomaton -> transitions[cpt] = newTransition;
          printf("[ %s ] . %s . [ %s ]\n", newTransition -> leftState -> name, newTransition -> symbol, newTransition -> nextState -> name);
          next = true;
          break;
        }
      }
      if (!next) {
        // screanCleaner();
        printf("Non Esxisting State\n");
      }
    } while (!next);

    ch = calloc(sizeof(char), 3 * newAutomaton -> numOfStates);

    printf("\nAdd a new transition (y or n) ? ");
    scanf("%s", ch);
    if (!strcmp(ch, "y")) {
      newTransition = transitionsInitializer();
      _newTransition = true;
      cpt++;
    } else {
      _newTransition = false;
    }

    printf("\n %d", cpt);

    for (int i = 0; i < cpt; i++) {
      printf("[ %s ] . %s . [ %s ]\n",
        newAutomaton -> transitions[i] -> leftState -> name,
        newAutomaton -> transitions[i] -> symbol,
        newAutomaton -> transitions[i] -> nextState -> name
      );
    }

  } while (_newTransition);

  return newAutomaton;
}

/* State Generator */
Automaton * stateMaker(Automaton * newAutomaton) {
  bool _newState = true;
  int cpt = 0;
  char * ch = calloc(sizeof(char), 25);

  printf("---\n");
  printf("States Construction\n");
  printf("---\n");
  printf("---\n");

  do {
    State * newState = stateInitializer();
    printf("[ State %d ]\n", cpt + 1);
    printf("Name / Symbol : ");
    scanf("%s", newState -> name);
    printf("Initial State (y or n) ? : ");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
      newState -> isInitial = true;
    else
      newState -> isInitial = false;
    printf("Final State (y or n) ? : ");
    scanf("%s", ch);
    if (!strcmp(ch, "y"))
      newState -> isFinal = true;
    else
      newState -> isFinal = false;

    newAutomaton -> numOfStates = cpt + 1;
    newAutomaton -> states[cpt] = newState;

    for (int i = 0; i < newAutomaton -> numOfStates; i++) {
      printf("[ %s ]", newAutomaton -> states[i] -> name);
    }

    printf("\nAdd a new state (y or n) ? ");
    scanf("%s", ch);
    if (!strcmp(ch, "y")) {
      _newState = true;
      cpt++;
    } else
      _newState = false;

  } while (_newState);
  // printf("Final cpt : %d", cpt);
  newAutomaton = transitionMaker(newAutomaton);

  return newAutomaton;
}

/* Automaton Generator */
Automaton * automatonMaker() {
  Automaton * newAutomaton = automatonInitializer();

  printf("Loading the Automaton Maker...\n");
  printf("---\n");
  printf("Automaton Informations\n");
  printf("---\n");
  printf("---\n");
  printf("Name : ");
  scanf("%s", newAutomaton -> name);
  // printf("\nYour name : %s\n", newAutomaton->name);
  printf("Number of states : ");
  scanf("%d", & newAutomaton -> numOfStates);
  // printf("Automata Num of States : %d\n", newAutomaton->numOfStates);

  newAutomaton = stateMaker(newAutomaton);

  return newAutomaton;
}

void assistedEntryMode() {
  printf("\n");
  printf("---\n");
  Automaton * newAutomaton = automatonMaker();
}

int principalMenu() {
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
  // printf("___Your personal Automaton Editor___\n");
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
  stepBar();
  scanf("%d", & choice);
  // choice = atoi(entry);
  return choice;
}

void selector(int choice) {
  switch (choice) {
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
}

int main() {

  selector(principalMenu());

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