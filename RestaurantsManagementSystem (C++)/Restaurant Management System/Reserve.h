#pragma once
#include <iostream>
#include "Table.h"
class Reserve :public Table
{
public:

	void init();
	int check(int h);
	bool ask();
};

