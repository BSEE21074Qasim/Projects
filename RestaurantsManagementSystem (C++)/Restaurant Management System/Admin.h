#pragma once
#include <fstream>
#include "Menu.h"	//For composition
using namespace std;

class Admin {
	static Admin* instance;
	string id, pass;
	bool access = false;
	Admin();

public:

	fstream admin_data;

	static Admin* getInstance() {
		if (!instance)
			instance = new Admin;
		return instance;
	}


	void signIn();
	void signUp();
	void adminMenu();


};

