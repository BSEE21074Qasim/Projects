#pragma once
#include <iostream>
using namespace std;

class Table
{
public:

	int table[10];

	int h = 0;
	virtual void init() = 0;
	virtual bool ask() = 0;
};

