#include<iostream>

#include"FrontEnd.h"
#include"BackEnd.h"

using namespace std;

//Used for the cursor
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

			} break;
			case 5:
			{

			} break;
			case 6:
			{
				displaySigninOptions();
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
	list.moveToFirst();
	for (dp = list.find(data); dp != nullptr; dp = list.find())
		cout << dp->year << " " << dp->month << " " << dp->day << " | " << dp->subject << " | " << dp->leader << " | " << dp->place << endl;
}

void Menu::changeInfo()
{

}

void Menu::deleteEvents()
{

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
	string username, pass, repeated_pass;
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

		if (pass == repeated_pass && username != "" && pass != "")
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

		string bin = decToBin(pass[0]);
		string bin1 = decToBin(pass[pass.size() - 1]);
		fo << (binaryToGray(bin) + pass.substr(1, pass.size() - 2) + binaryToGray(bin1)) << endl;
	}

	system("cls");
	cout << "YOU ARE ALL DONE, NOW WE ARE REDIRECTING YOU TO THE LOGIN PAGE";

	Sleep(2000);
	system("cls");
	Login();
}

void Menu::Login()
{
	string password, temp;
	bool flag = false;
	int checks, info;

	while (flag != true)
	{
		system("cls");

		checks = 0; info = 1;

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
			cout << "Username doesn't match!" << endl;
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
					string bin = decToBin(password[0]);
					string bin1 = decToBin(password[password.size() - 1]);
					string result = (binaryToGray(bin) + password.substr(1, password.size() - 2) + binaryToGray(bin1));

					if (result == temp)
						checks++;
				}


			} while (!fi.eof());
		}
		if (checks == 2 && password != "")
			flag = true;
		else {
			system("cls");
			cout << "Password doesn't match" << endl;
			Sleep(1000);
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

string Menu::grayToBinary(string gray)
{
	string binary = "";

	binary += gray[0];

	for (int i = 1; i < gray.length(); i++) {
		if (gray[i] == '0')
			binary += binary[i - 1];

		else
			binary += flip(binary[i - 1]);
	}

	return binary;
}

string Menu::binaryToGray(string bin)
{
	string gray = "";

	gray += bin[0];

	for (int i = 1; i < bin.length(); i++)
		gray += xor_func(bin[i - 1], bin[i]);

	return gray;
}