#include "Menu.h"
#include <fstream>
#include <stdio.h>
#include "Bill.h"

void Menu::add() {
top:

    int c = 0;
    float p = 0.0;
    string n = "abc";

    cout << "item code: ";
    cin >> i_code;

    cout << "item name: ";
    cin >> i_name;

    cout << "item price: ";
    cin >> i_price;


    if (!menu_data) {

        menu_data.open("menu data.txt", ios::app | ios::out); //opens file
        menu_data << " " << i_code << " " << i_name << " " << i_price << endl;
        menu_data.close();  //file being closed
    }
    else {

        menu_data >> c >> n >> p;

        while (!menu_data.eof()) {
            if (c == i_code) {
                token++;
            }
            menu_data >> c >> n >> p;
        }

        menu_data.close();

        if (token == 1) {
            goto top;
        }
        else {
            menu_data.open("menu data.txt", ios::app | ios::out);
            menu_data << " " << i_code << " " << i_name << " " << i_price << endl;
            menu_data.close();
        }
        cout << "\nItem has been inserted\n";
        displayMenu();
    }
}

void Menu::edit() {

    token = 0;

    int num = 0;
    int c = 0;
    float p = 0.0;
    string n = "abc";


    menu_data.open("menu data.txt", ios::in);

    if (!menu_data) {

        menu_data.open("menu data.txt", ios::app | ios::out); //opens file
        menu_data.close();  //file being closed
        cout << "\nAn empty file has automatically been generated as it didnt exist before\n";

    }
    else {
        // displayMenu();
        cout << "\nEnter item code to edit that particular item: ";
        cin >> num;

        temp_menu.open("temp menu.txt", ios::app | ios::out);
        menu_data >> i_code >> i_name >> i_price;

        while (!menu_data.eof()) {

            if (num == i_code) {
                cout << "\n\n\tEnter new code: ";
                cin >> c;

                cout << "\tEnter new name: ";
                cin >> n;

                cout << "\tEnter new price: ";
                cin >> p;

                temp_menu << c << " " << n << " " << p << endl;
                cout << "\n\tMENU HAS BEEN UPDATED\n";
                token++;
            }
            else {
                temp_menu << " " << i_code << " " << i_name << " " << i_price << endl;
            }
            menu_data >> i_code >> i_name >> i_price;
        }


        menu_data.close();
        temp_menu.close();

        remove("menu data.txt");
        rename("temp menu.txt", "menu data.txt");

        if (token == 0) {
            cout << "Entered code does not exists!";
        }

    }
    displayMenu();
}

void Menu::del() {

    token = 0;
    int num = 0;


    menu_data.open("menu data.txt", ios::in);

    if (!menu_data) {
        menu_data.open("menu data.txt", ios::app | ios::out); //opens file
        menu_data.close();  //file being closed
        cout << "\nAn empty file has automatically been generated as it didnt exist before\n";
    }
    else {

        cout << "\n\tEnter code to delete record\n";
        cin >> num;

        temp_menu.open("temp menu.txt", ios::app | ios::out);
        menu_data >> i_code >> i_name >> i_price;

        while (!menu_data.eof()) {

            if (i_code == num) {
                cout << "\nItem has been removed\n";
                token++;
            }
            else {
                temp_menu << " " << i_code << " " << i_name << " " << i_price << endl;
            }
            menu_data >> i_code >> i_name >> i_price;
        }

        menu_data.close();
        temp_menu.close();

        remove("menu data.txt");
        rename("temp menu.txt", "menu data.txt");

        if (token == 0) {
            cout << "\nEntered item code does not exists!\n";
        }
    }
    displayMenu();
}

void Menu::displayMenu() {

    menu_data.open("menu data.txt", ios::in); //opens file
    menu_data >> i_code >> i_name >> i_price;
    cout << "______________________________________\n"
        << "_________________Menu_________________\n"
        << "______________________________________\n";
    cout << "code\t\tname\t\tprice\n";
    while (!menu_data.eof()) {

        cout << i_code << "\t\t" << i_name << "\t\t" << i_price << endl;
        menu_data >> i_code >> i_name >> i_price;
    }
    menu_data.close();

}

void Menu::menu() {
    int menu_changes;
    cout << "\nYou have successfully signed in\n";
io:
    
    cout << "___________________________________\n";
    cout << "\n1\t-\tAdd items to the menu"
        << "\n2\t-\tEdit items from the menu"
        << "\n3\t-\tDelete items from the menu"
        << "\n4\t-\tCustomer's interface\n";

    cin >> menu_changes;

    switch (menu_changes) {
    case 1: {
        add();
        goto io;
        break;
    }
    case 2: {
        edit();
        goto io;
        break;
    }
    case 3: {
        del();
        goto io;
        break;
    }
    case 4: {
        break;
    }

    default: {
        cout << "\nInvalid entry\n";
        goto io;
        break;
    }


    }
}



