#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

int main() {
  system("cls");
  while (1)
  {
    printf("|- - - -| MAIN MENU |- - - -|\n");
    printf("[1] TRANSACTION\n");
    printf("[2] INVENTORY \n");
    printf("[3] FINANCIAL REPORT\n");
    printf("[4] ABOUT THIS PROGRAM\n");
    printf("[5] RESET SYSTEM\n");
    printf("[6] REFRESH SCREEN\n");
    printf("[0] EXIT PROGRAM\n");
    printf("enter the number : ");
    
    int cmd;
    scanf("%d", &cmd);

    if (cmd==0){
      system("cls");
      printf("Are you sure to exit this program?\n");                         // confirmation
      printf("press 0 to exit this program, press others to cancel\n");
      int confirm;
      scanf("%d", &confirm);
      if (confirm == 0 ) return 0;
      else {
        system("cls");
        continue;
      }
    }

    else if (cmd==1){
      transaction();
      system("cls");
    }

    else if (cmd==2){
    system("cls");
    while (1)
    {
      printf("|- - - -| INVENTORY MENU |- - - -|\n");
      printf("(1) INPUT\n");
      printf("(2) CHANGE\n");
      printf("(3) DELETE\n");
      printf("(4) INVENTORY DATA LIST\n");
	    printf("(0) BACK TO MAIN MENU\n");
      printf("enter the number : ");
      int pilih;
      scanf("%d", &pilih);
        if (pilih==0){
          system("cls");
          break;
        }
        else if (pilih == 1) {
          system("cls");
          while (1)
          {
            printf("|- - - -| INPUT INVENTORY MENU |- - - -|\n");
            printf("(1) INPUT NEW ITEM\n");
            printf("(2) ADD A ITEM STOCK\n");
            printf("(3) ADD A DISCOUNT\n");
            printf("(0) BACK TO INVENTORY MENU\n");
            printf("enter the number : ");
            int a;
            scanf("%d", &a);
            if (a==0) {
              system("cls");
              break;
            }
            else if (a==1){
              inputitem();
            }
            else if (a==2){
              add_stock();
            }
            else if (a==3){
              input_discount();
            }
            else {
            system("cls");
            printf("PLEASE INPUT CORRECT NUMBER !\n\n");
            continue;
            }
          }
          
        }
        else if (pilih==2){
          system("cls");
          while (1)
          {
            printf("|- - - -| CHANGE INVENTORY MENU |- - - -|\n");
            printf("(1) CHANGE ITEM NAME\n");
            printf("(2) CHANGE ITEM PRICE\n");
            printf("(3) CHANGE ITEM COST\n");
            printf("(0) BACK TO INVENTORY MENU\n");
            printf("enter the number : ");
            int b;
            scanf("%d", &b);
            if (b==0){
              system("cls");
              break;
            }
            else if(b==1){
              change_itemname();
            }
            else if(b==2){
              change_itemprice();
            }
            else if(b==3){
              change_itemcost();
            }
            else {
            system("cls");
            printf("PLEASE INPUT CORRECT NUMBER !\n\n");
            continue;
            }
          }
          
        }

        else if (pilih==3){
          system("cls");
          while (1)
          {
            printf("|- - - -| DELETE DATA MENU |- - - -|\n");
            printf("(1) DELETE ITEM\n");
            printf("(0) BACK TO MAIN MENU\n");
            printf("enter the number : ");
            int c;
            scanf("%d", &c);
            if (c==0) {
              system("cls");
              break;
            }
            else if (c==1){
              delete_item();
            }
            else {
            system("cls");
            printf("PLEASE INPUT CORRECT NUMBER !\n\n");
            continue;
            }
          }
        }

        else if (pilih==4){
          checkitem();
          continue;
          
        }
        
        else {
          system("cls");
          printf("PLEASE INPUT CORRECT NUMBER !\n\n");
          continue;
        }
    }
    
    }

    else if (cmd==3){
      system("cls");
          while (1)
          {
            printf("|- - - -| FINANCIAL REPORT MENU |- - - -|\n");
            printf("(1) ALL FINANCIAL REPORT\n");
            printf("(2) MONTHLY FINANCIAL REPORT\n");
            printf("(3) ITEM FINANCIAL REPORT\n");
            printf("(0) BACK TO MAIN MENU\n");
            printf("enter the number : ");
            int p;
            scanf("%d", &p);
            if (p==0) {
              system("cls");
              break;
            }
            else if (p==1){
              financial_report();
            }
            else if (p==2) {
              history_mon();
            }
            else if (p==3) {
               history_code();
            }
            else {
            system("cls");
            printf("PLEASE INPUT CORRECT NUMBER !\n\n");
            continue;
            }
          }
    }

    else if (cmd==4){
      system("cls");
          while (1)
          {
            printf("|- - - -| ABOUT THIS APP MENU |- - - -|\n");
            printf("(1) INSTRUCTION OF USE\n");
            printf("(2) ABOUT THIS APP\n");
            printf("(0) BACK TO MAIN MENU\n");
            printf("enter the number : ");
            int q;
            scanf("%d", &q);
            if (q==0) {
              system("cls");
              break;
            }
            else if (q==1){
              instruction();
            }
            else if (q==2) {
              about();
            }
            else {
            system("cls");
            printf("PLEASE INPUT CORRECT NUMBER !\n\n");
            continue;
            }
          }
      
    }
    
    else if (cmd == 5) {
      resetallstruct();
    }

    else if (cmd == 6) {
      system("cls");
      continue;
    }
    
    else {
      system("cls");
      printf("PLEASE INPUT CORRECT NUMBER !\n\n");
      continue;
    }
  }
  
}