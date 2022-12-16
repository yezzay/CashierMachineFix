#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

void transaction() {
  system("cls");
    char name[10];
    printf("Enter your name : ");
    scanf("%s", name);
    while (1) {
      system("cls");
      FILE *cm, *rc, *hs;
      item product = {"", "", 0, 0, 0, 0, 0, 0};
      receipt struk = {"", "", 0, 0, 0, 0, 0, 0, 0};

      if ((cm = fopen("itemlist.dat", "rb+")) == NULL){
            printf("Error!, File Cannot Be Opened.\n");
            fclose(cm);
        }
      else if ((rc = fopen("receiptlist.dat", "wb")) == NULL){
            printf("Error!, File Cannot Be Opened.\n");
            fclose(rc);
      }
      else if ((hs = fopen("historylist.dat", "ab")) == NULL){
            printf("Error!, File Cannot Be Opened.\n");
            fclose(hs);
      }
      else{
        int hour, min,day,mon,year;
        int strnum = 1, avail = 0;
        int bill = 0, pay, change, donate=0;
        while(1){
            system("cls");
            cm = fopen("itemlist.dat", "rb+");
            rc = fopen("receiptlist.dat", "rb+");
            hs = fopen("historylist.dat", "ab");

            if (avail == 1){
              printf("Out Of Stock!\n\n");
            }
            avail = 0;
            printf("|- - - - - - - - - -| TRANSACTION MENU |- - - - - - - - - -|\nPress 0 to cancel\n");
            printf("Enter Item Code     : ");
            char pcode[4];
            scanf("%s", pcode);
            
            if (strcmp(pcode, "0")==0){
              break;
            }

            else {
              while(!feof(cm)){
                fread(&product, sizeof(item), 1, cm);
                  if (strcmp(product.code, pcode)==0){
                    printf("Enter Number of %s purchased : ", product.name);
                          int temp;
                          scanf("%d", &temp);
                          if (temp > product.stock) {       // cek stok
                            avail = 1;
                            break;
                          }
                          else {
                            int a = atoi(product.code);
                            fseek(cm, (a - 1) * sizeof(item), SEEK_SET); 
                            product.stock -= temp;
                            product.income += product.price * temp;
                            bill += product.price * temp;
                            product.stats = product.income - product.expend;
                            fwrite(&product, sizeof(item), 1, cm);

                            strcpy(struk.code, product.code);
                            strcpy(struk.item, product.name);
                            struk.qty = temp;
                            struk.price = product.price* temp;
                            
                            if (strnum == 1){
                              time_t transactime;
                              time(&transactime);
                              struct tm *local = localtime(&transactime);
                              hour = local->tm_hour;
                              min = local->tm_min;
                              day = local->tm_mday;
                              mon = local->tm_mon;
                              year = local->tm_year;
                            }

                            struk.hour = hour;
                            struk.minutes = min;
                            struk.day = day;
                            struk.month = mon+1;
                            struk.year = year+1900;
                            
                            fseek(rc, (strnum - 1) * sizeof(receipt), SEEK_SET);
                            fwrite(&struk, sizeof(receipt), 1, rc);
                            fwrite(&struk, sizeof(receipt), 1, hs);
                            strnum++;
                            break;
                          }	
                  }
              }	
            }
            fclose(cm);
            fclose(rc);
            fclose(hs);
          }
          if (bill > 0){
            printf("\nYour total Spending is : Rp. %d\n", bill);
            printf("Enter total payment : ");
            scanf("%d", &pay);
            change = pay - bill;
            if (change == 0){
              printf("Right Money!\n\n");
              break;
            }
            else if (change > 0){
              if (change<=500) {
                printf("Would you donate with your Rp. %d change [Yes(1)/No(0)]\n", change);
                int pil;
                scanf("%d", &pil);
                if (pil==1) {
                  donate += change;
                  change=0;
                  printf("Rp. %d Donation, Succes!\n\n", donate);
                  }
                }
                else {
                  printf("Your total change is : Rp. %d\n\n", change);
                }
              }
            else {
              printf("Not Enough Money!\n\n");
            }
            printf("Press 0 to print receipt, Press 1 to next transaction");
            int a;
            scanf("%d", &a);
              if (a == 1) {
                system("cls");
                transaction();
              } 
              else if ( a == 0 ){
                showreceipt(name, bill, pay, change, donate);
                continue;
              }
              }
              else {
                printf("\n");
              }
        }
    break;
    }
}