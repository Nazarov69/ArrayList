#include <iostream>
#include "ArrayList.h"
#include "Queue.h"
#include "Stack.h"
#include "MyException.h"

int main(){
	TArrayList<int> arrlist(30);
	int tmp;
	try{
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Filling the ArrayList with values from 1 to 10... \n";
		for (int i = 0; i < 10; i++)
			arrlist.PushFirst(i + 1);
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from end of ArrayList...\n";
		tmp = arrlist.GetLast();
		std::cout << "Element from end of ArrayList equals: " << tmp << "\n";
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from start of ArrayList...\n";
		tmp = arrlist.GetFirst();
		std::cout << "Element from start of ArrayList equals: " << tmp << "\n";
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Putting  25 to the 2nd index of ArrayList...\n";
		arrlist.Push(2, 25);
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
		std::cout << "Getting element from 2nd index of ArrayList...\n";
		tmp = arrlist.Get(2);
		std::cout << "Element from 2nd index of ArrayList equals: " << tmp << "\n";
		std::cout << "ArrayList is: ";
		if (arrlist.IsEmpty())
			std::cout << "empty.\n";
		else if (arrlist.IsFull())
			std::cout << "full.\n";
		else
			std::cout << "not empty and not full.\n";
	}

	catch (TMyException& ex){
		ex.What();
	}
	return 0;

	/*ArrayList is: empty.
Filling the ArrayList with values from 1 to 10...
ArrayList is: not empty and not full.
Getting element from end of ArrayList...
Element from end of ArrayList equals: 1
ArrayList is: not empty and not full.
Getting element from start of ArrayList...
Element from start of ArrayList equals: 10
ArrayList is: not empty and not full.
Putting  25 to the 2nd index of ArrayList...
ArrayList is: not empty and not full.
Getting element from 2nd index of ArrayList...
Element from 2nd index of ArrayList equals: 25
ArrayList is: not empty and not full.*/
}
