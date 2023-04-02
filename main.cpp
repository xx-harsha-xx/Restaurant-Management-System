//#include<iostream>
#include<conio.h>
/*#include<fstream>
include<cstring>
#include<string>*/
#include<windows.h>
#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

//Start of Functions
void clearScreen()
{
	system("cls");
	cout<<"Press CTRL+C to Quit The Program"<<endl;
}

void wait()
{
	Sleep(1000);
}

void printMainMenu()
{
	clearScreen();
	cout<<"Menu"<<endl;
	cout<<"1. Admin"<<endl;
	cout<<"2. Employee"<<endl;
	cout<<"3. Customer"<<endl;	
	cout<<"4. Exit"<<endl;
}

void printAdminMenu(int choice)
{
	clearScreen();
	if(choice)
	{
		cout<<"Admin Menu"<<endl;
		cout<<"1. Login "<<endl;
		cout<<"2. Sign-Up "<<endl;
		cout<<"3. Previous Menu "<<endl;
	}
	else
	{
		cout<<"Admin Menu"<<endl;
		cout<<"1. Add Employee "<<endl;
		cout<<"2. View Employees "<<endl;
		cout<<"3. Delete Employee "<<endl;
		cout<<"4. View Menu "<<endl;
		cout<<"5. Add Items "<<endl;
		cout<<"6. Remove Items "<<endl;
		cout<<"7. View Orders "<<endl;
		cout<<"8. Edit Details"<<endl;
		cout<<"9. Logout "<<endl;
	}
}

void printEmployeeMenu()
{
	clearScreen();
	cout<<"Employee Menu"<<endl;
	cout<<"1. Login "<<endl;
	cout<<"2. Sign-Up "<<endl;
	cout<<"3. Previous Menu "<<endl;
}
void printEmployeeMenu(int choice)
{
	clearScreen();
	cout<<"Employee Menu"<<endl;
	cout<<"1. View Details "<<endl;
	cout<<"2. Edit Details"<<endl;
	cout<<"3. View Orders "<<endl;
	cout<<"4. Logout "<<endl;
}

void printCustomerMenu(int choice)
{
	clearScreen();
	if(choice == 1)
	{
		cout<<"\tAdd"<<endl;
		cout<<"1. View Staters "<<endl;
		cout<<"2. View Main Course "<<endl;
		cout<<"3. View Deserts "<<endl;
		cout<<"4. View Drinks "<<endl;
		cout<<"5. Previous Menu "<<endl;
	}
	else if(choice == 3)
	{
		cout<<"\tAdd"<<endl;
		cout<<"1. View Staters "<<endl;
		cout<<"2. View Main Course "<<endl;
		cout<<"3. View Deserts "<<endl;
		cout<<"4. View Drinks "<<endl;
		cout<<"5. Calculate Bill"<<endl;
		cout<<"6. Previous Menu "<<endl;
	}
}

void printAddMenu()
{
	clearScreen();
	cout<<"Add Items"<<endl;
	cout<<"1. Starter "<<endl;
	cout<<"2. Main Course "<<endl;
	cout<<"3. Dessert "<<endl;
	cout<<"4. Drinks "<<endl;
	cout<<"5. Previous Menu "<<endl;
}

int getIdPassword()
{
	clearScreen();
	int id;
	cout<<"Enter ID: "<<endl;
	cin>>id;
	cout<<"Enter Password: "<<endl;
	return id;
}

void editDetailsMenu()
{	
	cout<<"What you want Edit"<<endl;
	cout<<"1. Name"<<endl;
	cout<<"2. DOB"<<endl;
	cout<<"3. Address"<<endl;
}
//End of Functions

//Start of Employee Class
class Employee
{
	private:
		int tips;
	public:
		int empId;
		char password[8];
		string dob, empName, address;
	Employee()
	{
		tips  = 0;
	}
	void getEmpDetails()
	{
		cout<<"Enter the Details"<<endl;
		cout<<"ID: ";
		cin>>empId;
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout<<"Name: ";
		getline(cin, empName);
		cout<<"DOB(DD-MM-YYYY): ";
		cin>>dob;
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout<<"Address: ";
		getline(cin, address);
	}
	
	void storeEmpData()
	{
		ofstream fout;
		fout.open("employee-detail.txt", ios::app);
		fout<<empId<<" "<<empName<<" "<<dob<<" "<<address<<" "<<tips<<endl;
		fout.close();
	}
	//Admin Login
	int login(int empId, string password)
	{
		int passwordSize = password.length();
		char tempPassword[passwordSize + 1];
		strcpy(tempPassword, password.c_str());
		ifstream fin;
		string line;
		fin.open("id-pass.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, line))
			{
			//	getline(fin,line);
				int fileEmpId = 0;
				int size = line.length();
				char empDetails[size+1], filePassword[100] = {};
				int temp = 0, i=0, j=0, count = 0, c=0;
				strcpy(empDetails, line.c_str());
				while((temp = empDetails[i++]) != 32)
					fileEmpId = fileEmpId * 10 + (temp - 48);
				//i++;
				while(i<size)
				{
					filePassword[j] = empDetails[i];
					j++;
					i++;
					count ++;	
				}				
				filePassword[j] = '\0';
				if(fileEmpId == empId && ((empId / 100) == 1))
				{
					if(!strcmp(filePassword,tempPassword))
					{
						return 1;
					}
				}
				
			}
			fin.close();
		}
		return 0;
	}
	
	//Employee Login
	int login(int empId, string password, int emp)
	{
		int passwordSize = password.length();
		char tempPassword[passwordSize + 1];
		strcpy(tempPassword, password.c_str());
		ifstream fin;
		string line;
		fin.open("id-pass.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, line))
			{
				int fileEmpId = 0;
				int size = line.length();
				char empDetails[size+1], filePassword[100] = {};
				int temp = 0, i=0, j=0, count = 0, c=0;
				strcpy(empDetails, line.c_str());
				while((temp = empDetails[i++]) != 32)
					fileEmpId = fileEmpId * 10 + (temp - 48);
				while(i<size)
				{
					filePassword[j] = empDetails[i];
					j++;
					i++;
					count ++;	
				}				
				filePassword[j] = '\0';
				if(fileEmpId == empId && ((empId / 100) == 2))
				{
					if(!strcmp(filePassword,tempPassword))
					{
						return 1;
					}
				}
				
			}
			fin.close();
		}
		return 0;
	}
	
	
	void signUp()
	{
		empId = getIdPassword();
		for(int i = 0;i<8;i++)
		{
			password[i] = getch();
			putch('*');
		}
		password[8] = '\0';
		wait();
		ifstream fin;
		string line;
		fin.open("employee-detail.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, line))
			{
				int fileEmpId = 0;
				for(int i = 0;i < 3; i++)
					fileEmpId = fileEmpId* 10 + (line[i] - 48);
				if(fileEmpId == empId)
				{
					ofstream fout;
					fout.open("id-pass.txt", ios::app);
					fout<<empId<<" "<<password<<endl;
					fout.close();
					cout<<"\nEmployee Added!!!"<<endl;
					return ;
				}
			}
			fin.close();
			cout<<"\nEmployee Does Not Exist "<<endl;
		}
	}

	// View  Orders
	void viewOrders()
	{
		clearScreen();
		ifstream fin, fm;
		string rLine, mLine;
		fin.open("Orders.txt", ios::in);
		if(fin.is_open())
		{
			cout<<"|"<<setfill('-')<<setw(32)<<"Orders"<<setfill('-')<<setw(27)<<"|"<<endl;
			cout<<setfill(' ')<<setw(12)<<"Order Id."<<setw(23)<<"Items Name"<<setw(21)<<"Quantity"<<endl;	
			while(getline(fin, rLine))
			{
				int orderId = 0, temp = 0, i = 0, count = 0, itemId = 0, quantity = 0;
				while((temp = rLine[i++]) != 32)
					orderId = orderId * 10 + (temp - 48);
				itemId =  (rLine[i++] - 48) * 100 + (rLine[i++] - 48) * 10 + (rLine[i++] - 48);
				i++;
				quantity = rLine[i];
				fm.open("items-details.txt", ios::in);
				while(getline(fm, mLine))
				{
					int j = 0;
					char itemName[30] = " ";
					int fileItemId = (mLine[j++] - 48) * 100 + (mLine[j++] - 48) * 10 + (mLine[j++] - 48);
					if(fileItemId == itemId)
					{
						int count = 0;
						for(int k = 4; !isdigit(mLine[k]);k++)
						{
							itemName[count++] = mLine[k];
						}
						itemName[count] = '\0';
						cout<<right<<setw(9)<<orderId<<setw(13 + count)<<itemName<<setw(30 - count)<<rLine[i]<<endl;
					}
				}
					fm.close();
			}
		}
		else
			cout<<setfill('-')<<setw(30)<<" No Orders "<<setw(41);
		fin.close();
	}

	void viewDetails(int empId)
	{
		clearScreen();
		ifstream fin;
		string rLine;
		fin.open("employee-detail.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, rLine))
			{
				int i = 0, fileEmpId = (rLine[i++] - 48) * 100 + (rLine[i++] - 48) * 10 + (rLine[i++] - 48);
				char empName[50] = {' '}, dob[10] = {' '}, address[100] = {' '};
				if(fileEmpId == empId)
				{
					int size = rLine.length();
					char empDetails[size+1];
					strcpy(empDetails, rLine.c_str());
					empDetails[size+1] = '\0';
					int count = 0, k = 4, j = 0;
					for(k; !isdigit(empDetails[k]);k++)
					{
						empName[count++] = empDetails[k];
					}
					empName[count] = '\0';
					k++;
					for(j;!isalpha(empDetails[k]);j++)
					{
						dob[j] = empDetails[k++];
					}
					dob[j] = '\0';
					j = 0;
					while(empDetails[k] != ' ')
					{
						address[j++] = empDetails[k++];
					}
					address[j] = '\0';
					cout<<setw(27)<<"Details"<<setw(20)<<endl;
					cout<<setw(47)<<setfill('-')<<"-"<<endl;
					cout<<setfill(' ')<<left<<setw(20)<<"  Employee Name : "<<right<<empName<<endl;
					cout<<left<<setw(20)<<"  Employee Id : "<<right<<empId<<endl;
					cout<<left<<setw(20)<<"  DOB : "<<right<<dob<<endl;
					cout<<left<<setw(20)<<"  Address : "<<right<<address<<endl;
				}
			}
			fin.close();
		}
	}

	void editDetails(int empId)
	{
		clearScreen();
		int choice;
		string newEmpName, newDOB, newAddress;
		cout<<"Enter the details"<<endl;
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout<<"Name: ";
		getline(cin, newEmpName);
		cout<<"DOB(DD-MM-YYYY): ";
		cin>>newDOB;
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout<<"Address: ";
		getline(cin, newAddress);

		ifstream fin;
		string rLine;
		ofstream fout;
		fin.open("employee-detail.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, rLine))
			{
				int fileEmpId = 0;
				int size = rLine.length();
				char empD[size+1];
				int temp = 0, i=0;
				strcpy(empD, rLine.c_str());
				while((temp = empD[i++]) != 32)
					fileEmpId = fileEmpId * 10 + (temp - 48);
				if(fileEmpId != empId)
				{
					fout.open("temp.txt", ios::app);
					fout<<rLine<<endl;
					fout.close();
				}
			}
			fin.close();
		}
		remove("employee-detail.txt");
		rename("temp.txt","employee-detail.txt");

		fout.open("employee-detail.txt", ios::app);
		if(fout.is_open())
		{
			fout<<empId<<" "<<newEmpName<<" "<<newDOB<<" "<<newAddress<<" "<<"0"<<endl;
		}
		fout.close();
	}
};

//Start of Admin Class
class Admin : public Employee
{
	public:
		int noOfEmployees;
	
	void getAdminDetails()
	{
		signUp();
		ifstream fin;
		ofstream fout;
		string line;
		int count = 0 ;
		fin.open("employee-detail.txt", ios::in);
		while(getline(fin, line))
		{
			count++;
		}
		noOfEmployees = count;
		fin.close();
		fin.open("employee-detail.txt", ios::in);
		if(fin.is_open())
		{
			while(getline(fin, line))
			{
				int fileEmpId = 0;
				int size = line.length();
				char empD[size+1];
				int temp = 0, i=0;
				strcpy(empD, line.c_str());
				while((temp = empD[i++]) != 32)
					fileEmpId = fileEmpId * 10 + (temp - 48);
				if(fileEmpId ==  empId)
				{
					fout.open("manager-details.txt", ios::out);
					fout<<line<<" "<<noOfEmployees<<endl;
					fout.close();
				}
			}
			fin.close();
		}
		else
		{
			cout<<"Error"<<endl;
		}
	}
	
	char readEmpData()
	{
		clearScreen();
		ifstream fin;
		ofstream fout;
		string rLine;
		cout<<setw(40)<<"Details"<<setw(43)<<endl;
		cout<<setw(80)<<setfill('-')<<"-"<<endl;
		cout<<setfill(' ')<<setw(8)<<"ID"<<setw(22)<<"Name"<<setw(21)<<"DOB"<<setw(20)<<"Address"<<endl;
		cout<<setw(80)<<setfill('-')<<"-"<<endl;
		fin.open("employee-detail.txt", ios::in);
		while(getline(fin, rLine))
		{
			int fileEmpId  = (rLine[0] - 48) * 100 + (rLine[1] - 48)* 10 + (rLine[2] - 48);
			int size = rLine.length();
			char empDetails[size+1];
			int temp = 0, i=0;
			strcpy(empDetails, rLine.c_str());
			char empName[50] = {' '}, dob[10] = {' '}, address[100] = {' '};
			empDetails[size+1] = '\0';
			int count = 0, k = 4, j = 0, l =0;
			for(k; !isdigit(empDetails[k]);k++)
			{
				empName[count++] = empDetails[k];
			}
			empName[count] = '\0';
			for(j;!isalpha(empDetails[k]);j++)
			{
				dob[j] = empDetails[k++];
			}
			dob[j] = '\0';
			while(empDetails[k] != ' ')
			{
				address[l++] = empDetails[k++];
			}
			address[l] = '\0';
			cout<<setfill(' ')<<setw(9)<<fileEmpId<<setw(32)<<empName<<setw(15)<<dob<<setw(15)<<address<<endl;
		}
		fin.close();
		cout<<"Press E to Exit"<<endl;
		char e = tolower(getch());
		return e;
	}
	
	void deleteEmp()
	{
		int tempEmpId;
		cout<<"Enter EmpID: ";
		cin>>tempEmpId;
		
		ifstream fin;
		string rLine;
		ofstream fout;
		fin.open("employee-detail.txt", ios::in);
		if(fin.is_open())
		{
		while(getline(fin, rLine))
		{
			int fileEmpId = 0;
			int size = rLine.length();
			char empD[size+1];
			int temp = 0, i=0;
			strcpy(empD, rLine.c_str());
			while((temp = empD[i++]) != 32)
				fileEmpId = fileEmpId * 10 + (temp - 48);
			if(fileEmpId != tempEmpId)
			{
				fout.open("temp.txt", ios::app);
				fout<<rLine<<endl;
				fout.close();
			}
		}
		fin.close();
		}
		remove("employee-detail.txt");
		rename("temp.txt","employee-detail.txt");
	}
	
};
//End of Admin Class

//Start Food Items
class FoodItemType
{
	public:
		int chickenItemPrice, vegItemPrice;
		char itemType;
	void getFoodItemType()
	{
		cout<<"Enter Food Item Type(Non-Veg:n/Veg:v): ";
		cin>>itemType;
		itemType = tolower(itemType);
		if(itemType == 'n')
		{
			cout<<"Non-Veg(chicken) Item Price: ";
			cin>>chickenItemPrice;
		}
		if(itemType == 'v')
		{
			cout<<"Veg Item Price: ";
			cin>>vegItemPrice;
		}
	}
};

class FoodItem
{
	public:
		int itemCode;
		float itemPrice;
		string itemName;
	
	void getFoodItem()
	{
		cout<<"Enter Food Item Code: ";
		cin>>itemCode;
		cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		cout<<"Enter Food Item Name: ";
		getline(cin, itemName);
		cout<<"Enter Food Item Price: ";
		cin>>itemPrice;
	}
	void removeFoodItem()
	{
		int tempItemId;
		cout<<"Enter Item Code : ";
		cin>>tempItemId;
		
		ifstream fin;
		string rLine;
		ofstream fout;
		fin.open("items-details.txt", ios::in);
		if(fin.is_open())
		{
		while(getline(fin, rLine))
		{
			int fileItemId= 0;
			for(int i = 0;i < 3; i++)
				fileItemId = fileItemId * 10 + (rLine[i] - 48);
			if(fileItemId != tempItemId)
			{
				fout.open("temp.txt", ios::app);
				fout<<rLine<<endl;
				fout.close();
			}
		}
		fin.close();
		}
		remove("items-details.txt");
		rename("temp.txt","items-details.txt");
	}

	void displayFoodItem(int choice)
	{
		clearScreen();
		ifstream fin;
		string line;
		fin.open("items-details.txt", ios::in);
		cout<<"|"<<setfill('-')<<setw(24)<<"Menu"<<setfill('-')<<setw(21)<<"|"<<endl;
			int count = 1;
		while(getline(fin, line))
		{
			string itemName;
			int itemPrice = 0;
			int i = 3;
			char temp = line[i];
			while(!(isdigit(temp))  || temp == ' ' )
			{
				itemName += line[i++];
				temp = line[i];
			}
			while(temp != ' ')
			{
				itemPrice = itemPrice * 10 + (line[i++] - 48);
				temp = line[i];
			}
			int fileItemId = 0;
			for(int i = 0;i < 3; i++)
				fileItemId = fileItemId * 10 + (line[i] - 48);
			if((fileItemId / 100) == choice)
				cout<<setfill(' ')<<setw(4)<<count++<<"."<<itemName<<setw(38-itemName.length())<<itemPrice<<endl;
		}
		cout<<"Press 0 to exit"<<endl;
		fin.close();
	wait();
	}
};

class Starter : public FoodItem, public FoodItemType
{
	float starterPrice;
	public:
	
	void addStarter()
	{
		clearScreen();
		getFoodItem();
		getFoodItemType();
		if(itemType == 'n')
			starterPrice = itemPrice + chickenItemPrice;
		if(itemType == 'v')
			starterPrice = itemPrice + vegItemPrice;
		
	}
	
	void storeStarters()
	{
		ofstream fout;
		fout.open("items-details.txt", ios::app);
		fout<<itemCode<<" "<<itemName<<" "<<starterPrice<<" "<<itemType<<endl;
		fout.close();
	}
};
//Main Course
class MainCourse: public FoodItem
{
	float mainCoursePrice;
	float portion;
	public:
	
	void addMainCourse()
	{
		clearScreen();
		getFoodItem();
		cout<<"Enter portions(half:0.5/full:1): ";
		cin>>portion;
		mainCoursePrice = itemPrice  * portion;
	}
	
	void storeMainCourse()
	{
		ofstream fout;
		fout.open("items-details.txt", ios::app);
		fout<<itemCode<<" "<<itemName<<" "<<mainCoursePrice<<" "<<portion<<endl;
		fout.close();
	}
};
//Dessert 
class Dessert: public FoodItem
{
	float dessertPrice;
	public:
	
	void addDessert()
	{
		clearScreen();
		getFoodItem();
		dessertPrice  = itemPrice ;
	}
	
	void storeDessert()
	{
		ofstream fout;
		fout.open("items-details.txt", ios::app);
		fout<<itemCode<<" "<<itemName<<" "<<dessertPrice<<" "<<endl;
		fout.close();
	}
};

class Drink: public FoodItem
{
	float drinkPrice;
	int drinkQuantity;
	public:
	
	void addDrink()
	{
		clearScreen();
		getFoodItem();
		cout<<"Enter the quantity(ml): ";
		cin>>drinkQuantity;
		drinkPrice  = itemPrice ;
	}
	
	void storeDrink()
	{
		ofstream fout;
		fout.open("items-details.txt", ios::app);
		fout<<itemCode<<" "<<itemName<<" "<<drinkPrice<<" "<<drinkQuantity<<endl;
		fout.close();
	}
};

class Order
{
	public:
		int orderId, noOfItems, noOfStarters, noOfMainCourse, noOfDessert, noOfDrinks, loopCount, tempItemId, itemId ;
		string orderItems[1];

		void getOrder(int typeChoice)
		{
			ifstream fin, fRead;
			ofstream fout;
			string rLine, wLine, itemName;

			fin.open("items-details.txt", ios::in);
			while(getline(fin, rLine))
			{
				int temp = rLine[0] - 48;
				if(typeChoice == temp)
				{
					fout.open("temp-menu.txt", ios::app);
					fout<<rLine<<endl;
					fout.close();
				}
			}
			fin.close();
			int i = 0;
			fout.open("Orders.txt",ios::app);
			// fout<<endl;
			fout<<orderId;
	 		cout<<"Enter the Item: ";
			cin>>tempItemId;
			if(tempItemId == 0)
			{
				cout<<"Going to previous Menu"<<endl;
				wait();
			}
			else
			{
				fin.open("temp-menu.txt",ios::in);				
				while(getline(fin,rLine))
				{
					int temp = ((rLine[1] - 48)*10)+ (rLine[2] - 48);
					if(tempItemId == temp)
					{
						itemId = typeChoice * 100 + temp;
						fout<<" "<<itemId;
						break;
					}
				}
				cout<<"Enter the Number of portions: ";
				cin>>loopCount;
				fout<<" "<<loopCount<<endl;
				fout.close();
			}
			remove("temp-menu.txt");


		}
};

class Bill
{
	public:
		string itemNames[20];
		int itemCosts[20], itemQuantities[20], itemPrices[20], totalItemCount = 0;

		void calculateBill()
		{
			int noOfOrders, srNo = 0;
				int orderId;
				cout<<"Enter Order ID : ";
				cin>>orderId;
				ifstream fin, idFin;
				string rLine, idRLine;
				fin.open("Orders.txt", ios::in);
				while(getline(fin,rLine))
				{
					int fileOrderId = 0, i = 0, temp = 0, fileItemId = 0, itemCost = 0;
					char itemName[30] = " ";
					while((temp = rLine[i++]) != 32)
						fileOrderId = fileOrderId * 10 + (temp - 48);
					if(fileOrderId == orderId)
					{
						int itemId = 0;
						while((temp = rLine[i++]) != 32)
							itemId = itemId * 10 + (temp - 48);
						idFin.open("items-details.txt", ios::in);
						while(getline(idFin, idRLine))
						{
							int j = 0;
							itemName[30] = {' '};
							fileItemId = (idRLine[j++] - 48) * 100 + (idRLine[j++] - 48) * 10 + (idRLine[j++] - 48);
							if(fileItemId == itemId)
							{
								int count = 0, k = 4;
								for(k = 4; !isdigit(idRLine[k]);k++)
								{
									itemName[count++] = idRLine[k];
								}
								itemName[count] = '\0';
								while((temp = idRLine[k++]) != 32)
									itemCost = itemCost * 10 + (temp - 48);
								itemNames[srNo] = itemName;
								itemCosts[srNo] = itemCost;
								itemQuantities[srNo] = rLine[i] - 48;
								itemPrices[srNo++] = (itemCost * (rLine[i] - 48));
								totalItemCount++;
							}
						}
						idFin.close();
					}
				}
				fin.close();
			return;
		}

		void showBill()
		{
			clearScreen();
			cout<<setw(63)<<setfill('=')<<"="<<endl;
			cout<<setfill(' ')<<setw(32)<<"Bill"<<endl;
			cout<<setw(63)<<setfill('=')<<"="<<endl;
			cout<<setfill(' ')<<setw(8)<<"Sr. No"<<setw(16)<<"Item"<<setw(17)<<"Price"<<setw(12)<<"Quantity"<<setw(8)<<"Cost"<<endl;
			cout<<setw(63)<<setfill('-')<<"-"<<endl;
			int total = 0.00 ;
			for(int i = 0 ; i < totalItemCount; i++)
			{
				cout<<setfill(' ')<<setw(5)<<(i+1)<<setw(itemNames[i].length() + 10)<<itemNames[i]<<setw(25 - itemNames[i].length())<<itemCosts[i]<<setw(9)<<itemQuantities[i]<<setw(12)<<itemPrices[i]<<endl;
				total = total + itemPrices[i];
			}
			cout<<setw(63)<<setfill('-')<<"-"<<endl;
			int gst = total * 18 / 100, grandTotal = total + gst + gst;
			cout<<setfill(' ')<<setw(50)<<"Total"<<setw(10)<<total<<endl;
			cout<<setw(50)<<"SGST(18%)"<<setw(10)<<gst<<endl;
			cout<<setw(50)<<"CGST(18%)"<<setw(10)<<gst<<endl;
			cout<<setw(50)<<"Grand Total"<<setw(10)<<grandTotal<<endl;
		}
};

int main()
{
	clearScreen();
	int mainMenuchoice = 0, adminMenuChoice = 0, employeeMenuChoice = 0, customerMenuChoice = 0, empId, adminSubMenuChoice = 0, loopCount = 1, employeeSubMenuChoice = 0, addItemChoice = 0, addItemToMenu = 0;
	char password[8] = {0}, e;
	Employee emp;
	Admin admin;
	Starter s;
	MainCourse mc;
	Dessert des;
	Drink dri;
	FoodItem fi;
	Order o;
	Bill bill;

	while(mainMenuchoice != 4)
	{
		mainMenu : printMainMenu();
		cin>>mainMenuchoice;
		// mainMenuchoice = 1;
		switch(mainMenuchoice)
		{
			//MainMenu case 1
			case 1:
	AdminMenu : printAdminMenu(1);
				cin>>adminMenuChoice;
				// adminMenuChoice = 1;
				switch(adminMenuChoice)
				{
					//AdminMainMenu Case 1
					AdminLogin : case 1:
						empId = getIdPassword();
						for(int i = 0;i<8;i++)
						{		
							password[i] = getch();
							putch('*');
						}
						// if(admin.login(empId, password))
						if(1)
						{
			AdminSubMenu : printAdminMenu(0);
							cin>>adminSubMenuChoice;
							// adminSubMenuChoice = 7;
							switch(adminSubMenuChoice)
							{
								//AdminSubMenu case 1
								case 1:
									cout<<"No of Employees to be Added: ";
									cin>>loopCount;
									for(int i = 0;i < loopCount; i++)
									{
										emp.getEmpDetails();
										emp.storeEmpData();
										cout<<"Employee Added !!!"<<endl;
										Sleep(500);
									}
									
									goto AdminSubMenu;
									break;
								//AdminSubMenu case 2
								case 2:
									admin.readEmpData();
									if(e == 'e')
										goto AdminSubMenu;
									goto AdminSubMenu;
									break;
								//AdminSubMenu case 3
								case 3:
									cout<<"Delete Employee"<<endl;
									admin.deleteEmp();
									wait();
									goto AdminSubMenu;
									break;
								//AdminSubMenu case 4
								case 4:
									cout<<"View Menu"<<endl;
							here:	printCustomerMenu(1);
									cin>>customerMenuChoice;
									if(customerMenuChoice == 5)
										goto AdminSubMenu;
									else
									{
										fi.displayFoodItem(customerMenuChoice);
										e = getch();
										if(e == '0')
											goto here;
									}
									break;
								//AdminSubMenu case 5
								case 5:
									do
									{
										printAddMenu();
										cin>>addItemChoice;
										switch(addItemChoice)
										{
											case 1:
												cout<<"No of items to be Added: ";
												cin>>loopCount;
												for(int i = 0;i < loopCount; i++)
												{
													s.addStarter();
													s.storeStarters();
													cout<<"Starter Added !!!"<<endl;
													wait();
												}
												break;
											case 2:
												cout<<"No of items to be Added: ";
												cin>>loopCount;
												for(int i = 0;i < loopCount; i++)
												{
													mc.addMainCourse();
													mc.storeMainCourse();
													cout<<"Main Course Added !!!"<<endl;
													wait();
												}
												break;
											case 3:
												cout<<"No of items to be Added: ";
												cin>>loopCount;
												for(int i = 0;i < loopCount; i++)
												{
													des.addDessert();
													des.storeDessert();
													cout<<"Dessert Added !!!"<<endl;
													wait();
												}
												break;
											case 4:
												cout<<"No of items to be Added: ";
												cin>>loopCount;
												for(int i = 0;i < loopCount; i++)
												{
													dri.addDrink();
													dri.storeDrink();
													cout<<"Drink Added !!!"<<endl;
													wait();
												}
												break;
											case 5:
												goto AdminSubMenu;
												break;
											default :
												cout<<"Wrong Input !!!"<<endl;
										}
									}										
									while(addItemChoice != 4);
									break;
								//AdminSubMenu case 6
								case 6:
									cout<<"No of items to be Removed: ";
									cin>>loopCount;
									for(int i = 0;i < loopCount; i++)
									{
										cout<<"Delete Items"<<endl;
										fi.removeFoodItem();
										cout<<"!!! Item Removed !!!"<<endl;
										wait();
									}
									goto AdminSubMenu;
									break;
									
								//AdminSubMenu case 7
								case 7:
									cout<<"View Orders"<<endl;
									admin.viewOrders();
									cout<<"\nPress E to Exit"<<endl;
									e = tolower(getch());
									if(e == 'e')
										goto AdminSubMenu;
									goto AdminMenu;
									break;
								//AdminSubMenu case 8
								case 8:
									admin.editDetails(empId);
									cout<<"Details Saved"<<endl;
									break;
								//AdminSubMenu case 9
								case 9:
									cout<<"Logging Out"<<endl;
									wait();
									goto AdminMenu;
									break;
								//adminSubMenuDelault
								default :
									cout<<"Wrong Input"<<endl;
									goto AdminSubMenu;
							}
						}
						else
						{
							cout<<"Incorrect ID/Password"<<endl;
							wait();
							goto AdminLogin;
						}
							
						break;
					//AdminMainMenu Case 2
					case 2:
						cout<<"Admin Sign-Up"<<endl;
						admin.getAdminDetails();
						break;						
					//AdminMainMenuDefault
					case 3:
						cout<<"Going to previous Menu"<<endl;
						wait();
						goto mainMenu;
						
					default:
						cout<<"Wrong Input"<<endl;
					
				}
				break;
			//MainMenu case 2
			case 2:
				EmployeeMenu : printEmployeeMenu();
				cin>>employeeMenuChoice;
				switch(employeeMenuChoice)
				{
					//Employee MainMenu Case 1
	EmployeeLogin : case 1:
						empId = getIdPassword();
						for(int i = 0;i<8;i++)
						{
							password[i] = getch();
							putch('*');
						}
						if(emp.login(empId, password, 2))
						{
		EmployeeSubMenu :	printEmployeeMenu(0);
							cin>>employeeSubMenuChoice;
							switch(employeeSubMenuChoice)
							{
								case 1:
									emp.viewDetails(empId);
									cout<<"\nPress E to Exit"<<endl;
									e = tolower(getch());
									if(e == 'e')
										goto EmployeeSubMenu;
									goto EmployeeSubMenu;
									break;
								case 2:
									emp.editDetails(empId);
									cout<<"Details Saved"<<endl;
									wait();
									break;
								case 3:
									cout<<"View Orders"<<endl;
									emp.viewOrders();
									cout<<"\nPress E to Exit"<<endl;
									e = tolower(getch());
									if(e == 'e')
										goto EmployeeSubMenu;
									goto EmployeeSubMenu;
									break;
								case 4 :
									cout<<"Logging Out"<<endl;
									wait();
									goto EmployeeMenu;
									break;
								//Employee Sub Menu Delault
								default :
									cout<<"Wrong Input"<<endl;
									goto EmployeeSubMenu;
							}
						}
						else
						{
							cout<<"Incorrect ID/Password"<<endl;
							wait();
							goto EmployeeLogin;
						}
						break;
					case 2:
						emp.signUp();
						break;
					case 3:
						cout<<"Going to previous Menu"<<endl;
						wait();
						goto mainMenu;
						break;
						
				}
				break;
			//MainMenu case 3
			case 3:
				srand(time(0));
				o.orderId = rand()%1000;
customerMenu : printCustomerMenu(3);
				cin>>customerMenuChoice;
				switch(customerMenuChoice)
				{
					case 1:
						fi.displayFoodItem(customerMenuChoice);
						cout<<"Your order id is: "<<o.orderId<<endl;
						o.getOrder(customerMenuChoice);
						wait();
						goto customerMenu;
						break;
					case 2:
						fi.displayFoodItem(customerMenuChoice);
						cout<<"Your order id is: "<<o.orderId<<endl;
						o.getOrder(customerMenuChoice);
						wait();
						goto customerMenu;
						break;
					case 3:
						fi.displayFoodItem(customerMenuChoice);
						cout<<"Your order id is: "<<o.orderId<<endl;
						o.getOrder(customerMenuChoice);
						wait();
						goto customerMenu;
						break;
					case 4:
						fi.displayFoodItem(customerMenuChoice);
						cout<<"Your order id is: "<<o.orderId<<endl;
						o.getOrder(customerMenuChoice);
						wait();
						goto customerMenu;
						break;
					case 5:
						bill.calculateBill();
						bill.showBill();
						cout<<"\nPress E to Exit"<<endl;
						e = tolower(getch());
						if(e == 'e')
							goto customerMenu;
						goto customerMenu;
						break;
					case 6:
						cout<<"Going to previous Menu"<<endl;
						wait();
						goto mainMenu;
					default :
						cout<<"Wrong Input"<<endl;
				}
				break;
			//MainMenu case 4
			case 4:
				cout<<"Thank You"<<endl;
				exit(1);
			//MainMenuDefault
			default :
				cout<<"Wrong Input"<<endl;
				wait();
		}
	}
	return 0;
}