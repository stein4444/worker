#include "worker.h"
#include<list>
#include<string>
#include <fstream>


worker newWoker;
list<worker> workList;
string info = "Info.txt";
const string sveInfo = "Saves.txt";
void init()
{
	ifstream fin;
	fin.open(info);

	bool isOPen = fin.is_open();

	if (isOPen == false) {
		cout << "Error" << endl;
	}
	else {
		int currentString = 0;
		string data;
		worker listWorkers;
		while (!fin.eof()) {
			currentString++;
			getline(fin, data);

			if (currentString == 1) {
				listWorkers.name = data;
			}
			else if (currentString == 2)
			{
				listWorkers.surename = data;
				currentString = 0;
				workList.push_back(listWorkers);
				listWorkers = worker();
			}
			

		}

	}
	fin.close();
}

void findInfo(){
	int action = 0;
	ifstream fin;
	ofstream fout;
	fin.open(info, ios::in);
	fout.open(sveInfo, ios::app);
	worker info;
	do
	{
		cout << "If you want find workers by age press - 1" << endl;
		cout << "If you want to find workers by letter press - 2" << endl;
		cout << "If you want history of searching - 3" << endl;
		cout << "Back to main menu press - 4" << endl;
		cout << "choose your action: ";
		cin >> action;
		switch (action)
		{
		case 1: 
			int age;
			cout << "Enter age: ";
			cin >> age;
			
			if (!fin) {
				cout << "Cannot open file.\n";
			}
			else {
				worker item;
				while (fin >> item.name >> item.surename >> item.years)
				{
					if (age == item.years) {

						cout << item.name << " " << item.surename << endl;
						fout << age << endl;
						fout << item.name << " " << item.surename << endl;
					}
				}
			}
			fin.close();
			break;
		case 2:
			// кароче я не поняв як це зробити(((

			break;

		case 3: 
			showSaved(age);

			break;
		default:

			break;
		}

	} while (action !=4);
	
	
	fout.close();
}

void showWorkers()
{
	system("CLS");
	ifstream fin;
	fin.open(info, ios::in);
	worker info;
	if (!fin) {
		cout << "Cannot open file.\n";
	}
	else
	{
		int i = 0;
		while (fin >> info.name >> info.surename >> info.years)
		{
			i++;
			cout << "[" << i << "]" << info.name << " " << info.surename << " " << info.years << endl;


		}
	}
	fin.close();
}

void addWorker()
{
	system("CLS");
	int value;
	cout << "How many workers you want to add: ";
	cin >> value;
	ofstream fout;
	fout.open(info, ios::app);
	bool isOpen = fout.is_open();
	if (isOpen == false) {
		cout << "Error: Application can't connecting to database file!" << endl;
	}
	else {

		for (int i = 0; i < value; i++) {
			cout << "Enter worker name: ";
			cin >> newWoker.name;

			cout << "Enter worker surname: ";
			cin >> newWoker.surename;

			cout << "Enter worker age: ";
			cin >> newWoker.years;
			fout << newWoker.name << " " << newWoker.surename << " " << newWoker.years << endl;
			workList.push_back(newWoker);
		}
		fout.close();
	}
}

void editWorker()
{
	system("CLS");
	worker oldWorker;
	cout << "Enter surname who you want to edit: ";
	cin >> oldWorker.surename;
	cout << "Enter his name: ";
	cin >> oldWorker.name;
	cout << "Enter his age: ";
	cin >> oldWorker.years;
	worker editWorker;
	
	ifstream fin; 
	fin.open(info);

	ofstream temp;
	temp.open("temp.txt", ios:: app);
	cin.ignore();
	while (fin >> editWorker.name >> editWorker.surename >> editWorker.years)
	{
		if (editWorker.name != oldWorker.name && editWorker.surename != oldWorker.surename && editWorker.years != oldWorker.years)
			temp << editWorker.name << " "<< editWorker.surename << " " << editWorker.years << endl;
			
	}
	fin.close();
	temp.close();
	remove("Info.txt");
	rename("temp.txt", "Info.txt");

	
	cout << "Enter new name: ";
	cin >> editWorker.name;

	cout << "Enter new surname: ";
	cin >> editWorker.surename;

	cout << "Enter new age: ";
	cin >> editWorker.years;

	ofstream fout1;
	fout1.open("Info.txt", ios::app | ios::out);
	fout1 << editWorker.name<< " " << editWorker.surename<<" "<< editWorker.years << endl;
	fout1.close();
}

void dellWorker()
{
	system("CLS");
	worker oldWorker;
	cout << "Enter surname who you want to delete: ";
	cin >> oldWorker.surename;
	cout << "Enter his name: ";
	cin >> oldWorker.name;
	cout << "Enter his age: ";
	cin >> oldWorker.years;
	worker editWorker;

	ifstream fin;
	fin.open(info);

	ofstream temp;
	temp.open("temp.txt", ios::app);
	cin.ignore();
	while (fin >> editWorker.name >> editWorker.surename >> editWorker.years)
	{
		if (editWorker.name != oldWorker.name && editWorker.surename != oldWorker.surename && editWorker.years != oldWorker.years)
			temp << editWorker.name << " " << editWorker.surename << " " << editWorker.years << endl;

	}
	fin.close();
	temp.close();
	remove("Info.txt");
	rename("temp.txt", "Info.txt");

}

void showSaved(int numb)
{
	ifstream fin;
	string name, surname;
	fin.open(sveInfo, ios::in);
	if (!fin) {
		cout << "Cannot open file.\n";
	}
	else {
		while (fin >> numb >> name >> surname)
		{
			cout << "History: " << endl;
			cout << "age: " << numb << " " << name << " " << surname << endl;

		}
	}
	fin.close();
}

