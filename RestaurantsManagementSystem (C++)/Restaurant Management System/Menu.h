
#pragma once
#include <iostream>
#include <fstream>
//#include "Order.h"

using namespace std;

class Menu {
private:
    int token = 0;

public:
    int i_code;
    float i_price;
    string i_name;

    fstream menu_data, temp_menu;   //files
    
    void add();         //Add menu items
    void edit();        //Edit menu items
    void del();         //delete menu items
    void displayMenu(); //displays menu

    void menu();        //Contains all attributes of this class
    
};

