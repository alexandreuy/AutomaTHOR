#include <stdio.h> //Input Output
#include <stdlib.h>
#include <stdbool.h> //For booleans
#include <string.h> //String

// #include "utils.c"
//___________________

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