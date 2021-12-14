#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //For booleans

typedef struct State
{
  char symbol;
  bool isInitial; //Initial or Final
  bool isFinal; //Initial or Final
  int numOfTransitions;
  struct Transition *Transitions; //Table of transitions
}State;

typedef struct Transition
{
  char symbol; //Letter
  State *nextStates; //Table of destination states
}Transition;

typedef struct Automaton
{
  int numOfStates;
  State *initStates;
  State *finalStates;
  State *states;
}Automaton;



int main()
{

  int entry;
  int choice;
  
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

  scanf("%d", entry);
  choice = entry;

    printf("Test : %d\n", choice);

//   switch (choice)
//   {
//    case 1:
//       printf("Case 1\n");
//     //   stateMaker(automatonMaker());
//       break;
//     case 2:
//       /* code */
//       break;
//     case 3:
//       /* code */
//       break;
//     case 4:
//       /* code */
//       break;
//   }
  




	return 0;
}