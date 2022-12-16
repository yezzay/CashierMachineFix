#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

void showreceipt(char name[], int bill, int pay, int change, int donate) {
  FILE *rc;
  system("cls");
  receipt struk = {"", "", 0, 0, 0, 0, 0, 0, 0};

  	if ((rc = fopen("receiptlist.dat", "rb+")) == NULL){
    	printf("Error!, File Cannot Be Opened.\n");
      fclose(rc);
    }
    else{
    	system("cls");
    	int tc = 1;
    	printf("=======================================\n|- - - -| TRANSACTION RECEIPT |- - - -|\n=======================================\n\nCashier : %s\n", name);
		  while(!feof(rc)){ 
        if(fread(&struk, sizeof(receipt), 1, rc)){
          if(strcmp(struk.code, "0")){
            if (tc){
	            printf("Transaction Time : ");
	        		if (struk.day < 10){
	        			printf("0%d/", struk.day);
							}
							else {
							printf("%d/", struk.day);
							}
							if (struk.month < 10){
							printf("0%d/", struk.month);
							}
							else {
							printf("%d/", struk.month);
							}
	            printf("%d\t ", struk.year);
	            if (struk.hour < 10){
	            	printf("0%d:", struk.hour);
							}
							else {
								printf("%d:", struk.hour);
							}
							if (struk.minutes < 10){
								printf("0%d\n\n", struk.minutes);
							}
							else {
								printf("%d\n\n", struk.minutes);
							}
	    				printf("=======================================\n%-7s%-14s%-12s%s\n", "Code", "Item", "Quantity", "Price");
	    				tc = 0;
						}
              printf("=======================================\n%-7s%-14s%6d%11d\n", 
              struk.code, struk.item, struk.qty, struk.price);
        	}
            }   
        }
        printf("=======================================\n");
        printf("%29s%9d\n", "Bill:", bill);
        printf("%29s%9d\n", "Pay:", pay);
				printf("%29s%9d\n", "Donate:", donate);
        printf("%29s%9d\n", "Change:", change);
				if (donate>0) printf("\n=======================================\nThank You for your Rp. %d Donation", donate);
				printf("\nThank You for Choosing Us.\nYour Support Means a Lot to Us!\n=======================================\n");

				printf("Press 0 to exit menu ");
        int a;
        scanf("%d",&a);
        if (a==0) {
					system("cls");
					return;
					}
        else {
					printf("Wrong Input!");
					showreceipt(name, bill, pay,change, donate);
					}
					fclose(rc);
		}
}