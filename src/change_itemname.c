#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void change_itemname() {
  system("cls");
	FILE *cm;
	item product = {"", "", 0, 0, 0, 0, 0,0};
	
	if ((cm = fopen("itemlist.dat", "rb+")) == NULL) {
        printf("Error!, File Cannot Be Opened.\n");
        fclose(cm);
    }
    else{
    	while(1){
        
				printf("|- - - - - - - - - -| CHANGE ITEM NAME MENU |- - - - - - - - - -|\nPress 0 to cancel\n");
    		printf("Enter Item Code	: ");
	    	char pcode[4];
	    	scanf("%s", pcode);
	    	
	    	if(!strcmp(pcode, "0")){
	        	system("cls");
	            break;
	        }
	    	
	    	while(!feof(cm)){
	        fread(&product, sizeof(item), 1, cm);
	        if (!strcmp(product.code, pcode)){
	          printf("Enter New Item Name	: ");
					  scanf(" %[^\n]s", product.name);	
					
					int p = atoi(product.code);
	        fseek(cm, (p - 1) * sizeof(item), SEEK_SET);                   
	        fwrite(&product, sizeof(item), 1, cm);

					printf("CHANGE ITEM NAME SUCCESS! ");
        	printf("Do you want to change more item name?\n");
          printf("Press 1 to continue changing item name, press 0 to close\n");
          int cm;
          scanf("%d", &cm);
          if (cm == 1) {
            change_itemname();
            continue;
          } 
          else if ( cm == 0 ){
            system("cls");
            break;
          }
          else {
            printf("PLEASE INPUT A CORRECT INSTRUCTION\n");
						change_itemname();
          }
	        system("cls");
				}
	      }
			
	    fclose(cm);
	    system("cls");
			break;
		}
	}
}