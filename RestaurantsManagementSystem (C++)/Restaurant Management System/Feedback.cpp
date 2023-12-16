#include "Feedback.h"
#include <iostream>

using namespace std;

Feedback::Feedback()
{
    cout << "Please use this form to give us compliments, complaints and suggestions\n";
    cout << "So We could improve our service and you experience with us\n";
}

void Feedback::compliment()
{
    int a, b, c, d, e;
    cout << "How Did You Find Our Service\n";
    cout << "1. Excellent\n" << "2. Great\n" << "3.Average\n" << "4.Poor\n" << "5.Very Bad\n";
    cin >> a;
    switch (a)
    {
    case 1:
    {
        cout << "Excellent\n";
        break;
    }
    case 2:
    {
        cout << "Great\n";
        break;
    }
    case 3:
    {
        cout << "Average\n";
        break;
    }
    case 4:
    {
        cout << "poor\n";
        break;
    }
    case 5:
    {
        cout << "Very Bad\n";
        break;
    }
    default:
        cout << "Wrong Selection\n";
    }
    cout << endl << endl;
    cout << "How was the quality of our food?\n";
    cout << "1. Excellent\n" << "2. Great\n" << "3.Average\n" << "4.Poor\n" << "5.Very Bad\n";
    cin >> b;
    switch (b)
    {
    case 1:
    {
        cout << "Excellent\n";
        break;
    }
    case 2:
    {
        cout << "Great\n";
        break;
    }
    case 3:
    {
        cout << "Average\n";
        break;
    }
    case 4:
    {
        cout << "poor\n";
        break;
    }
    case 5:
    {
        cout << "Very Bad\n";
        break;
    }
    default:
        cout << "Wrong Selection\n";
    }
    cout << endl << endl;
    cout << "How was the attitude of our staff.\n";
    cout << "1. Excellent\n" << "2. Great\n" << "3.Average\n" << "4.Poor\n" << "5.Very Bad\n";
    cin >> c;
    switch (c)
    {
    case 1:
    {
        cout << "Excellent\n";
        break;
    }
    case 2:
    {
        cout << "Great\n";
        break;
    }
    case 3:
    {
        cout << "Average\n";
        break;
    }
    case 4:
    {
        cout << "poor\n";
        break;
    }
    case 5:
    {
        cout << "Very Bad\n";
        break;
    }
    default:
        cout << "Wrong Selection\n";
    }

    cout << endl << endl;

    cout << "How was the wait time you have experienced.\n";
    cout << "1. Excellent\n" << "2. Great\n" << "3.Average\n" << "4.Poor\n" << "5.Very Bad\n";
    cin >> d;
    switch (d)
    {
    case 1:
    {
        cout << "Excellent\n";
        break;
    }
    case 2:
    {
        cout << "Great\n";
        break;
    }
    case 3:
    {
        cout << "Average\n";
        break;
    }
    case 4:
    {
        cout << "poor\n";
        break;
    }
    case 5:
    {
        cout << "Very Bad\n";
        break;
    }
    default:
        cout << "Wrong Selection\n";
    }

    cout << endl << endl;

    cout << "How was the overall experience.\n";
    cout << "1. Excellent\n" << "2. Great\n" << "3.Average\n" << "4.Poor\n" << "5.Very Bad\n";
    cin >> e;
    switch (e)
    {
    case 1:
    {
        cout << "Excellent\n";
        break;
    }
    case 2:
    {
        cout << "Great\n";
        break;
    }
    case 3:
    {
        cout << "Average\n";
        break;
    }
    case 4:
    {
        cout << "poor\n";
        break;
    }
    case 5:
    {
        cout << "Very Bad\n";
        break;
    }
    default:
        cout << "Wrong Selection\n";
    }

}


Feedback::~Feedback()
{
    cout << "**************************************** " << endl;
    cout << " T H A N K S     F O R      C O M I N G  " << endl;
    cout << "**************************************** " << endl;
}