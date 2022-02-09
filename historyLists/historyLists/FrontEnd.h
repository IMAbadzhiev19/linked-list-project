#pragma once
#include"BackEnd.h"

class Menu
{
public:
	Menu() { list.loadFromFile(fileName); }
	~Menu() { system("cls"); }

	void clearScreen();
	void gotoXY(int x, int y);

	void displayOptions();
	void displayList();
	void pushBack();
	void pushFront();
	void findEvents();
	void changeInfo();
	void deleteEvents();

private:
	EventsList list;
	std::string fileName = "history.txt";
};