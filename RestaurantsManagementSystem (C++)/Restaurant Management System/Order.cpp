#include "Order.h"
#include "Menu.h"
#include <fstream>
void Order::order(Order& h)
{
    if (!menu_data)
    {
        cout << "\nEmpty menu data base \n";
    }
    else
    {
        
        cout << "\n-----------PLACE OREDR----------- \n";
        do
        {
        m:
            cout << "Enter item code: \n";
            cin >> arrc[c];
            cout << "Enter item quantity: \n";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\nDuplicate item code Try again \n";
                    goto m;
                }
            }
            c++;
            cout << "\nDo you want to buy another item? if yess than press y press no \n";
            cin >> choice;
        } while (choice == "y");
    }
    h.bill();
}

void Order::bill() {
    total = 0;

    cout << "\n------------------------Bill------------------------ \n";
    cout << "Item number \t Item name \t Item quantity \t Price \n ";
    for (int i = 0; i < c; i++)
    {
        menu_data.open("menu data.txt", ios::in);
        menu_data >> i_code >> i_name >> i_price;
        while (!menu_data.eof())
        {

            if (i_code == arrc[i])
            {
                total += (i_price * arrq[i]);

                cout << "\n " << i_code << "\t\t" << i_name << "\t\t" << arrq[i] << "\t\t" << i_price << "\t";
                menu_data.close();
            }
            menu_data >> i_code >> i_name >> i_price;
        }
        i_price += total;
    }

    cout << "\n\nTotal amount: " << total
        << endl;

}


/*
std::ostream& operator<<(std::ostream& out, const Order& order)
{
    if (order.m_waiter.empty())
    {
        out << order.getName() << " has no Waiter right now";
        return out;
    }

    out << order.m_name << " is seeing Waiter: ";
    for (const auto& waiter : order.m_waiter)
        out << waiter.get().getName() << ' ';

    return out;
}
*/