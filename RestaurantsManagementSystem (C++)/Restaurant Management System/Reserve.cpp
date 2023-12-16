#include "Reserve.h"
#include "Table.h"
#include <iostream>
using namespace std;


void Reserve::init()
{
	int i = 0;
	while (i < 11)
	{
		table[i] = i;
		i++;
	}
}

int Reserve::check(int h)
{
	int i = 0;
	while (i < 11)
	{
		if (table[i] == h) { table[i] = 0; return 1; }
		i++;
	}
	return 2;
}

bool Reserve::ask()
{
	cout << "    WE HAVE TOTAL 10 TABLES IN OUR RESTAURAUNT   \n";
	cout << endl;
	cout << " WHICH TABLE YOU WANT TO RESERVE : ";
	cout << endl;
	cin >> h;
	cout << " CHECKING IF THIS TABLE IS AVAILABLE......... \n";
	cout << endl;

	if (h > 11 && h <= 0) { return false; }
	else
	{
		if (check(h) == 1) { return true; }
		else
			return false;
	}
}