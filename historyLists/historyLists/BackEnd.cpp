#include<iostream>

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