#pragma once
#include"BackEnd.h"

class Menu
{
public:
	Menu() { list.LoadFromFile(fileName); }
	~Menu() { system("cls"); }

	void clearScreen();
	void gotoXY();

	void displayOptions();
	void displayList();
	void pushBack();
	void pusFront();
	void findEvents();
	void changeInfo();
	void deleteEvents();

private:
	EventsList list;
	string fileName = "history";
};