#pragma once

class EventsList {
public:
	struct DATA {
		int year;
		short month, day;
		char subject[121];
		char leader[31];
		char place[31];
	};

	EventsList() : current(nullptr), first(nullptr), last(nullptr) {}
	~EventsList() { EraseList(); }
	
	bool MoveToFirst() { current = first; }
	bool MoveToLast() { current = last; }
	bool MoveToNext();
	bool MoveToPrev();
	bool GetData(DATA& d);
	bool Set(DATA d);

	void PushBack(DATA d);
	void PushFront(DATA d);
	void Remove();
	void EraseList();

	DATA* Find(DATA d);
	DATA* Find();

	//Files
	bool SaveToFile(std::string fileName);
	bool LoadFromFile(std::string fileName);

private:
	struct ELEMENT {
		ELEMENT* next, * prev;
		DATA data;
	};

	ELEMENT* first, * current, * last;
	DATA dataToFind;
};