#include "templates.c"

/* ________________________
Principal Menu Function
---------------------------
---------------------------*/
int principalMenu()
{
    printf("---[ FSA EDITOR ]---\n");
    printf("\n");
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

    /* Automatic DataCharge
     */
    printf("5. Test Mode\n");
    printf("________________________________\n");

    /* Quit or Reload
     */
    // printf("\nQuit (Q or q)\n");
    // printf("Reload (R or r)\n");
    // printf("________________________________\n");

    /* Your selection
     */
    printf("\n---");
    printf("\nYour selection : ");

    scanf("%d", &choice); // Getting your choice
    return choice;
}

/* ________________________
Selector
---------------------------
---------------------------*/
void selector(int choice)
{
    switch (choice)
    {
    case 1:
        system("clear");                 // clear the windows command line
        printf("Assisted Entry Mode\n"); // Print choosen mode
        assistedEntryMode();             // load the assisted mode entry function
        break;
    case 2:
        system("clear");                      // clear the windows command line
        printf("Semi-Assisted Entry Mode\n"); // Print choosen mode
        break;
    case 3:
        system("clear");             // clear the windows command line
        printf("Self-Entry Mode\n"); // Print choosen mode
        break;
    case 4:
        system("clear");              // clear the windows command line
        printf("File Import Mode\n"); // Print choosen mode
    case 5:
        // dataCharge();
        break;
    }
}