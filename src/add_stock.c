#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void add_stock() {
      system("cls");
    FILE *cm;
    item product = {"", "", 0, 0, 0, 0, 0,0};
    
    if ((cm = fopen("itemlist.dat", "rb+")) == NULL) {
          printf("Error!, File Cannot Be Opened.\n");
          fclose(cm);
      }
      else{
        while(1){
          printf("|- - - - - - - - - -| ADD ITEM STOCK MENU |- - - - - - - - - -|\nPress 0 to cancel\n");
          printf("Enter Item Code: ");
          char pcode[4];
          scanf("%s", pcode);
          
          if(!strcmp(pcode, "0")){
              system("cls");
                break;
            }

          while(!feof(cm)){
            fread(&product, sizeof(item), 1, cm);
              if (!strcmp(product.code, pcode)){
                  printf("Enter number of %s added : ", product.name);
                  int temp;
                  scanf("%d", &temp);
                  product.stock += temp;
                  product.expend += product.cost * temp;
	                product.stats = product.income - product.expend;
                  int a = atoi(product.code);
                  fseek(cm, (a - 1) * sizeof(item), SEEK_SET);                   
                  fwrite(&product, sizeof(item), 1, cm);
                  printf("ADD ITEM STOCK SUCCESS! ");
                  printf("Do you want to add more item stock?\n");
                  printf("Press 1 to continue adding more item stock, press 0 to close\n");
                  int cm;
                  scanf("%d", &cm);
                  if (cm == 1) {
                    system("cls");
                    add_stock();
                  } 
                  else if ( cm == 0 ){
                    system("cls");
                    break;
                  }
                  break;	
                }
          }
            
            fclose(cm);
            system("cls");
        }
    }
}