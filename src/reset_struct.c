#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>


void reset(item *tmp);

void resetallstruct() {
  system("cls");
  FILE *cm, *hs;
  item tmp = {"", "", 0, 0, 0, 0, 0,0};
  receipt temp = {"", "", 0, 0, 0, 0, 0, 0, 0};

  if ((cm = fopen("itemlist.dat", "rb+")) == NULL){
        printf("Error!, File Cannot Be Opened.\n");
        fclose(cm);
  }
  else if ((hs = fopen("historylist.dat", "ab")) == NULL){
            printf("Error!, File Cannot Be Opened.\n");
            fclose(hs);
  }

  else {
  printf("Are you sure to reset this program?\nAll of the data will bw deleted\nPress 0 to reset program, Press Others to cancel\nPlease Restart Program after Reset!\n");
  int p;
  scanf("%d", &p);
  if (p==0) {
      while (!feof(cm) && !feof(hs)) {
      fseek(cm, (p - 1) * sizeof(item), SEEK_SET);
      fseek(hs, (p - 1) * sizeof(receipt), SEEK_SET);
      restruct(&tmp);
      restructed(&temp);
      fwrite(&tmp, sizeof(item), 1, cm);
      fwrite(&temp, sizeof(receipt), 1, hs);
      p++;
      }
  }
  else {
    system("cls");
    return;
  }
  }
  fclose(cm);
}

// void reset(item *tmp) {
//   strcpy(tmp->code, ""); 
// 	strcpy(tmp->name, ""); 
// 	tmp->stock = 0;
// 	tmp->price = 0;
// 	tmp->cost = 0;
// 	tmp->income = 0;
// 	tmp->expend = 0;
// 	tmp->stats = 0;
// }