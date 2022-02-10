#include<iostream>
#include<fstream>
#include<climits>

#include"BackEnd.h"
#include"FrontEnd.h"

using namespace std;

bool EventsList::moveToNext()
{
	if (current == nullptr)
		return false;

	current = current->next;
	return true;
}

bool EventsList::moveToPrev()
{
	if (current == nullptr)
		return false;

	current = current->prev;
	return true;
}

void EventsList::pushBack(DATA d)
{
	ELEMENT* e = new ELEMENT;
	e->data = d; // copying the data
	e->prev = last; // The previous element becomes the last
	e->next = nullptr; // The new element becomes the last

	if (first == nullptr) // checks if we add element in empty list
		first = e; // the new elements become first in the list
	else
		last->next = e;

	last = e; // the new element is the last
}

void EventsList::pushFront(DATA d)
{
	ELEMENT* e = new ELEMENT;
	e->data = d;
	e->prev = nullptr;
	e->next = first;

	if (last == nullptr)
		last = e;
	else
		last->prev = e;

	first = e;
}

bool EventsList::getData(DATA& d)
{
	if (current == nullptr)
		return false;

	d = current->data;
	return true;
}

void EventsList::remove()
{
	if (current == nullptr)
		return;

	ELEMENT* e;
	e = current->prev; // point to the element which is previous to the deleted

	if (e != nullptr) // checks if the deleted element has a previous one (isn't first)
		e->next = current->next;
	else
	{
		e = current->next;

		if (e != nullptr)
			e->prev = nullptr;

		first = e;
	}

	e = current->next;

	if (e != nullptr)
		e->prev = current->prev;
	else
	{
		e = current->prev;

		if (e != nullptr)
			e->next = nullptr;

		last = e;
	}

	e = current;
	current = (current->next != nullptr) ? current->next : current->prev;

	delete e;
}

bool EventsList::set(DATA d)
{
	if (current == nullptr)
		return false;

	current->data = d;
	return true;
}

void EventsList::eraseList()
{
	ELEMENT* e;

	for (current = first; current != nullptr; current = e)
	{
		e = current->next;
		delete current;
	}

	first = nullptr;
	last = nullptr;
}

bool EventsList::saveToFile(string fileName)
{
	ofstream file;
	file.open(fileName, ios::out | ios::binary);

	if (file.fail())
		return false;

	for (ELEMENT* e = first; e != nullptr; e = e->next)
		file.write((char*)&(e->data), sizeof(DATA));

	file.close();
	return true;
}

bool EventsList::loadFromFile(string fileName)
{
	ifstream f;
	DATA d;

	f.open(fileName, ios::in | ios::binary);
	if (f.fail())
		return false;

	eraseList();
	while (true)
	{
		f.read((char*)&d, sizeof(DATA));
		if (f.eof())
			break;

		pushBack(d);
	}

	f.close();
	return true;
}

EventsList::DATA* EventsList::find(DATA d)
{
	dataToFind = d;

	for (current = first; current != nullptr; current = current->next)
	{
		if ((d.year != INT_MIN) && (d.year != current->data.year))
			continue;
		if ((d.month != 0) && (d.month != current->data.month))
			continue;
		if ((d.day != 0) && (d.day != current->data.day))
			continue;
		if ((d.subject[0] != 0) && (strcmp(d.subject, current->data.subject) != 0))
			continue;
		if ((d.leader[0] != 0) && (strcmp(d.leader, current->data.leader) != 0))
			continue;
		if ((d.place[0] != 0) && (strcmp(d.place, current->data.place) != 0))
			continue;

		return &(current->data); // an event meeting the creteria is found
	}

	return nullptr;
}

EventsList::DATA* EventsList::find()
{
	if (current == nullptr)
		return nullptr;

	for (current = current->next; current != nullptr; current = current->next)
	{
		if ((dataToFind.year != INT_MIN) && (dataToFind.year != current->data.year))
			continue;
		if ((dataToFind.month != 0) && (dataToFind.month != current->data.month))
			continue;
		if ((dataToFind.day != 0) && (dataToFind.day != current->data.day))
			continue;
		if ((dataToFind.subject[0] != 0) && (strcmp(dataToFind.subject, current->data.subject) != 0))
			continue;
		if ((dataToFind.leader[0] != 0) && (strcmp(dataToFind.leader, current->data.leader) != 0))
			continue;
		if ((dataToFind.place[0] != 0) && (strcmp(dataToFind.place, current->data.place) != 0))
			continue;

		return &(current->data); // an event meeting the creteria is found
	}

	return nullptr;
}