#pragma once
#include<vector>
#include<fstream>
#include<climits>
#include<string>

class EventsList {
public:
	struct DATA {
		int year;
		short month, day;
		char subject[121];
		char leader[31];
		char place[31];
	};

	struct ELEMENT {
		ELEMENT* next, * prev;
		DATA data;
	};

	EventsList() : current(nullptr), first(nullptr), last(nullptr) 
	{ 
		memset(&dataToFind, 0, sizeof(dataToFind));
		foundAdrs.clear();
	}
	~EventsList() 
	{ 
		eraseList(); 
		foundAdrs.clear();
	}

	void moveToFirst() { current = first; }
	void moveToLast() { current = last; }
	bool moveToNext();
	bool moveToPrev();
	bool getData(DATA& d);
	bool set(DATA d);

	void pushBack(DATA d);
	void pushFront(DATA d);
	void eraseList();
	void remove();

	DATA* find(DATA d);
	DATA* find();

	//Files
	bool saveToFile(std::string fileName);
	bool loadFromFile(std::string fileName);

	std::vector<ELEMENT*> foundAdrs; //Stores the addresses of the found events

private:
	DATA dataToFind;
	ELEMENT* current, * first, * last;
};