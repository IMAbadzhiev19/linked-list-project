#pragma once
#include<conio.h>
#include<windows.h>

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

	//Used for gray's algorithm
	std::string decToBin(int n);
	char xor_func(char a, char b) { return (a == b) ? '0' : '1'; } //does xor operation
	char flip(char c) { return (c == '0') ? '1' : '0'; } //changes the bits to the opposite one
	std::string grayToBinary(std::string gray);
	std::string binaryToGray(std::string bin);

private:
	EventsList list;
	std::string name;
};