#pragma once
#include "Waiter.h"
using namespace std;

class Cheff :public Waiter
{
public:
    Waiter w;//compostion
    string cheff_name;
    int chef_id;

    void set_id();
    int get_id();
    void cook_order();

};