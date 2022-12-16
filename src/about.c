#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void about() {
  system("cls");
  while (1)
  {
  printf("|- - - - - - - - - - - - - - - - - - - -| ABOUT THIS PROGRAM |- - - - - - - - - - - - - - - - - - - -|\n\n");
  printf("Program Name : Simple Cashier Machine Program\n");
  printf("Author       : Yanuar Eka Pramudya (5025221049)\n"); 
  printf("Repository   : \n\n");

  printf("A simple cashier machine program made in C language by applying modular programming\n");
  printf("and binary data files to fulfill the final project of the basic programming course\n");

  printf("\n\nPress 0 to exit menu ");
    int a;
    scanf("%d",&a);
    if (a==0) {
      system("cls");
      break;
    }
    else {
      printf("Wrong Input!");
      about();
    }
  }
  
}