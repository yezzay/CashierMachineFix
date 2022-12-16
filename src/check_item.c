#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void checkitem(){
    while (1)
    {
            system("cls");
    FILE *cm;
    item product = {"", "", 0, 0, 0, 0, 0,0};

    if ((cm = fopen("itemlist.dat", "rb+")) == NULL) {
        printf("Error!, File Cannot Be Opened.\n");
        fclose(cm);
    }

    else{
    	int checker = 0;
        while(!feof(cm)){ 
            if(fread(&product, sizeof(item), 1, cm)){
                if(strcmp(product.code, "0") && strcmp(product.name, "")){
                	if (checker == 0){
                    printf("|- - - - - - - - -| ITEM LIST MENU |- - - - - - - - -|\n\n");
                    printf("===================================================\n");
                	printf("%-8s%-10s%10s%10s%10s\n", "Code", "Item", "Stock", "Price", "Cost");
                    printf("===================================================\n");
                  }
                    printf("%-8s%-10s%10d%10d%10d\n", product.code, product.name, product.stock, product.price, product.cost);
                    printf("---------------------------------------------------\n");
                    checker = 1;
                    
                }
             }   
        }
        if (checker == 0){
        	printf("Inventory is empty! \n Press (1) to input an item, Press (0) to cancel\n");
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
        printf("\n\n");
        printf("Press 0 to exit menu ");
        int a;
        scanf("%d",&a);
        if (a==0) {
        system("cls");
        break;
        }
        else {
        printf("Wrong Input!");
        checkitem();
        }
        fclose(cm);
    }
    }
    
}