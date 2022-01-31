#include<iostream>
#include<climits>

#include"FrontEnd.h"
#include"BackEnd.h"

using namespace std;

bool EventsList::MoveToNext() 
{
	if ((current == nullptr) || (current->next == nullptr))
		return false;

	current = current->next;
	return true;
}

bool EventsList::MoveToPrev()
{
	if ((current == nullptr) || (current->prev == nullptr))
		return false;

	current = current->prev;
	return true;
}

void EventsList::PushBack(DATA d)
{
	ELEMENT* e = new ELEMENT;
	e->data = d; //copy the data
	e->prev = last; // The previous element becomes last in the list
	e->next = nullptr; // The new element becomes last in the list

	if (first == nullptr) //checks if we add an element in an empty list
		first = e; //if true -> the new element becomes first in the list
	else
		last->next = e;

	last = e; //the new element becomes the last in the list
}

void EventsList::PushFront(DATA d)
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

bool EventsList::GetData(DATA& d)
{
	if (current == nullptr)
		return false;

	d = current->data;
	return true;
}

void EventsList::Remove()
{
	if (current == nullptr)
		return;

	ELEMENT* e = current->prev; //points to the element which is previous to the deleted

	if (e != nullptr) // checks if the deleted element has a previous one (if it isn't first)
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

	delete current;
}

bool EventsList::Set(DATA d)
{
	if (current == nullptr)
		return false;

	current->data = d;
	return true;
}

EventsList::DATA* EventsList::Find(DATA d)
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

EventsList::DATA* EventsList::Find()
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