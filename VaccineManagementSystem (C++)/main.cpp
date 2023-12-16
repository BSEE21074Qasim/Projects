#include<iostream>
#include<string>
#include<fstream>
#include"FINAL.h"

using namespace std;

int main()
{
	
	int jerry;
	drain:
		cout<<"\n\n   Course : Data Structures & Algorithms   Semester  Project By   BSEE21025 -  BSEE21072 -  BSEE21074 \n\n";
	 cout << "\n\n     !!!!!!   C O V I D ' 1 9    V A C C I N A T I O N    M A N A G E M E N T    S Y S T E M   !!!!! \n\n";
	cout<<" \n\n                                      1 - Organization \n\n";
	cout<<" \n\n                                      2 - Manager \n\n";
	cout<<" \n\n                                      3 - Citizen \n\n";
	cout<< "\n\n                                      4 - Feed Back \n\n";
	cout<<" \n\n                                      5 - Exit \n\n";
	cin>> jerry;
	
	switch(jerry)
	{
		case 1:
			{
				
				Admin* s = s->getInstance();
HeapOrganization obj(100, 100);

int alpha;
if (s->signIn() == true) {
    a:
    int o;
    cout << "\n\n1 - Insert Vaccination Centre\t\t2 - Insert Employee\n\n3 - Remove Vaccination Centre\t\t4 - Remove Employee"
    << "\n\n5 - Promote to manager \t\t\t6 - Demote to worker\n\n7 - Display Vaccination Centres\t\t8 - Display Employees "
    << "\n\n9 - Add organisation accounts\n\n0 - Exit Organisation"
    << "\n\nEnter: ";
    cin >> o;

    switch (o) {
    case 1: {
        int val;
        cout << "\nEnter Centre id: ";
        cin >> val;
        obj.insertVaccinationCentre(val);
        goto a;
        break;
    }
    case 2: {
        int val;
        cout << "\nEnter Employee id: ";
        cin >> val;
        obj.insertStaff(val);
        goto a;
        break;
    }
    case 3: {
        int val;
        //obj.displayOrganization();
        cout << "\nEnter Centre id: ";
        cin >> val;
        obj.removeVaccinationCentre(val);
        goto a;
        break;
    }
    case 4: {
        int val;
        cout << "\nEnter Staff id: ";
        cin >> val;
        obj.removeStaff(val);
        goto a;
        break;
    }
    case 5: {
        int val;
        cout << "\nEnter Staff id: ";
        cin >> val;
        obj.specifyManager(val);
        goto a;
        break;
    }
    case 6: {
        int val;
        cout << "\nEnter Staff id: ";
        cin >> val;
        obj.removeManager(val);
        goto a;
        break;
    }
    case 7: {
        cout << "\n Vaccination Centres\n";
        obj.displayOrganization();
        goto a;
        break;
    }
    case 8: {
        cout << "\n Employees\n";
        obj.displayStaff();
        goto a;
        break;
    }
    case 9: {
        s->signUp();
        goto a;
        break;
    }
    case 0: {
        goto drain;
        break;
    }
    default: {
        cout << "\nInvalid Entry please try again";
        break;
    }
    }
    }
    else {
        cout << "\nYou are not authorised to proceed";
        goto drain;
    }


z:
				goto drain;
				break;
			}
		case 2: // case 2 of Manager
			{
				cout << "\n\n !!!!!!   C O V I D ' 1 9    V A C C I N A T I O N    M A N A G E M E N T    S Y S T E M   !!!!! \n\n";
                Manager* m;
center objectOfCenter;
objectOfCenter.loginDetails(); //choice 1

int star;
hehe:
cout << " \n\n1 - To Manage Vaccination Centers \n\n";
cout << " \n\n2 - To Specify Timings For Vaccination \n\n";
cout<<"  \n\n 3 - For Chatting in Group \n\n";
cout << " \n\n4 - To Log Out From System \n\n";
cin >> star;
switch (star)
{
case 1:
{
objectOfCenter.insertingCenter(1); //choice 1
cout << endl;
objectOfCenter.displayingCenter();
goto hehe;
break;
}
case 2:
{
string apm;//choice 2
cout << " \n\n Enter era of Day (am / pm) for making time slots :  ";
cin >> apm;
cout << " \n\n Enter any 10 hours you want to make slots for Vaccination " << endl;
Manager* root = NULL;
root = m->insertingTimeSlots(root);
m->insertingTimeSlots(root);
m->insertingTimeSlots(root);
m->insertingTimeSlots(root);
cout << " \n\n Vaccination Time Slots Are : " << endl << endl;
m->traversalOfManager(root);
cout << endl << endl;
goto hehe;
break;
}

case 3:
	{
    managerMessages mObject;
    int caps;
    hexa:
    cout << " \n\n Chatting Of Manager In Group\n\n";
    cout << " \n \n    1 - Send & Display Message \n\n";
    cout << " \n\n     2 - To Exit From Chatting \n\n";
    cin >> caps;

    switch (caps)
    {
    case 1:
    {
        string nameX, messageX;
        int priorityX;
        cout << " Enter Manager's Name       : ";
        cin.ignore();
        getline(cin, nameX);
        cout << " Enter Manager's Priority   : ";
        cin >> priorityX;
        cout << " Enter your message   : ";
        cin.ignore();
        getline(cin, messageX);
        mObject.enquingMessages(nameX, priorityX, messageX);
        mObject.displayQueue();
        goto hexa;
        break;
    }
    default:
        cout << " \n\n Exited \n\n";
        goto hehe;
        break;
    } 
	}
default:
cout << "\n\n You are Logged Out \n\n";
break;

}
goto drain;
				break;
			}
			
			case 3: // case 3 of citizen
				{
					int entry;
    string name;
    int priority;
    int age;
    string id;
    string gender;

    Citizen cz;

gt:

    cout << endl;
    //cout << "\n\n !!!!!!   C O V I D ' 1 9    V A C C I N A T I O N    M A N A G E M E N T    S Y S T E M   !!!!! \n\n";
    cout << "\n\n  W e l c o m e      C i t i z e n \n\n";
    cout << "  \n\n                   1 - To Enter the Details Of Citizen \n\n ";
    cout << "  \n\n                   2 - To Delete the Details Of Citizen  \n\n";
    cout << "  \n\n                   3 - To Display the Details Of Citizn \n\n";
    cout << " \n\n                    4 - For Chatting in Group \n\n";
    cout << "  \n\n                   5 - To Exit from Registration Process  \n\n";
    cin >> entry;

    switch (entry)
    {
    case 1:
    {
        cout << "_____________________________________________________" << endl;
        cout << "|            Age Group   |       Vaccine Type       |" << endl;
        cout << "|________________________|__________________________|" << endl;
        cout << "|             1 - 18     |           Pfizer         |" << endl;
        cout << "|             19 - 60    |           Sinopharm      |" << endl;
        cout << "|              60 +      |           Moderna        | " << endl;
        cout << "|________________________|__________________________|" << endl << endl << endl;


        cout << " Enter Citizen's Name       : ";
        cin.ignore();
        getline(cin, name);

        cout << " Enter Citizen's Priority   : ";
        cin >> priority;
        cout << " Enter Citizen's Age        : ";
        cin >> age;
        if (age <= 18)
            cout << " Vaccine Type : Pfizer" << endl;
        else if (age > 18 && age <= 60)
            cout << " Vaccine Type : Sinopharm" << endl;
        else
            cout << " Vaccine Type : Moderna" << endl;
        cout << " Enter Citizen's CNIC       : ";
        cin >> id;
        cout << " Enter Gender (male/female) : ";
        cin >> gender;
        cz.enque(name, priority, age, id, gender);
        goto gt;
        break;
    }

    case 2:
    {
        cz.deque();
        goto gt;
        break;
    }

    case 3:
    {
        cz.displayQueue();
        goto gt;
        break;
    }
    case 4:
    {

        int enter;
        string nameofCitizen;
        int priorituofMessage;
        string messageofCitizens;
        CitizenMessage ms;


        cout << endl;
        cout << " ____________________________________________________________________ ";
        cout << "\n\n                    W e l c o m e      C i t i z e n \n\n";
        cout << "  \n\n               1-   To     Enter    in     Citizen's    Chat  \n\n ";
        cout << " ____________________________________________________________________ " << endl << endl;
        cin >> enter;

        switch (enter)
        {
        case 1:
        {
            int citi;

        pak:
            cout << " \n Hello Citizen \n";
            cout << "\n 1- For send message \n";
            cout << "\n 2- For display message \n";
            cout << "\n 3- To exit from citizen's chat \n";
            cin >> citi;
            switch (citi)
            {
            case 1:
            {
                cout << " Enter Citizen's Name       : ";
                cin.ignore();
                getline(cin, nameofCitizen);
                cout << " Enter Citizen's Priority   : ";
                cin >> priorituofMessage;
                cout << " Enter your message   : ";
                cin.ignore();
                getline(cin, messageofCitizens);
                ms.enquingCitizenMessages(nameofCitizen, priorituofMessage, messageofCitizens);
                goto pak;
                break;

            }
            case 2:
            {
                ms.displayMessage();
                goto pak;
                break;
            }
            default:
                break;
            }

        }
        }
        goto gt;
        break;
    }

    case 5:
    {
        cout << " \n\n You Are Exited \n\n";
        break;
    }

    default:
        cout << " \n\n Invalid input";
    }
    goto drain;
					break;
				}
	
    
    case 4: // feedback class case 4
    	{
    		feedBackClass fbc(50);
	fbc.Complement();
	cout << " \n\n                !!!   F E E D B A C K     T I M E     !!!              \n\n";
	cout << " \n\n Kindly write few words about your overall experince at Center \n\n ";
	string Namee, Cnicc, feedbackkk;
	cout << "\n\n Enter your name : ";
	cin.ignore();
	getline(cin, Namee);
	cout << "\n\n Enter your Cnic : ";
	cin >> Cnicc;
	cout << "\n\n Enter Your FeedBack : ";
	cin.ignore();
	getline(cin, feedbackkk);
	fbc.insertionFeddBack(2, Namee, Cnicc, feedbackkk);
	cout << endl << endl;
	fbc.showData();

    		goto drain;
    		break;
		}
    default:
    	cout<< " To Exit the Program "<<endl;
    	break;
    }
}
