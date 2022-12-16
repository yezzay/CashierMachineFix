#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void instruction() {
  system("cls");
  while (1)
  {
  printf("|- - - - - - - - - - - - - - - - - - - -| INSTRUCTION OF USE |- - - - - - - - - - - - - - - - - - - -|\n");
  printf("  1. Please input only numbers when asked for approval of something like the example below :\n      ->  'Inventory is empty! Press (1) to input an item, Press (0) to cancel'\n     to avoid error [infinite loop]\n");
  printf("  2. Please restart program after reset data\n");
  printf("  3. Please input only numbers on product code\n");
  printf("  4. if any crashing program, just restart this program\n");
  printf("  5. Vill Gleck! \n");

  printf("\n\nPress 0 to exit menu ");
    int a;
    scanf("%d",&a);
    if (a==0) {
      system("cls");
      break;
    }
    else {
      printf("Wrong Input!");
      instruction();
    }
  }
  
}