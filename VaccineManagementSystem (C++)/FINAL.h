#include <iostream>
#include<fstream> //for file handling
#include<string>
#include <math.h> 
#include <climits> 
using namespace std;

//citizen
struct node // node class structure for citizen
{
    string name;
    int priority;
    node* l; //next pointer
    int age;
    string gender;
    string id;

};

class Citizen //citizen class 
{
    node* front; //front pointer

public:

    Citizen() //constructor
    {
        front = NULL;
    }
    void enque(string mks, int sha, int age, string id, string gender) //enqueing data
    {
        node* temp, * khu;
        temp = new node;
        temp->name = mks;
        temp->priority = sha;
        temp->age = age;
        temp->id = id;
        temp->gender = gender;

        if (front == NULL || sha < front->priority)
        {
            temp->l = front;
            front = temp;
        }
        else
        {
            khu = front;
            while (khu->l != NULL && khu->l->priority <= sha)
                khu = khu->l;
            temp->l = khu->l;
            khu->l = temp;
        }
    }
    void deque() //dequeing
    {
        node* temp;
        if (front == NULL)
        {
            cout << "   Queue Underflow ";
        }
        else
        {
            temp = front;
            cout << "  Deleted Citizen  Name : " << temp->name << endl;
            front = front->l;

        }
    }

    void displayQueue() //showing data
    {
        node* display;
        display = front;
        if (front == NULL)
        {
            cout << " Its Empty, No data  ";
        }
        else
        {

            cout << endl;
            ofstream MyFile("CitizenDeatails.txt", ios::app); //file handling

            while (display != NULL)
            {
                MyFile << display->priority << "    -  " << display->name << "    - " << display->age << " years  - " << display->id << " - " << display->gender << endl;
                cout << display->priority << "    -  " << display->name << "    - " << display->age << " years  - " << display->id << " - " << display->gender << endl;
                display = display->l;
            }
            MyFile.close(); //file closing
        }
    }
};

class nodeMessage //node class structure for message class
{
public:
    string nameOfPersons;
    int priorityofmessage;
    nodeMessage* ln; //next pointer
    string messageOfPerson;

};

class CitizenMessage :public  Citizen //inheritance 
{
    nodeMessage* start;

public:

    CitizenMessage() //conntructor
    {
        start = NULL;
    }
    void enquingCitizenMessages(string p, int h, string q)
    {
        nodeMessage* tmp, * khubaib;
        tmp = new nodeMessage;
        tmp->nameOfPersons = p;
        tmp->priorityofmessage = h;

        tmp->messageOfPerson = q;


        if (start == NULL || h < start->priorityofmessage)
        {
            tmp->ln = start;
            start = tmp;
        }
        else
        {
            khubaib = start;
            while (khubaib->ln != NULL && khubaib->ln->priorityofmessage <= h)
                khubaib = khubaib->ln;
            tmp->ln = khubaib->ln;
            khubaib->ln = tmp;
        }
    }

    void displayMessage()
    {
        nodeMessage* disp;
        disp = start;
        if (start == NULL)
        {
            cout << " Its Empty, No data  ";
        }
        else
        {

            cout << endl;
            ofstream MyFile("GroupChat.txt", ios::app);
            while (disp != NULL)
            {
                MyFile << " \n\n *************** G R O U P  C H A T ******************* \n\n";
                MyFile << " \n " << disp->priorityofmessage << "     " << endl;
                cout << " \n " << disp->priorityofmessage << "     " << endl;
                MyFile << "\n Citizen's Name  :" << disp->nameOfPersons << "     " << endl;
                cout << " \n  Citizen's Name  :" << disp->nameOfPersons << "     " << endl;
                MyFile << "\n Citizen's Message  :" << disp->messageOfPerson << "   " << endl;
                cout << " \n  Citizen's Message  :" << disp->messageOfPerson << "   " << endl;
                cout << " \n Your Message has been deliverd !!\n";
                disp = disp->ln;

            }
            MyFile.close();
            cout << endl;
        }
    }

};

//manager

class subManager //Node class structure for manager class
{
public:
int centerNumber;
string centerName;
int capacityOfPersons;
subManager* next;
};

class Manager //Manager class structure
{
public:
string data;
Manager* left; //left pointer
Manager* right; //right pointer

Manager* newManager(string value) //initializing values
{
Manager* temp = new Manager;
temp->data = value;
temp->left = temp->right = NULL;
return temp;
}

void traversalOfManager(Manager* root) //preorder traversal of manager class
{
if (root != NULL)
{
cout << root->data << " -- ";
traversalOfManager(root->left);
traversalOfManager(root->right);
}
}

Manager* insertingTimeSlots(Manager* node) //inserting nodes in BST
{
string val;
cin >> val;
if (node == NULL)
return newManager(val);
if (val < node->data)
node->left = insertingTimeSlots(node->left); //recursively calling function
else if (val > node->data)
node->right = insertingTimeSlots(node->right);
return node;
}
};

class center //class center for center details
{
public:
string centerName;
int capacityOfPersons;
subManager* head, * tail;
center() //constructor
{
head = NULL;
tail = NULL;
}

void loginDetails() //login details 
{

start:
string user, pass;
cout << "          \n\n                   User name :   ";
cin >> user;
cout << "          \n\n                   Password :     ";
cin >> pass;
cout << " \n\n\n + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + + ";
if (user == "Haleema" && pass == "123456")
{
cout << "   \n\n Welcome Manager! You are successfully login into the system \n\n";
}
else
{
cout << " \n\n               Wrong password or username, Try Again \n\n";
goto start;
}
}

void insertingCenter(int d) //inserting data of center
{
cout << " \n\n Enter Center Number : ";
cin >> d;
cout << " \n\n Enter Center Name : ";
cin.ignore();
getline(cin, centerName);
//cin >> centerName;
cout << " \n\n Make sure " << centerName << " has maximum capacity of 10,000 persons" << endl;
cout << " \n\n Enter total number of person's in Vaccination Center : ";
cin >> capacityOfPersons;
if (capacityOfPersons > 10000)
cout << " \n\n Persons are out of capacity :( " << endl << endl;
subManager* temp = new subManager;
temp->centerNumber = d;
temp->centerName = centerName;
temp->next = NULL;
if (head == NULL)
{
head = temp;
tail = temp;
}

else
{
tail->next = temp;
tail = tail->next;
}
}

void displayingCenter() //displaying details
{
subManager* temp = head;
ofstream MyFile("centerInfo.txt",ios::app); //creating file
while (temp != NULL)
{
	MyFile << temp->centerNumber << " - ";
cout << temp->centerNumber << " - ";
MyFile << " Center Name : " << temp->centerName << " -  ";
cout << " Center Name : " << temp->centerName << " -  ";
MyFile << " Capacity : " << capacityOfPersons << "   " << endl << endl;
cout << " Capacity : " << capacityOfPersons << "   " << endl << endl;
temp = temp->next;
}
MyFile.close(); //closing file
cout << endl;
}
};


class messageNode//node class struture of message class
{
public:
    string personName;
    int priorityOfMessgae;
    messageNode* z; //next pointer
    string personsMessages;

};
class managerMessages :public Manager //messgaes using priority queues
{
    messageNode* frontMessage;
public:
    managerMessages() //constructor
    {
        frontMessage = NULL;
    }
    void enquingMessages(string m, int k, string s) //enequeing using priority queue
    {
        messageNode* temp, * khu;
        temp = new messageNode;
        temp->personName = m;
        temp->priorityOfMessgae = k;

        temp->personsMessages = s;


        if (frontMessage == NULL || k < frontMessage->priorityOfMessgae)
        {
            temp->z = frontMessage;
            frontMessage = temp;
        }
        else
        {
            khu = frontMessage;
            while (khu->z != NULL && khu->z->priorityOfMessgae <= k)
                khu = khu->z;
            temp->z = khu->z;
            khu->z = temp;
        }
    }

    void displayQueue() //displaying queue
    {
        messageNode* display;
        display = frontMessage;
        if (frontMessage == NULL)
        {
            cout << " Its Empty, No data  ";
        }
        else
        {
            cout << endl;
            ofstream MyFile("GroupChat.txt", ios::app); //creating file
            while (display != NULL)
            {
               MyFile << " \n " << display->priorityOfMessgae << "     " << endl;
                cout << " \n " << display->priorityOfMessgae << "     " << endl;
                MyFile << " \n Manager's Name  :" << display->personName << "     " << endl;
                cout << " \n Manager's Name  :" << display->personName << "     " << endl;
                MyFile << " \n Manager's Message  :" << display->personsMessages << "   " << endl;
                cout << " \n Manager's Message  :" << display->personsMessages << "   " << endl;
                display = display->z;

            }
            MyFile.close(); //closing file
            cout << endl;
        }
    }
};

//feedback
class feedBack
{
public:

	int key;
	string NAME;
	string CNIC;
	string feedbackk;

	feedBack()
	{
		key = -1;
	}
};

class feedBackClass :public Citizen //inheritance with citizen class
{
public:

	int capacity;
	int SIZE;
	feedBack* ptr;

	feedBackClass(int C)
	{
		capacity = C;
		SIZE = 0;
		ptr = new feedBack[capacity];
	}

	int hashFunction(int key) //hash function
	{
		int index = key % capacity;
		return index;
	}

	void insertionFeddBack(int k, string NAME, string CNIC, string feedbackk) //inserting using hashing by arrays
	{
		if (SIZE == capacity - 1)
		{
			cout << " \n\n LIMIT OVER \n\n";
		}

		else
		{
			int index = hashFunction(k);
			if (SIZE == 0)
			{
				ptr[index].key = k;
				ptr[index].NAME = NAME;
				ptr[index].CNIC = CNIC;
				ptr[index].feedbackk = feedbackk;
			}
			else
			{
				while (ptr[index].key != -1)
				{
					index = index + 1;
					if (index == capacity)
					{
						index = 0;
					}
				}

				ptr[index].key = k;
				ptr[index].NAME = NAME;
				ptr[index].CNIC = CNIC;
				ptr[index].feedbackk = feedbackk;
			}
			SIZE++;
		}
	}

	void showData() //displaying data
	{
		ofstream MyFile("feedback.txt",ios::app);
		MyFile << " Name - CNIC - FeedBack " << endl<<endl;
		cout << " Name - CNIC - FeedBack " << endl<<endl;
		for (int i = 0; i < capacity; i++)
		{
			if (ptr[i].key != -1)
			{
				MyFile << ptr[i].NAME << " - " << ptr[i].CNIC << " - " << ptr[i].feedbackk << endl;
				cout << ptr[i].NAME << " - " << ptr[i].CNIC << " - " << ptr[i].feedbackk << endl;
			}
		}
		MyFile.close(); //closing file
	}
	void Complement()
	{
		int e;
		cout << " \n How was the overall experience...\n\n";
		cout << " \n 1. Excellent\n";
	    cout << "\n  2. Great\n";
	    cout << " \n 3.Average\n";
		cout << "\n  4.Poor\n";
		cout<< " \n  5.Very Bad\n";
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
			cout << "Poor\n";
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

};


class HeapOrganization {    //Organization class
    public:
    int id = -1;
    string name;            //To save names in files
    string designation;     //To save desgination of emmployees in files

    int* centre_array;      
    int centre_capacity;
    int centre_size;

    int* staff_array;
    int staff_capacity;
    int staff_size;

    fstream org;            //organization file
    fstream stf;            //staff file

    HeapOrganization(int c_capacity, int s_capacity);   //Parameterised constructor

    //Supporting funtions
    void swap(int& a, int& b);      //swaping function  
    void minHeapify(int i);         //min heafify
    int left(int i);                
    int right(int i);               
    int parent(int i);

    //Vaccine Centers
    void displayOrganization();
    int centreIndex(int val);
    int removeVaccinationCentre(int v);
    void insertVaccinationCentre(int k);

    //Employees
    void displayStaff();
    int staffIndex(int val);
    int removeStaff(int v);
    void insertStaff(int k);
    void specifyManager(int k);
    void removeManager(int k);

    //to prove that heap is working 
    void printHeapStaff();

};



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

    bool signIn();
    void signUp();

};

