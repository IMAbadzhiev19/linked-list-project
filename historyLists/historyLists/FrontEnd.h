#pragma once
#include"BackEnd.h"

class Menu
{
public:
	void clearScreen();
	void gotoXY(int x, int y);

	void Login();
	void SignUp();
	void displaySigninOptions();

	void displayOptions();
	void displayList();
	void pushBack();
	void pushFront();
	void findEvents();
	void changeInfo();
	void deleteEvents();

private:
	EventsList list;
	std::string name;
};