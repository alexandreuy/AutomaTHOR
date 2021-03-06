#include "../mesFonctions.h"



/* ________________________
Transition Generator
---------------------------
---------------------------*/
Automaton *transitionMaker(Automaton *newAutomaton)
{
    // newTransition = transitionsInitializer();
    char *ch;
    int cpt = 0;
    bool _newTransition = false;
    bool symOut = false;
    int symCpt = 0;
    char *sym;

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

        sym = calloc(sizeof(char *), 1); // Letter
        sym = newTransition->symbol;

        do
        {
            if (symCpt == 0)
            {
                newAutomaton->symbols[symCpt] = sym;
                symOut = true;
                symCpt++;
            }
            else
            {
                for (int i = 0; i < symCpt; i++)
                {
                    if (!strcmp(sym, newAutomaton->symbols[i]))
                    {
                        symOut = true;
                        break;
                    }
                }
                if (!symOut)
                {
                    newAutomaton->symbols[symCpt] = sym;
                    symCpt++;
                    symOut = true;
                }
            }
            // printf("Not Inside...\n");
            // newAutomaton->symbols[i] = newTransition->symbol;
            // symCpt++;

        } while (!symOut);

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
                printf("Non Existing State\n");
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
                printf("Non Existing State\n");
            }
        } while (!next);

        ch = calloc(sizeof(char), 3 * newAutomaton->numOfStates);

        printf("\nAdd a new transition (y or n) ? ");
        scanf("%s", ch);
        if (!strcmp(ch, "y"))
        {
            newTransition = transitionsInitializer();
            _newTransition = true;
            symOut = false;
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

        printf("\n---\n");
        printf("Symbols Tab\n");
        for (int j = 0; j < symCpt; j++)
        {
            printf("%s|", newAutomaton->symbols[j]);
        }

    } while (_newTransition);

    // printf("\n");
    printf("\nYour states\n");
    for (int i = 0; i <= cpt; i++)
    {
        printf("[ %s ] . %s . [ %s ]\n",
               newAutomaton->transitions[i]->leftState->name,
               newAutomaton->transitions[i]->symbol,
               newAutomaton->transitions[i]->nextState->name);
    }

    return newAutomaton;
}
// _____________________________________________

/* ________________________
State Generator
---------------------------
---------------------------*/
Automaton *stateMaker(Automaton *newAutomaton)
{
    bool _newState = true;
    int cpt = 0;
    char *ch = calloc(sizeof(char), 25);

    printf("___________________\n");
    printf("States Construction\n");
    printf("---\n");
    // printf("---\n");

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
        }
        else
            newState->isInitial = false;
        printf("Final State (y or n) ? : ");
        scanf("%s", ch);
        if (!strcmp(ch, "y"))
        {
            newState->isFinal = true;
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
// _________________________________________________________

/* ________________________
Automaton Generator
---------------------------
---------------------------*/
Automaton *automatonMaker()
{
    Automaton *newAutomaton = automatonInitializer();

    // printf("Loading the Automaton Maker...\n");
    // printf("---\n");
    printf("Automaton Informations\n");
    // printf("---\n");
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