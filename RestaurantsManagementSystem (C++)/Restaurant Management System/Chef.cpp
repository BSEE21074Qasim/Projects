#include "Chef.h"



void Cheff::set_id()
{
    chef_id = 333;
}

int Cheff::get_id()
{
    cout << "Cheff ID is " << chef_id << endl;
    return chef_id;
}

void Cheff::cook_order()
{
    cout << "\nYour order is being cooked" << endl;
    cout << "    BON APETIT    " << endl;
}