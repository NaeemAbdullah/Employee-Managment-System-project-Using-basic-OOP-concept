#include <iostream>              
#include <windows.h>                 // For ClS
#include <conio.h>                   
#include <cstring>
#include <fstream>

using namespace std;

class veriable
{
	protected:
    // Variables for employee details
    char name[30];
    char dpartmnt[30];
    char id[5];
    char designation[10];
    int age,slry;
    char experience[20];
};

class insert: public veriable {   

  
  public:           // Access specifier
    insert() {     // Constructor
      
      system("cls");
    fstream file;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Insert Data -------------------------------------------" << endl;
    cout << "\n Enter Name of Employee: ";
    cin >> name;
    cout << "\n Enter Employee ID [max 4 digits]: ";
    cin >> id;
    cout << "\n Enter Designation: ";
    cin >> designation;
    cout << "\n Enter Employee Age: ";
    cin >> age;
    cout << "\n Enter Employee Salery: ";
    cin >> slry;
    cout << "\n Enter Employee Experience: ";
    cin >> experience;
    cout << "\n Enter Employee Department: ";
    cin >> dpartmnt;
    file.open("ems.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << designation << " " << age << " " << slry << " " << experience << " " << dpartmnt <<"\n";
    file.close();     
    }
};



class display: public veriable {
  public:
   display() // Display data of employe
{
    system("cls");
    int total = 1;
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Record Data ---------------------------------------------------" << endl;
    file.open("ems.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> slry >> experience>>dpartmnt;
        cout << "\n -------------------------------------------------------------------------------------------------------------------------";
        cout << "\n||    NAME    ||    ID    ||    DESIGNATION    ||    AGE    ||      SALLERY      ||    EXPERIENCE    ||    DEPARTMENT    ";
        cout << "\n -------------------------------------------------------------------------------------------------------------------------";
        while (!file.eof())
        {
            cout << "\n";
            cout << total++ << " \t" << name << "\t  " << id << "\t\t  " << designation << "\t\t   " << age << "\t\t  " << slry << "\t\t" << experience<< "\t\t" << dpartmnt;
            file >> name >> id >> designation >> age >> slry >> experience>>dpartmnt;
        }
    }
    file.close();
}
};

class update: public veriable
{
	public:  
     update() // Modify data of employe
{
    system("cls");
    char checkId[5];
    int found = 0;
    fstream file, file1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Modify Data ------------------------------------------" << endl;
    file.open("ems.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter employee id: ";
        cin >> checkId;
        file1.open("ems.txt", ios::app | ios::out);
        file >> name >>id >> designation >> age >> slry >>experience>>dpartmnt;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n Enter Name of Employee: ";
                cin >> name;
                cout << "\n Enter Employee ID [max 4 digits]: ";
                cin >> id;
                cout << "\n Enter Designation: ";
                cin >> designation;
                cout << "\n Enter Employee Age: ";
                cin >> age;
                cout << "\n Enter Employee sallery: ";
                cin >> slry;
                cout << "\n Enter Employee Experience: ";
                cin >> experience;
                cout << "\n Enter Employee department: ";
                cin >> dpartmnt;
                cout << "\n\nSuccessfully Modify Details Of Employee";
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << slry << " " << experience <<" "<< dpartmnt << "\n";
                found++;
            }
            else
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << slry << " " << experience << " " << dpartmnt<< "\n";
            }
            file >> name >> id >> designation >> age >> slry >> experience>>dpartmnt;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
    }
}
};

class search: public veriable
{
	public:
	 void search1() // Search data of employe
{                                  //Displays all details according to Employee's id
    system("cls");
    fstream file;
    char checkId[5];
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Employee Search Data -------------------------------------------" << endl;
    file.open("ems.txt", ios::in);
    cout << "\n\nEnter Employee ID: ";
    cin >> checkId;
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present... ";
        file.close();
    }
    else
    {
        file >> name >> id >> designation >> age >> slry >> experience>>dpartmnt;
        while (!file.eof())
        {
            if (strcmp(checkId, id) == 0)
            {
                cout << "\n---------------------\n";
                cout << "Employee Name: " << name << "\n";
                cout << "Employee ID.: " << id << "\n";
                cout << "Employee Designation: " << designation << "\n";
                cout << "Employee Age: " << age << "\n";
                cout << "Employee sallery: " << slry << "\n";
                cout << "Employee Experience: " << experience << "\n";
                 cout << "Employee department: " << dpartmnt << "\n";
                cout << "---------------------\n";
            }
            file >> name >> id >> designation >> age >> slry >> experience>>dpartmnt;
        }
    }
    file.close();
}
};



class deleted: public veriable
{
	public:
		void deleted_fun() // Delete data of employe
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Employee Data ------------------------------------------" << endl;
    file.open("ems.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Employee Id To Remove Data: ";
        cin >> checkId;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> id >> designation >> age >> slry >> experience>>dpartmnt;
        while (!file.eof())
        {
            if (strcmp(checkId, id) != 0)
            {
                file1 << " " << name << " " << id << " " << designation << " " << age << " " << slry << " " << experience << " " << dpartmnt << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> id >> designation >> age >> slry >> experience>>dpartmnt;
        }
        if (found == 0)
        {
            cout << "\n\n\tEmployee ID Not Found.. Please Try Again";
        }
        file1.close();
        file.close();
    }
}
};


class Empl_management
{
private:
    // Variables for employee details
    char name[30];
    char id[5];
    char designation[10];
    int age, ctc;
    char experience[20];

public:
    
void menu() //Project Menu
{
        int choice;
        char x; // Options to choose an action
        system("cls");
        cout << "\n\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t>> EMPLOYE MANAGEMENT SYSTEM <<" << endl;
        cout << "\t\t\t\t\t-------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Enter New Record" << endl;
        cout << "\t\t\t\t\t 2. Display Record" << endl;
        cout << "\t\t\t\t\t 3. Modify Record" << endl;
        cout << "\t\t\t\t\t 4. Search Record" << endl;
        cout << "\t\t\t\t\t 5. Delete Record" << endl;
        cout << "\t\t\t\t\t 6. Exit" << endl;

        cout << "\t\t\t\t\t.................................." << endl;
        cout << "\t\t\t\t\t>> Choice Options: [1/2/3/4/5/6] <<" << endl;
        cout << "\t\t\t\t\t.................................." << endl;
        cout << " Enter Your Choice: "; // Taking the action input
        cin >> choice;
        // Calling relevant function as per choice
        switch (choice)
        {
        case 1:
            
            {
                insert insrt_obj;
                cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
            }
			 if (x == 'y' || x == 'Y')
			 {
			 	insert insrt_obj;
			 }
			 else if (x == 'n' || x == 'N')
			 {
			 Empl_management obj;
        	obj.menu();	
			 }
			 else
			 {
			 	cout << "\n\n\t\t\t Invalid";
			 }
            break;
        case 2:
        	{
        	display dis;
			cout << "\n\n\t\t\t For Main Manu Press 1. ";
                cin >> x;	
			}
			if (x == '1')
			 {
			 	Empl_management obj;
        	obj.menu();
			 }
			 else
			 {
			 	cout << "\n\n\t\t\t Invalid No";
			 }
            
            break;
        case 3:
        	{
        	update up;	
        cout << "\n\n\t\t\t Update Another Employe Record Press (Y, N) : ";
                cin >> x;	
			}
			 if (x == 'y' || x == 'Y')
			 {
			 	update up;
			 }
			 else if (x == 'n' || x == 'N')
			 {
			 Empl_management obj;
        	obj.menu();	
			 }
			 else
			 {
			 	cout << "\n\n\t\t\t Invalid";
			 }
            
            break;
        case 4:
            {
            	search ser;
            	ser.search1();
        cout << "\n\n\t\t\t Search Another Employe Record Press (Y, N) : ";
                cin >> x;	
				
			
			 if (x == 'y' || x == 'Y')
			 {
			 	
            	search ser;
            	ser.search1();
			 }
			 else if (x == 'n' || x == 'N')
			 {
			 Empl_management obj;
        	obj.menu();	
			 }
			 else
			 {
			 	cout << "\n\n\t\t\t Invalid";
			 }
            	
			}
            break;
        case 5:
            {
            	deleted dell;
            	dell.deleted_fun();
            	cout << "\n\n\t\t\t Add Another Employe Record Press (Y, N) : ";
                cin >> x;
                 if (x == 'y' || x == 'Y')
			 {
			 	
            	deleted dell;
            	dell.deleted_fun();
            
			 }
			 else if (x == 'n' || x == 'N')
			 {
			 Empl_management obj;
        	obj.menu();	
			 }
			 else
			 {
			 	cout << "\n\n\t\t\t Invalid";
			 }
                
			}
            break;
        case 6:
            system("cls");
            cout << "\n\t\t\t>> EMPLOYE MANAGEMENT SYSTEM <<\n\n";
            Sleep(10);
            exit(0);
        default:
            cout << "\n\n\t\t\t Invalid Choice... Please Try Again...\n";
        }
        getch();
}
};


int main()
{
	Empl_management obj;
	
	obj.menu();
	
    return 0;  
}
