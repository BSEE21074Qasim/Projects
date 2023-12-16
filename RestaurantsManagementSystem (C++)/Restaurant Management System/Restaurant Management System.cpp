// Restaurant Management System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Menu.h"
#include <iostream>
#include "Admin.h"
#include "Bill.h"
#include "Order.h"
#include "Restaurant Management System.h"
#include "Table.h"
#include "Reserve.h"
#include"Waiter.h"
#include "Chef.h"
#include "Feedback.h"
#include "Customer.h"

using namespace std;

Cheff c;



int main() {

    Admin* s = s->getInstance();

    s->adminMenu();
    Customer cus;
    cout << "\n\tEnter customers name and id " << endl;

    cin >> cus;
    cout << cus;
    cus.cancel_order();

    Order o;
    Bill b;


    b.showinfo(o);


    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                        " << endl;
    cout << "                            T A B L E   R E S E R V A T I O N                             " << endl;
    cout << "                                                                                        " << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << endl;
    Table* tb;
    Reserve res;
    tb = &res;
    tb->init();
    bool k = 0;

    k:

        cout << " . ENTER 0 TO RESERVE THE TABLE ......." << endl;
        cout << " . ENTER 1 FOR TAKE AWAY" << endl;
        cout << endl;
   
        cin >> k;
        if (k == 1)
        {

            cout << "\n\tYou may recieve your order from the counter as soon as it is ready" << endl;

            int a;
            Feedback f;

        re:
            cout << "Whould you like to fill the survey\n"
                << "1.Yes\n" << "2.No\n";


            cin >> a;
            switch (a)
            {
            case 1:
            {
                f.compliment();
                break;
            }
            case 2:
            {
                break;
            }
            default:
                cout << "Wrong Selection\n";
                goto re;
            }

            exit(0);
        }
        if (tb->ask()) {
            cout << " TABLE AVAILABILITY STATUS = YES , THIS TABLE NUMBER : " << tb->h << " IS AVAILABLE \n";
            cout << endl;
        }
        else
        {
            cout << " TABLE AVAILABILITY STATUS = SORRY , THIS TABLE IS NOT AVAILABLE \n";
            goto k;
        }
        cout << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl;




    c.take_order();
    c.set_id();
    c.get_id();
    c.cook_order();
    c.deliver_order();

  
    int a;
    Feedback f;
   
e:

    cout << "Whould you like to fill the survey\n"
        << "1.Yes\n" << "2.No\n";


    cin >> a;
    switch (a)
    {
    case 1:
    {
        f.compliment();
        break;
    }
    case 2:
    {
        break;
    }
    default:
        cout << "Wrong Selection\n";
        goto e;
    }


}
