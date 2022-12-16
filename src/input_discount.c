#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void input_discount(){
  system("cls");
    FILE *cm;
    item product = {"", "", 0, 0, 0, 0, 0,0};
    
    if ((cm = fopen("itemlist.dat", "rb+")) == NULL) {
          printf("Error!, File Cannot Be Opened.\n");
          fclose(cm);
      }
      else{
        while(1){
          printf("|- - - - - - - - - -| ADD DISCOUNT MENU |- - - - - - - - - -|\nPress 0 to cancel\n");
          printf("Enter Item Code: ");
          char pcode[4];
          scanf("%s", pcode);
          
          if(!strcmp(pcode, "0")){
              system("cls");
                break;
            }

          while(!feof(cm)){
                int dc;
                fread(&product, sizeof(item), 1, cm);
                if (!strcmp(product.code, pcode)){
                    printf("Enter Item Discount (%%): ");
                    scanf("%d", &dc);	
                    product.price = product.price*(100-dc)/100;
                    product.stats = product.income - product.expend;
                    int p = atoi(product.code);
                    fseek(cm, (p - 1) * sizeof(item), SEEK_SET);                   
                    fwrite(&product, sizeof(item), 1, cm);
                    printf("ADD ITEM DISCOUNT SUCCESS! ");
                    printf("Do you want to add more item discount?\n");
                    printf("Press 1 to continue adding more item discount, press 0 to close\n");
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
            break;
            system("cls");
        }
    }
}