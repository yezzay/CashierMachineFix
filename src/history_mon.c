#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

void history_mon() {
  system("cls");
	FILE *hs;
	receipt struk = {"", "", 0, 0, 0, 0, 0, 0, 0};
	
	if ((hs = fopen("historylist.dat", "rb+")) == NULL){
    	printf("File could not be opened.\n");
      fclose(hs);
	}
  else{
    	while(1){
    		hs = fopen("historylist.dat", "rb+");
    		
    		printf("Enter Month/Year:");
		    int y,m;
		    scanf("%d/%d", &y,&m);
		    if(y == 0){
		    	system("cls");
		      break;
		    }
			int sold = 0, income = 0;
		  system("cls");
	    	while(!feof(hs)){ 
		      if(fread(&struk, sizeof(receipt), 1, hs)){
		            if(struk.year == y){
		            	if(struk.month == m){
		            		if (sold == 0){
		            		  printf("|- - - - - - - - - - -| %d/%d's FINANCIAL REPORT |- - - - - - - - - - -|\n", struk.year,struk.month);
										  printf("=========================================================================\n");
		              		printf("%-7s%-14s%6s%14s%20s%8s\n", "Code", "Item", "Quantity", "Total Price", "Transaction Date", "Time");
								  		printf("=========================================================================\n");
						        }
		                printf("%-7s%-14s%6d%14d", struk.code, struk.item, struk.qty, struk.price);
                if (struk.day < 10){
                  printf("%11s%d/", "0", struk.day);
                }
                else {
                  printf("%12d/", struk.day);
                }
                if (struk.month < 10){
                  printf("0%d/", struk.month);
                }
                else {
                  printf("%d/", struk.month);
                }
                      printf("%d", struk.year);
                      if (struk.hour < 10){
                        printf("   0%d:", struk.hour);
                }
                else {
                  printf("   %d:", struk.hour);
                }
                if (struk.minutes < 10){
                  printf("0%d\n", struk.minutes);
                }
                else {
                  printf("%d\n", struk.minutes);
                }
                printf("\n--------------------------------------------------------------------------\n");
                  sold += struk.qty;
                  income += struk.price;
                }
                    }
                }   
            }
		    if (sold == 0){
		    	printf("There is no transaction data yet!\n");
			}
			else {
				printf("=========================================================================\n");
				printf("Total Item Sold		: %d\n", sold);
				printf("Total Income		: %d\n", income);
			}
			
		    printf("\n");
			fclose(hs);   
		}	
	}

}