#include"FINAL.h"
#include <iostream>
#include<fstream>
#include<string>
#include <math.h> //ceil function
#include <climits> //extractMin function
using namespace std;

HeapOrganization::HeapOrganization(int c_capacity, int s_capacity) {
	centre_size = 0;
	staff_size = 0;

	centre_capacity = c_capacity;
	staff_capacity = s_capacity;

	centre_array = new int[c_capacity];
	staff_array = new int[s_capacity];
}

void HeapOrganization::swap(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int HeapOrganization::centreIndex(int val) {
	for (int i = 0; i < centre_size; i++) {
		if (centre_array[i] == val) {
		//cout << "\n Value Found";
		return i;
		}
	}
	cout << "\n Value not found";
}

void HeapOrganization::displayOrganization() {
	cout << endl;
	org.open("file.txt", ios::out | ios::in);
	if (!org) {
		cout << "\nFile doesnt exist";
		org.close();
		return;
	}
	else {
		org >> id >> name;
	do {
		cout << id << "\t" << name;
		org >> id >> name;
		cout << endl;
	} while (!org.eof());
	org.close();
	}
}
void HeapOrganization::displayStaff() {
	cout << endl;
	stf.open("Staff.txt", ios::out | ios::in);
	if (!stf) {
		cout << "\nFile doesnt exist";
		stf.close();
		return;
	}
	else {
		stf >> id >> name >> designation;
	do {
		cout << id << "\t" << name << "\t" << designation;
		stf >> id >> name >> designation;
		cout << endl;
	} while (!stf.eof());
	stf.close();
	}
}

void HeapOrganization::minHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < centre_size && centre_array[l] < centre_array[i]) {
		smallest = l;
	}
	if (r < centre_size && centre_array[r] < centre_array[smallest]) {
		smallest = r;
	}
	if (smallest != i) {
		swap(centre_array[i], centre_array[smallest]);
		minHeapify(smallest);
	}
}



int HeapOrganization::removeVaccinationCentre(int v) {

	fstream orgTemp;
	int tokken = 0;

	org.open("file.txt", ios::in);
	orgTemp.open("tempVC.txt", ios::app | ios::out);
	org >> id >> name;

	while (!org.eof()) {
		if (id == v) {
			cout << "\n\t***Vaccination Centre has been removed***";
			tokken++;
		}
		else {
			orgTemp << id << "\t" << name << endl;
		}
		org >> id >> name;
	}
	org.close();
	orgTemp.close();
	remove("file.txt");
	rename("tempVC.txt", "file.txt");
	if (tokken == 0) {
		cout << "\nError: Vaccination centre id doesnt exists";
		return 0;
	}


	int x = centreIndex(v);
	if (centre_size <= 0) {
		return INT_MAX;
	}
	if (centre_size == 1) {
		centre_size--;
		return centre_array[x];
	}
	int root = centre_array[x];
	centre_array[x] = centre_array[centre_size - 1];
	centre_size--;
	minHeapify(0);


return root;
}


int HeapOrganization::left(int i) {
	return ((2 * i) + 1);
}

int HeapOrganization::right(int i) {
	return ((2 * i) + 2);
}

int HeapOrganization::parent(int i) {
	return ((i - 1) / 2);
}

void HeapOrganization::insertVaccinationCentre(int k) {
	id = k;
	if (centre_size == centre_capacity) {
		cout << "\nOver flow";
		return;
	}
	centre_size++;
	int i = centre_size - 1;
	centre_array[i] = k;

	while (i != 0 && centre_array[parent(i) > centre_array[i]]) {
		swap(centre_array[i], centre_array[parent(i)]);
		i = parent(i);
	}

	minHeapify(0);
	cout << "\n Enter name: ";
	cin >> name;



	org.open("file.txt", ios::app);
	org << id << "\t" << name << endl;
	org.close();

	minHeapify(0);

}


int HeapOrganization::staffIndex(int val) {
	for (int i = 0; i < staff_size; i++) {
		if (staff_array[i] == val) {
			cout << "\n Value Found";
			return i;
		}
	}
	cout << "\n Value not found";
}

int HeapOrganization::removeStaff(int v) {
	fstream stfTemp;
	int tokken = 0;
	stf.open("Staff.txt", ios::in);
	stfTemp.open("tempS.txt", ios::app | ios::out);
	stf >> id >> name >> designation;
	while (!stf.eof()) {
		if (id == v) {
			cout << "\n\t***Employee has been removed***";
			tokken++;
		}
		else {
			stfTemp << id << "\t" << name << "\t" << designation << endl;
		}
	stf >> id >> name >> designation;
	}
	stf.close();
	stfTemp.close();
	remove("Staff.txt");
	rename("tempS.txt", "Staff.txt");
	if (tokken == 0) {
		cout << "\nError: Employee id does not exists";
		return 0;
	}

	int x = staffIndex(v);
	if (staff_size <= 0) {
		return INT_MAX;
	}
	if (staff_size == 1) {
		staff_size--;
		return staff_array[x];
	}
	int root = staff_array[x];
	staff_array[x] = staff_array[staff_size - 1];
	staff_size--;
	minHeapify(0);

	return root;
}

void HeapOrganization::insertStaff(int k) {
	id = k;
	if (staff_size == staff_capacity) {
		cout << "\nOver flow";
		return;
	}
	staff_size++;
	int i = staff_size - 1;
	staff_array[i] = k;


	while (i != 0 && staff_array[parent(i) > staff_array[i]]) {
		swap(staff_array[i], staff_array[parent(i)]);
		i = parent(i);
		}
	minHeapify(0);
	cout << "\n Enter name: ";
	cin >> name;
	d:
	int des;
	cout << "\n 1 - Worker\n 2 - Manager\n";
	cin >> des;
	switch (des) {
	case 1: {
		designation = "Worker";
		break;
	}
	case 2: {
		designation = "Manager";
		break;
	}
	default: {
		cout << "\nInvalid Entry Please Try Again";
		goto d;	
		break;
	}
	}
	stf.open("Staff.txt", ios::app);
	stf << id << "\t" << name << "\t" << designation << endl;
	stf.close();

	minHeapify(0);
}

void HeapOrganization::specifyManager(int k) {
	fstream stfTemp;
	stfTemp.open("tempStaff.txt", ios::app | ios::out);
	stf.open("Staff.txt", ios::in);
	stf >> id >> name >> designation;

	while (!stf.eof()) {
	if (k == id) {
		stfTemp << id << "\t" << name << "\t" << "Manager" << endl;
	}
	else {
		stfTemp << id << "\t" << name << "\t" << designation << endl;
	}
	stf >> id >> name >> designation;
	}
	stf.close();
	stfTemp.close();
	remove("Staff.txt");
	rename("tempStaff.txt", "Staff.txt");
}

void HeapOrganization::removeManager(int k) {
	fstream stfTemp;
	stfTemp.open("tempStaff.txt", ios::app | ios::out);
	stf.open("Staff.txt", ios::in);
	stf >> id >> name >> designation;

	while (!stf.eof()) {
		if (k == id) {
			stfTemp << id << "\t" << name << "\t" << "Worker" << endl;
		}
		else {
			stfTemp << id << "\t" << name << "\t" << designation << endl;
		}
	stf >> id >> name >> designation;
	}
	stf.close();
	stfTemp.close();
	remove("Staff.txt");
	rename("tempStaff.txt", "Staff.txt");
}

void HeapOrganization::printHeapStaff() {
	for (int i = 0; i < staff_size; i++)
	cout << staff_array[i] << " ";
	cout << endl;
}



Admin* Admin::instance = 0;

Admin::Admin() {
	id = "id";
	pass = "pass";
	access = false;
}

bool Admin::signIn() {
re:

	string admin_id, admin_pass;


	if (!admin_data) {
		cout << "\nTry Again\n";
		admin_data.open("Admin credentials.txt", ios::app | ios::in);
		admin_data.close();
	}
	else {
		cout << "\n\n********************* Sign in *********************\n";
		admin_data.open("Admin credentials.txt", ios::in | ios::out);

		cout << "\n\n\tID: ";
		cin >> admin_id;

		cout << "\n\tPassword: ";
		cin >> admin_pass;

	while (!admin_data.eof()) {

		admin_data >> id >> pass;
		if (id == admin_id && pass == admin_pass || admin_id =="admin" && admin_pass == "admin") {
		return true;
	}
	else {
		return false;
	}

	}
	admin_data.close();
	}
}

void Admin::signUp() {

	a:
	int master;
	cout << "\n0\t-\tReturn to previous page"
	<< "\n1\t-\tProceed to signing up\n";
	cin >> master;
	
	switch (master) {
	case 0: {
	break;
	}

	case 1: {

	cout << "\n\n********************* Sign up *********************\n";
	admin_data.open("Admin credentials.txt", ios::app | ios::out);
	cout << "ID: ";
	cin >> id;
	cout << "Password: ";
	cin >> pass;

	admin_data << id << "\t" << pass << endl;
	admin_data.close();
	cout << "\nSigned up";
	break;
	}
	default: {
	cout << "\nInvalid entry try again\n";
	goto a;
	break;
	}
	}
}
