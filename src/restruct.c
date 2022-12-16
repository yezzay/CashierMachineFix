#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <header.h>

void restruct(item *tmp) {
  strcpy(tmp->code, ""); 
	strcpy(tmp->name, ""); 
	tmp->stock = 0;
	tmp->price = 0;
	tmp->cost = 0;
	tmp->income = 0;
	tmp->expend = 0;
	tmp->stats = 0;
}

void restructed(receipt *temp) {
  strcpy(temp->code, ""); 
	strcpy(temp->item, ""); 
	temp->qty = 0;
	temp->price = 0;
	temp->minutes = 0;
	temp->hour = 0;
	temp->day = 0;
	temp->month = 0;
	temp->year = 0;
}