#include "Customer.h"

ostream& operator<<(ostream& output, const Customer& co)
{
    output << "\n\nCustomer Name: " << co.name_customer << endl;
    output << "Customer ID: " << co.customer_id << endl;
    return output;
}



std::istream& operator>> (std::istream& inp, Customer& h)
{
    inp >> h.name_customer;
    inp >> h.customer_id;
    return inp;
}


Customer::Customer()
{
    name_customer = "no name";
    customer_id = 0;

}

void Customer::cancel_order()
{
i:
    string p;
    cout << "\n\tAre you ready to place your order? (y/n) " << endl;

    cin >> p;


    if (p == "y")
    {
        cout << "\tYour order is being proceeded" << endl;
    }
    else if (p == "n")
    {
        cout << "\tYour order is canceled :( " << endl;
        goto i;

    }
    else {
        cout << "\nINVALID ENTRY\n";
        goto i;
    }
}