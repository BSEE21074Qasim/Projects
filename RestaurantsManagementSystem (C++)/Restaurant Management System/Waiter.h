#pragma once
#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>
#include "Order.h"
using namespace std;

class Waiter
{
    int table_number;
public:
    void take_order();
    void deliver_order();
};

