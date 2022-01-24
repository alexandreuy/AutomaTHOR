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
int appartient();
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
Automaton *transitionMaker(Automaton *newAutomaton);
Automaton *stateMaker(Automaton *newAutomaton);
Automaton *automatonMaker();

// Template
Automaton *dataCharge();

// File -- Still working on it
Automaton* modifier(Automaton* newAutomaton);
void changename(Automaton* newAutomaton);
void modifnbetats(Automaton *newAutomaton);
void modifnbtrans(Automaton *newAutomaton);
void modifnbsymbol(Automaton *newAutomaton);
void modifstates(Automaton *newAutomaton);
void affichagetransition(Automaton *newAutomate);
void changetransition(Automaton *newAutomate);
Automaton *importcsv();
void Suiteprocess(Automaton *newAutomaton);
void affectationstate(Automaton *newAutomaton, char* listetat, int numbinistate, char *listinitstate, int numbfinalstate, char *listfinalstate);
void affichageteststates(Automaton *newAutomaton);
void affectationsymbol(Automaton *newAutomaton, char* listessymbole);
void affectotransition(Automaton *newAutomaton,char *token, int numbinitstate, int numbfinalstate, char * listfinalstate, char* listinitstate);
void createstatetotransition(Automaton * newAutomaton, Transition *newTransition, char *namestate, int choix , int numbinitstate, int numbfinalstate, char * listfinalstate, char* listinitstate);



// Enter an AEF
void assistedEntryMode();
bool isInAFinalTransition(Automaton *newAutomaton, char *yourWord);
bool isInAnInitialTransition(Automaton *newAutomaton, char *yourWord);
void recByAEF(Automaton *newAutomaton, char *word);
void questionsAnswer(Automaton *newAutomaton);

// General function
bool isPresent(char **tab, char* symbol, int numberOfTransitions);
int getNumberOfTransitionFinal(char **tab, int numberOfTransitions);
int getSizeOfTab(char **tab);
char** initialSate(State** states, int numOfStates);
char **getTransitionOfState(Transition **tabTransition, char *name, int numberOfTransitions);
int numberOfInitialState(Automaton *automaton);
int getPositionInitState(State** states, int numOfStates);

// complete verification

bool isComplete(Automaton *automaton);

// Make it complete
char** symbolsMissing(char** tabSymbolStateTransition, char** symbols, int numOfSymbols);
int isPStateExist(Automaton *automaton);
Automaton *makeItComplete(Automaton *automaton);


// determinist verification
bool doublonVerification(Transition **tabTransition, char *name, int numberOfTransitions);
bool isDeterminist(Automaton *automaton);

// Make it determinist -- Not working yet
Automaton* makeItDeterminist(Automaton* automate);

// Circular Unitary verification
bool isUnitaryCircular(Automaton *automaton);


// Regex
int saveInAFile(char *regEx);
char *editARegEx(char *regExToEdit);
void regExEdSelector(char *regEx, int choice);
int regExEdMenu(char *regEx);
int editor(char *regEx);
int regExMenu();
bool parityMatch(char *regEx, char bef, char aft);
bool isCorrect(char *regEx);
int manualMode();
int fileImportMode();
void MenuSelector(int choice);
