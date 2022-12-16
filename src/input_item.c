#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void inputitem() {
  system("cls");
  FILE *cm;
  item product = {"", "", 0, 0, 0, 0, 0,0};

    if ((cm = fopen("itemlist.dat", "rb+")) == NULL){
        printf("Error!, File Cannot Be Opened.\n");
        fclose(cm);
    }
    else {
		while(1)
      { 
          printf("|- - - -| INPUT NEW ITEM MENU |- - - -|\nPress 0 to cancel\n");
	        printf("Enter Product Code : ");
	        scanf("%s", product.code);
	        if(strcmp(product.code, "0")==0) {
	        	system("cls");
	          break;
	        }
	        printf("Enter Product Name : ");
	        scanf(" %[^\n]s", product.name);
          printf("Enter Product Stock : ");
	        scanf(" %d", &product.stock);
          printf("Enter Product Cost : ");
	        scanf(" %d", &product.cost);
          printf("Enter Product Price : ");
	        scanf(" %d", &product.price);

          product.expend = product.cost * product.stock;
          product.stats = product.income - product.expend;

          int p = atoi(product.code);       
	        fseek(cm, (p - 1) * sizeof(item), SEEK_SET);
	        fwrite(&product, sizeof(item), 1, cm);
          
          printf("INPUT ITEM SUCCESS! ");
          printf("Do you want to add more item?\n");
          printf("Press 1 to continue adding item, press 0 to close\n");
          int cm;
          scanf("%d", &cm);
          if (cm == 1) {
            system("cls");
            continue;
          } 
          else if ( cm == 0 ){
            system("cls");
            break;
          }
          else {
            printf("PLEASE INPUT A CORRECT INSTRUCTION\n");
          }
	        system("cls");
	    }
	  }
    fclose(cm);
}