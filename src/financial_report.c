#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void financial_report() {
    while (1) {
    system("cls");
    FILE *cm;
    item product = {"", "", 0, 0, 0, 0,0, 0};
    if ((cm = fopen("itemlist.dat", "rb")) == NULL) {
      printf("Error!, File Cannot Be Opened.\n");
      fclose(cm);
    }
    else{ 
		int checker = 0, avail = 0, expend = 0, income = 0, stats = 0;
      while(!feof(cm)){ 
      if(fread(&product, sizeof(item), 1, cm)){
        if(strcmp(product.code, "000") && strcmp(product.name, "")){
          if (checker == 0){
            printf("|- - - - - - - - - - - - - - - - - - - - -| FINANCIAL REPORT MENU |- - - - - - - - - - - - - - - - - - - - -|\n");
            printf("=============================================================================================================\n");
        		printf("%-14s%-14s%-14s%-14s%-14s%-14s%-14s%s\n", "Product Code", "Product Name", "Stock", "Price", "Cost", "Expend", "Income", "Difference");
            printf("=============================================================================================================\n");
					}
          printf("%-14s%-16s%2d%14d%14d%16d%14d%18d\n", product.code, product.name, product.stock, product.price ,product.cost, product.expend, product.income, product.stats);
            printf("-------------------------------------------------------------------------------------------------------------\n");
          avail += product.stock;
          expend += product.expend;
          income += product.income;
					checker = 1;
          }
        }   
      }
        if (checker == 0){
        	printf("Inventory is empty! \n Press (1) to input an item, Press (0) to exit menu\n");
        int gatau;
        scanf("%d", &gatau);
        if (gatau == 0) {
          system("cls");
          return;
          }
        else if (gatau==1) {
          inputitem();
          }
		    } 
        else {
          printf("\n\nTotal Item  Available         : %d Pieces\n", avail);
          printf("Total Expend                  : Rp. %d\n", expend);
          printf("Total Income                  : Rp. %d\n", income);
          printf("Financial Stats               : ");
          stats = income - expend;
          if (stats < 0){
            printf("We're suffer a financial lost of Rp. %d\n\n", -1*stats);
          }
          else if (stats >= 0){
            printf("We get a profit of Rp. %d\n\n", stats);
          }
        }

        printf("Press 0 to exit menu ");
        int a;
        scanf("%d",&a);
        if (a==0) {
          system("cls");
          break;
        }
        else {
          printf("Wrong Input!");
          financial_report();
        }
        fclose(cm);
      }
  }
}