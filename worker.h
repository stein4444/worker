#pragma once
#include <iostream>
#include <string>
using namespace std;

struct worker
{
	string name;
	string surename;
	int years;
};
void init();
void findInfo();
void showWorkers();
void addWorker();
void editWorker();
void dellWorker();
void showSaved(int numb);