#include "Waiter.h"


void Waiter::take_order()
{
    cout << "\n\n\nThis is your waiter here may I please know your table number ";
    cout << "\n\nEnter table number \n";
    cin >> table_number;
}

void Waiter::deliver_order()
{

    cout << "\nOrder will be delivered at table number " << table_number << endl;
    cout << endl;


}