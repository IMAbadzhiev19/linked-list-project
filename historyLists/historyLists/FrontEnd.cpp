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
	unsigned short y = 14, choice = 0;

	while (true)
	{
		gotoXY(0, 0); cout << "*--------------------------------------------------------------*" << endl;
		gotoXY(0, 1); cout << ":                                                              :" << endl;
		gotoXY(0, 2); cout << ":  _______  _______  _______  ___   _______  __    _  _______  :" << endl;
		gotoXY(0, 3); cout << ": |       ||       ||       ||   | |       ||  |  | ||       | :" << endl;
		gotoXY(0, 4); cout << ": |   _   ||    _  ||_     _||   | |   _   ||   |_| ||  _____| :" << endl;
		gotoXY(0, 5); cout << ": |  | |  ||   |_| |  |   |  |   | |  | |  ||       || |_____  :" << endl;
		gotoXY(0, 6); cout << ": |  |_|  ||    ___|  |   |  |   | |  |_|  ||  _    ||_____  | :" << endl;
		gotoXY(0, 7); cout << ": |       ||   |      |   |  |   | |       || | |   | _____| | :" << endl;
		gotoXY(0, 8); cout << ": |_______||___|      |___|  |___| |_______||_|  |__||_______| :" << endl;
		gotoXY(0, 9); cout << ":                                                              :" << endl;
		gotoXY(0, 10); cout << ":                                                              :" << endl;
		gotoXY(0, 11); cout << "*--------------------------------------------------------------*" << endl;

		gotoXY(25, 14); cout << "Display List";
		gotoXY(25, 15); cout << "Push to the end";
		gotoXY(25, 16); cout << "Push to the front";
		gotoXY(25, 17); cout << "Find event(s)";
		gotoXY(25, 18); cout << "Change event's info";
		gotoXY(25, 19); cout << "Delete event(s)" << endl;

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && y != 19)
		{
			gotoXY(22, y); cout << "  ";
			y++;
			gotoXY(22, y); cout << "-> ";
			choice++;
			continue;
		}

		if (GetAsyncKeyState(VK_UP) && y != 14)
		{
			gotoXY(22, y); cout << "  ";
			y--;
			gotoXY(22, y); cout << "-> ";
			choice--;
			continue;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");

			switch (choice)
			{

			case 0:
			{
				list.LoadFromFile(fileName);
				displayList();

				system("pause>nul");
			}break;

			case 1:
			{
				pushBack();
				list.SaveToFile(fileName);
			}break;

			case 2:
			{
				pushFront();
				list.SaveToFile(fileName);
			}break;

			case 3:
			{
				list.LoadFromFile(fileName);
				findEvents();
				system("pause>nul");
			}break;

			case 4:
			{

			}break;

			case 5:
			{

			}break;

			} //switch
		}
	}
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

	cout << "! IF YOU DON'T KNOW OR DON'T WANT TO GIVE DETAILS ABOUT THE DATE -> TYPE \"0\" !" << endl << "! IF YOU DON'T KNOW SOMETHING BELOW THE DATE PRESS ENTER !" << endl << endl;

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

	cout << "! IF YOU DON'T KNOW OR DON'T WANT TO GIVE DETAILS ABOUT THE DATE -> TYPE \"0\" !" << endl << "! IF YOU DON'T KNOW SOMETHING BELOW THE DATE PRESS ENTER !" << endl << endl;

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
	EventsList::DATA data, * dp;

	cout << "! (1)You can enter 0 if you want to ignore the date field !" << endl << "! (2)You can also enter an empty string if you want to ignore any of the fields below the date !" << endl << endl;

	cout << "Please enter the year of the event: "; cin >> data.year;
	cout << "Please enter the month of the event: "; cin >> data.month;
	cout << "Please enter the day of the event: "; cin >> data.day; cin.ignore();
	cout << "Please enter the name of the event: "; cin.getline(data.subject, sizeof(data.subject));
	cout << "Please enter the leader of the event: "; cin.getline(data.leader, sizeof(data.leader));
	cout << "Please enter the place where the event happened: "; cin.getline(data.place, sizeof(data.place));

	system("cls");
	list.MoveToFirst();
	for (dp = list.Find(data); dp != nullptr; dp = list.Find())
		cout << dp->year << " " << dp->month << " " << dp->day << " " << dp->subject << " " << dp->leader << " " << dp->place << endl;
}

void Menu::changeInfo()
{

}

void Menu::deleteEvents()
{

}