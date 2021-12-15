#include <stdbool.h> //For booleans 
#include "struct/structures.c"

// Launcher
void launchFunction(int choice);
void launchAlphabetFunction(int choice);
void launchAEFFunction(int choice);

// Navigation Menu

int principal_displayMenu();
int alphabet_displayMenu();
int aef_displayMenu();

/** First Exercice **/
char *puis();
bool vide();
char* concat();
char *miroir(); 
bool estFini();

// Header 
void lineBar();
void stepBar();
void screanCleaner();


// Initializers
Automaton* automatonInitializer();
State* stateInitializer();
Transition *transitionsInitializer();


// Generators
void fillSymbolLib(Automaton *newAutomaton, char *sym);
Automaton *transitionMaker(Automaton *newAutomaton);
Automaton *stateMaker(Automaton *newAutomaton);
Automaton *automatonMaker();

// Templates
Automaton *dataCharge();

// Enter an AEF
void assistedEntryMode();
bool isInAFinalTransition(Automaton *newAutomaton, char *yourWord);
bool isInAnInitialTransition(Automaton *newAutomaton, char *yourWord);
void recByAEF(Automaton *newAutomaton, char *word);
void questionsAnswer(Automaton *newAutomaton);




