#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// variable
    //  static int bill;               // money to be paid            
    //  static int pay;                // ammount paid
    //  static int change;             // total change
    //  static int donate;             // total donation
    
//struct
  // product list
    typedef struct {
    char code[10];      // product code
    char name[20];      // product name 
    int stock;          // product available
    int price;          // selling price
    int cost;           // buying price
    int income;         // income for this product
    int expend;         // expenses for this product
    int stats;          // financial stats (profit/loss)
    } item ;

  //transaction receipt
    typedef struct {
      char code[5];    // sreceipt number
      char item[20];   // purchased item
      int qty;         // number of item purchased
      int price;       // total item price 
      int minutes;     // transaction time
      int hour;
      int day;
      int month;
      int year;
    } receipt ;

// function
  // main function
      void transaction();              // transaction menu
  // show function
      void checkitem();                 // show all item available
      void financial_report();          // show financial report
      void showreceipt();               // to show receipt of transaction
      void about();                     // show more info about this app
      void instruction();               // show instruction of how to using this app
      void history_code();              // show an item's all transaction history
      void history_mon();               // show item's transaction in a month
  // input function
      void inputitem();                 // to input a new item
      void input_discount();            // to input a discount on an item
      void add_stock();                 // to add a product stock
  //change function
      void change_itemname();           // to change item name
      void change_itemprice();          // to change item price
      void change_itemcost();           // to change item cost
  // delete function
      void delete_item();               // to delete choosen item
      void resetallstruct();            // to reset program (delete all data)
      void restruct(item *tmp);         // to reset struct (change data into null)
      void restructed(receipt *temp);  
