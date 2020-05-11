#include<iostream>
#include<string>
#include "worker.h"

using namespace std;

int main() {
	
	init();
	int action = 0;

	do
	{
		cout << "If you want to add worker press - 1 " << endl;
		cout << "If you want to show all workers press - 2" << endl;
		cout << "If you want to find workers by age/surname pres - 3" << endl;
		cout << "If you want to dell worker press - 5" << endl;
		cout << "If you want edit worker press - 6" << endl;
		cout << "If you want exit press - 7" << endl;
		cout << "Choose your action : ";
		cin >> action;
		switch ( action)
		{
		case 1:
			addWorker();
			break;
		case 2:
			showWorkers();
			break;
		case 3:
			findInfo();
			break;
		case 5:
			dellWorker();
			break;
		case 6:
			editWorker();
			break;
		default:
			break;
		}
	} while (action !=6);

	system("pause");
	return 0;

}