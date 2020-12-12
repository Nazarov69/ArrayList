#pragma once
#include "ArrayList.h"
#include <iostream>
using namespace std;

template <class ValType>
class ArrayIterator{
protected:
	ArrayList<ValType>& arlist;
	int ind;
public:
	ArrayIterator(ArrayList<ValType>& list, int ind = -2);
	ArrayIterator(ArrayIterator<ValType>& v);
	~ArrayIterator();

	ValType GetArray();
	int GetIndex();

	bool IsGoNext();
	void GoNext();

	ArrayIterator<ValType>& operator = (const ArrayIterator<ValType>& v);
	bool operator == (const ArrayIterator<ValType>& v);
	ArrayIterator<ValType>& operator++();
};

template<class ValType>
ArrayIterator<ValType>::ArrayIterator(ArrayList<ValType>& list, int ind) : arlist(list){
	this->ind = ind;
}

template<class ValType>
ArrayIterator<ValType>::ArrayIterator(ArrayIterator<ValType>& v){
	this->arlist = v.arlist;
	this->ind = v.ind;
}

template<class ValType>
ArrayIterator<ValType>::~ArrayIterator(){
	ind = -2;
}

template<class ValType>
bool ArrayIterator<ValType>::IsGoNext(){
	return (ind >= 0)	
}

template<class ValType>
void ArrayIterator<ValType>::GoNext(){
	if (this->IsGoNext())
		ind = arlist.pointers[ind];
	else 
		throw logic_error("Input error: invalide value of ArrayIterator length in GoNext");
}

template<class ValType>
ArrayIterator<ValType>& ArrayIterator<ValType>::operator=(const ArrayIterator<ValType>& v){
	this->arlist = v.arlist;
	this->ind = v.ind;

	return (*this);
}

template<class ValType>
bool ArrayIterator<ValType>::operator==(const ArrayIterator<ValType>& v){
	return (this->ind == v.ind && *(this->arlist) == *(v.arlist))
}

template<class ValType>
ArrayIterator<ValType>& ArrayIterator<ValType>::operator++(){
	GoNext();
	return (*this);
}

template<class ValType>
ValType ArrayIterator<ValType>::GetArray(){
	if (ind < 0)
		throw logic_error("Input error: invalide value of ArrayIterator length in GetArray");

	return arlist.array[ind];
}

template<class ValType>
int ArrayIterator<ValType>::GetIndex(){
	return ind;
}