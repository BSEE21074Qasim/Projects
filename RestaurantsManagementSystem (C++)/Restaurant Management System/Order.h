#pragma once
#include "Menu.h"
#include <fstream>
#include <iostream>

using namespace std;
class Order: public Menu {

    fstream menu_data;
    int c = 0;
    int arrc[100];
    int arrq[100];
    string choice;

    float amount = 0;
    float total = 0;





public:
    void bill();
    void order(Order&);


};

