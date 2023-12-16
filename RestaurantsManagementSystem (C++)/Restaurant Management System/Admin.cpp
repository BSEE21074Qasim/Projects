#include "Admin.h"
#include <iostream>
using namespace std;

Admin* Admin::instance = 0;

Admin::Admin() {
	id = "id";
	pass = "pass";
	access = false;
}

void Admin::signIn() {
re:

	string admin_id, admin_pass;

	admin_data.open("Admin credentials.txt", ios::in|ios::out);

	if (!admin_data) {
		cout << "\nFile not found\n";
	}
	else {
		cout << "\n\n********************* Sign in *********************\n";

		cout << "\n\n\tID: ";
		cin >> admin_id;

		cout << "\n\tPassword: ";
		cin >> admin_pass;

		while (!admin_data.eof()) {

			admin_data >> id >> pass;
			if (id == admin_id && pass == admin_pass) {
				access = true;

				Menu oMenu;
				oMenu.menu();


			}
			
		}
		admin_data.close();
	}
}

void Admin::signUp() {
	string master_id, master_pass;
	int master;
a:
	cout << "\n0\t-\tReturn to previous page"
		<< "\n1\t-\tProceed to signing up";
	cin >> master;
	switch (master) {
	case 0: {
		break;
	}

	case 1: {
		cout << "\nEnter master credentials to proceed\n";

		cout << "ID: ";
		cin >> master_id;

		cout << "Password: ";
		cin >> master_pass;

		if (master_id == "master" && master_pass == "master") {
			admin_data.open("Admin credentials.txt", ios::app);

			cout << "\n\n********************* Sign up *********************\n";

			cout << "ID: ";
			cin >> id;

			cout << "Password: ";
			cin >> pass;

			admin_data << id << "\t" << pass << endl;

			admin_data.close();
		}
		else {
			cout << "\nYou are unauthorized to proceed\n";
			goto a;

		}
		break;
	}
	default: {
		cout << "\nInvalid entry try again\n";
		goto a;
		break;
	}
	}
}

void Admin::adminMenu() {
	int admin_choice;
a:

	cout << "\n1\t-\tSign up"
		<< "\n2\t-\tSign in\n";
	cin >> admin_choice;

	switch (admin_choice) {
	case 1: {
		signUp();
		goto a;
		break;
	}
	case 2: {
		signIn();
		break;
	}
	}
}
