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
	EventsList::DATA data;

	cout << "! IF YOU DON'T KNOW OR DON'T WANT TO GIVE DETAILS ABOUT THE DATE -> TYPE \"0\" !" << endl << "! FOR SOMETHING BELOW THE DATE PRESS ENTER !" << endl << endl;

	cout << "Please enter the year of the event: "; cin >> data.year;
	cout << "Please enter the month of the event: "; cin >> data.month;
	cout << "Please enter the day of the event: "; cin >> data.day; cin.ignore();
	cout << "Please enter the name of the event: "; cin.getline(data.subject, sizeof(data.subject));
	cout << "Please enter the leader of the event: "; cin.getline(data.leader, sizeof(data.leader));
	cout << "Please enter the place where the event happened: "; cin.getline(data.place, sizeof(data.place));

	list.PushBack(data);
}

void Menu::pushFront()
{
	EventsList::DATA data;

	cout << "! IF YOU DON'T KNOW OR DON'T WANT TO GIVE DETAILS ABOUT THE DATE -> TYPE \"0\" !" << endl << "! FOR SOMETHING BELOW THE DATE PRESS ENTER !" << endl << endl;

	cout << "Please enter the year of the event: "; cin >> data.year;
	cout << "Please enter the month of the event: "; cin >> data.month;
	cout << "Please enter the day of the event: "; cin >> data.day; cin.ignore();
	cout << "Please enter the name of the event: "; cin.getline(data.subject, sizeof(data.subject));
	cout << "Please enter the leader of the event: "; cin.getline(data.leader, sizeof(data.leader));
	cout << "Please enter the place where the event happened: "; cin.getline(data.place, sizeof(data.place));

	list.PushFront(data);
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