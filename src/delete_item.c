#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void resetstruct(item *temp);

void delete_item() {
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
          printf("|- - - -| DELETE ITEM MENU |- - - -|\nPress 0 to cancel\n");
	        printf("Enter Product Code : ");
	        scanf("%s", product.code);
	        if(strcmp(product.code, "0")==0) {
	        	system("cls");
	          break;
	        }

          int p = atoi(product.code);       
	        fseek(cm, (p - 1) * sizeof(item), SEEK_SET);
					restruct(&product);
	        fwrite(&product, sizeof(item), 1, cm);
          
          printf("DELETE ITEM SUCCESS! ");
          printf("Do you want to delete more item?\n");
          printf("Press 1 to continue deleting item, press 0 to close\n");
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

// void resetstruct(item *temp) {
// 	strcpy(temp->code, ""); 
// 	strcpy(temp->name, ""); 
// 	temp->stock = 0;
// 	temp->price = 0;
// 	temp->cost = 0;
// 	temp->income = 0;
// 	temp->expend = 0;
// 	temp->stats = 0;
// }