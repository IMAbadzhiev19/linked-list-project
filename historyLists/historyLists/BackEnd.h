#pragma once

class EventsList {
public:
	struct DATA {
		int year;
		short month, day;
		char subject[120];
		char leader;
		char place;
	};

	EventsList() : current(nullptr), first(nullptr), last(nullptr) {}
	~EventsList() { Erase(); }
	
	bool MoveToFirst() { current = first; }
	bool MoveToLast() { current = last; }
	bool MoveToNext();
	bool MoveToPrev();
	bool GetData(DATA& d);

	void PushBack(DATA d);
	void PushFront(DATA d);
	void Set(DATA d);
	void Remove();
	void Erase();

private:
	struct ELEMENT {
		ELEMENT* next, * prev;
		DATA data;
	};

	ELEMENT* first, * current, * last;
};