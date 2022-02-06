#include<iostream>
#include<windows.h>

#include"FrontEnd.h"
#include"BackEnd.h"

using namespace std;

void Menu::clearScreen()
{
	COORD cursor;

	cursor.X = 0;
	cursor.Y = 0;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Menu::gotoXY(int x, int y)
{
	COORD coords;

	coords.X = x;
	coords.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
}

void Menu::displayOptions()
{

}

void Menu::displayList()
{
	EventsList::DATA data1;
	list.MoveToFirst();

	while (list.GetData(data1) == true)
	{
		cout << data1.year << '-' << data1.month << '-' << data1.day << "  " << data1.subject << " " << data1.leader << " " << data1.place << endl;
		list.MoveToNext();
	}
}

void Menu::pushBack()
{

}

void Menu::pushFront()
{

}

void Menu::findEvents()
{

}

void Menu::changeInfo()
{

}

void Menu::deleteEvents()
{

}