#pragma once
#include <iostream>
using namespace std;

class Customer
{
private:
    string name_customer;
    int customer_id;
public:

    Customer();

    void cancel_order();
    friend ostream& operator<<(ostream& output, const Customer& co);
    friend istream& operator>>(istream& inp, Customer& h);
};

