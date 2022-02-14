#include<iostream>

#include"FrontEnd.h"
#include"BackEnd.h"

using namespace std;

int c = 0;

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

//Menu options
void Menu::displayOptions()
{
	system("cls");

	bool here2 = true;
	int y = 14, choice = 0;

	while (here2 == true)
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
		gotoXY(25, 19); cout << "Delete event(s)\n";
		gotoXY(25, 20); cout << "Go Back\n";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && y != 20)
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
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				else {
					list.loadFromFile(name + "-data");
					displayList();

					system("pause>nul");
					system("cls");
				}
			} break;
			case 1:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				{
					pushBack();
					list.saveToFile(name + "-data");
				}
			} break;
			case 2:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				{
					pushFront();
					list.saveToFile(name + "-data");
				}
			} break;
			case 3:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				else
				{
					list.loadFromFile(name + "-data");
					findEvents();
					system("pause>nul");
					system("cls");
				}
			} break;
			case 4:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				else
				{
					list.loadFromFile(name + "-data");
					changeInfo();
					list.saveToFile(name + "-data");
					system("cls");
				}
			} break;
			case 5:
			{
				if (name == "")
				{
					cout << "You must be logged into your account to use this benefits";
					Sleep(1500);
					displaySigninOptions();
				}
				else
				{
					list.loadFromFile(name + "-data");
					deleteEvents();
					list.saveToFile(name + "-data");
					system("cls");
				}
			} break;
			case 6:
			{
				displaySigninOptions();
				break;
			}break;
			} //switch
		}
	}
}

void Menu::displayList()
{
	EventsList::DATA data1;
	list.moveToFirst();

	while (list.getData(data1) == true)
	{
		cout << data1.year << "." << data1.month << '.' << data1.day << " |Subject - ";

		if (strlen(data1.subject) == 0)
			cout << "Unknown";
		else
			cout << data1.subject;

		cout << " |Leader - ";

		if (strlen(data1.leader) == 0)
			cout << "Unknown";
		else
			cout << data1.leader;

		cout << " |Place - ";

		if (strlen(data1.place) == 0)
			cout << "Unknown";
		else
			cout << data1.place;

		cout << endl;
		list.moveToNext();
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

	list.pushBack(data);
	system("cls");
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

	list.pushFront(data);
	system("cls");
}

void Menu::findEvents()
{
	EventsList::DATA data{ 0, 0, 0, "", "", "" }, * dp;

	cout << "! (1)You can enter 0 if you want to ignore the date field !" << endl << "! (2)You can also enter an empty string if you want to ignore any of the fields below the date !" << endl << endl;

	cout << "Please enter the year of the event: "; cin >> data.year;
	cout << "Please enter the month of the event: "; cin >> data.month;
	cout << "Please enter the day of the event: "; cin >> data.day; cin.ignore();
	cout << "Please enter the name of the event: "; cin.getline(data.subject, sizeof(data.subject));
	cout << "Please enter the leader of the event: "; cin.getline(data.leader, sizeof(data.leader));
	cout << "Please enter the place where the event happened: "; cin.getline(data.place, sizeof(data.place));

	system("cls");
	list.moveToFirst();
	for (dp = list.find(data); dp != nullptr; dp = list.find())
	{
		cout << dp->year << "." << dp->month << '.' << dp->day << " |Subject - ";

		if (strlen(dp->subject) == 0)
			cout << "Unknown";
		else
			cout << dp->subject;

		cout << " |Leader - ";

		if (strlen(dp->leader) == 0)
			cout << "Unknown";
		else
			cout << dp->leader;

		cout << " |Place - ";

		if (strlen(dp->place) == 0)
			cout << "Unknown";
		else
			cout << dp->place;

		cout << endl;
	}
}

void Menu::changeInfo()
{
	findEvents();

	int choice = 0, y = 2, size = list.foundAdrs.size();
	system("cls");

	for (int i = 0; i < size; i++)
	{
		gotoXY(4, y + i);
		cout << list.foundAdrs[i]->data.year << "." << list.foundAdrs[i]->data.month << '.' << list.foundAdrs[i]->data.day << " |Subject - ";

		if (strlen(list.foundAdrs[i]->data.subject) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.subject;

		cout << " |Leader - ";

		if (strlen(list.foundAdrs[i]->data.leader) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.leader;

		cout << " |Place - ";

		if (strlen(list.foundAdrs[i]->data.place) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.place;

	}

	while (true)
	{
		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && (choice < size - 1))
		{
			gotoXY(1, y + choice); cout << "   ";
			choice++;
			gotoXY(1, y + choice); cout << "-> ";

			continue;
		}
		else if (GetAsyncKeyState(VK_UP) && (choice > 0))
		{
			gotoXY(1, y + choice); cout << "   ";
			choice--;
			gotoXY(1, y + choice); cout << "-> ";

			continue;
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			break;
		}
	}

	EventsList::DATA d{ 0, 0, 0, "", "", "" };
	cout << "! IF YOU DON'T KNOW OR DON'T WANT TO GIVE DETAILS ABOUT THE DATE -> TYPE \"0\" !" << endl << "! IF YOU DON'T KNOW SOMETHING BELOW THE DATE PRESS ENTER !" << endl << endl;

	cout << "Please enter the year of the event: "; cin >> d.year;
	cout << "Please enter the month of the event: "; cin >> d.month;
	cout << "Please enter the day of the event: "; cin >> d.day; cin.ignore();
	cout << "Please enter the name of the event: "; cin.getline(d.subject, sizeof(d.subject));
	cout << "Please enter the leader of the event: "; cin.getline(d.leader, sizeof(d.leader));
	cout << "Please enter the place where the event happened: "; cin.getline(d.place, sizeof(d.place));

	list.moveTo(list.foundAdrs[choice]);
	list.set(d);

	system("cls");
}

void Menu::deleteEvents()
{
	findEvents();

	int choice = 0, y = 2, size = list.foundAdrs.size();
	system("cls");

	for (int i = 0; i < size; i++)
	{
		gotoXY(4, y + i);
		cout << list.foundAdrs[i]->data.year << "." << list.foundAdrs[i]->data.month << '.' << list.foundAdrs[i]->data.day << " |Subject - ";

		if (strlen(list.foundAdrs[i]->data.subject) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.subject;

		cout << " |Leader - ";

		if (strlen(list.foundAdrs[i]->data.leader) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.leader;

		cout << " |Place - ";

		if (strlen(list.foundAdrs[i]->data.place) == 0)
			cout << "Unknown";
		else
			cout << list.foundAdrs[i]->data.place;

	}

	while (true)
	{
		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && (choice < size - 1))
		{
			gotoXY(1, y + choice); cout << "   ";
			choice++;
			gotoXY(1, y + choice); cout << "-> ";

			continue;
		}

		if (GetAsyncKeyState(VK_UP) && (choice > 0))
		{
			gotoXY(1, y + choice); cout << "   ";
			choice--;
			gotoXY(1, y + choice); cout << "-> ";

			continue;
		}

		if (GetAsyncKeyState(VK_RETURN))
		{
			system("cls");
			break;
		}
	}

	list.moveTo(list.foundAdrs[choice]);
	list.remove();

	system("cls");
}

//Account
void Menu::displaySigninOptions()
{
	system("cls");

	bool here2 = true;
	int y = 14, choice = 0;

	while (here2 == true)
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


		gotoXY(25, 14); cout << "Login\n";
		gotoXY(25, 15); cout << "Sign in\n";
		gotoXY(25, 16); cout << "List options\n";
		gotoXY(25, 17); cout << "Quit";

		system("pause>nul");

		if (GetAsyncKeyState(VK_DOWN) && y != 17)
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
				Login();
			}break;
			case 1:
			{
				SignUp();
			}break;
			case 2:
			{
				displayOptions();
			} break;
			case 3:
			{
				system("cls");
				cout << "                                     YOU HAVE SUCCESSFULLY QUITED" << endl;
				exit(0);
			}break;
			}
		}
	}
}

void Menu::SignUp()
{
	string username, pass, repeated_pass, finalPassword;
	bool flag = false;

	while (flag != true)
	{
		system("cls");

		cout << "         -- SIGNIN --         " << endl;
		cout << " ---------------------------- " << endl;
		cout << "|          Username:         |" << endl;
		cout << "|         -> "; getline(cin, username); std::cout << "\033[F";
		cout << "|          Password:         |" << endl;
		cout << "|         -> "; getline(cin, pass);  std::cout << "\033[F";
		cout << "|       Confirm Password:    |" << endl;
		cout << "|         -> "; getline(cin, repeated_pass);  std::cout << "\033[F";
		cout << " ---------------------------- " << endl;

		ifstream temp;
		temp.open(username);

		if (temp)
		{
			system("cls");
			cout << "                         USERNAME ALREADY EXISTS" << endl;
			Sleep(1000);
		}
		else if (pass == repeated_pass && username != "" && pass != "")
			flag = true;
		else
		{
			system("cls");
			cout << "                         REPEATED PASSWORD DOESN'T MATCH THE ORIGINAL" << endl;
			Sleep(1000);
		}
	}

	ofstream fo;
	fo.open(username, ios::out);

	if (fo.fail()) {
		cout << "WRONG INFORMATION" << endl;
		Sleep(1000);
		displaySigninOptions();
	}
	else {
		fo << username << endl;

		for (size_t i = 0; i < pass.size(); i++)
		{
			string bin = decToBin(pass[i]);
			finalPassword += binaryToGray(bin);
		}

		fo << finalPassword << endl;
	}

	system("cls");
	cout << "YOU ARE ALL DONE, NOW WE ARE REDIRECTING YOU TO THE LOGIN PAGE";

	Sleep(2000);
	system("cls");
	Login();
}

void Menu::Login()
{
	string password, temp, result;
	bool flag = false;
	int checks, info;

	c++;
	if (c == 2)
	{
		system("cls");
		cout << "!!! YOU HAVE TO EXIT THE PROGRAM AND THAN LAUNCH IT AGAIN TO BE ABLE TO LOG INTO A DIFFERENT ACCOUNT !!!" << endl << endl;
		Sleep(2000);
		system("cls");
		cout << "                         We will log you out after a second";
		Sleep(1000);

		system("cls");
		cout << "                                     YOU HAVE SUCCESSFULLY QUITED" << endl;
		exit(0);
	}

	while (flag != true)
	{
		system("cls");
		cout << "!!! YOU HAVE TO EXIT THE PROGRAM AND THAN LAUNCH IT AGAIN TO BE ABLE TO LOG INTO A DIFFERENT ACCOUNT !!!" << endl << endl;

		checks = 0; 
		info = 1;

		cout << "      -- LOGIN --       " << endl;
		cout << " ---------------------- " << endl;
		cout << "|       Username:      |" << endl;
		cout << "|     -> "; getline(cin, name); std::cout << "\033[F";
		cout << "|       Password:      |" << endl;
		cout << "|     -> "; getline(cin, password);  std::cout << "\033[F";
		cout << " ---------------------- " << endl;

		ifstream fi;
		fi.open(name, ios::in);

		if (fi.fail()) {
			system("cls");
			cout << "                                 Username doesn't match!" << endl;
			Sleep(1500);
		}
		else {
			do {
				getline(fi, temp);

				if (info == 1)
				{
					if (name == temp)
					{
						checks++;
						info++;
					}
				}
				else if (info == 2)
				{
					for (size_t i = 0; i < password.size(); i++)
					{
						string bin = decToBin(password[i]);
						result += binaryToGray(bin);
					}

					if (result == temp)
						checks++;
				}


			} while (!fi.eof());
		}
		if (checks == 2 && password != "")
			flag = true;
		else {
			system("cls");
			cout << "                          Password doesn't match" << endl;
			Sleep(1000);
			displaySigninOptions();
		}
	}

	displayOptions();
}

//Gray's algorithm
string Menu::decToBin(int n)
{
	string bin;

	while (n != 0)
	{
		bin += to_string(n % 2);
		n /= 2;
	}

	reverse(bin.begin(), bin.end());

	return bin;
}

string Menu::binaryToGray(string bin)
{
	string gray = "";

	gray += bin[0];

	for (int i = 1; i < bin.length(); i++)
		gray += xor_func(bin[i - 1], bin[i]);

	return gray;
}