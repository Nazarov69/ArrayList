#pragma once
#include <iostream>
#include "Queue.h"
#include "MyException.h"

template <class ValType>
class TArrayList{
	ValType* mas;
	int* nextIndex;
	int* prevIndex;
	int length;
	int first;
	int last;
	int count;
	TQueue<int> fElem;
public:
	TArrayList(int length = 10);
	TArrayList(TArrayList<ValType>& v);
	~TArrayList();

	void Push(int index, ValType elem);
	void PushFirst(ValType elem);
	void PushLast(ValType elem);

	ValType Get(int index);
	ValType GetFirst();
	ValType GetLast();

	bool IsFull();
	bool IsEmpty();
};

template <class ValType>
TArrayList<ValType>::TArrayList(int length) : fElem(length){
	if (length <= 0)
		throw TMyException("Error! Size must be positive!\n");
	
	else{
		this->length = length;
		this->count = 0;
		this->first = -1;
		this->last = -1;

		mas = new ValType[this->length];
		nextIndex = new ValType[this->length];
		prevIndex = new ValType[this->length];

		for (int i = 0; i < this->length; i++){
			nextIndex[i] = -2;
			prevIndex[i] = -2;
			fElem.Push(i);
		}
	}
}

template <class ValType>
TArrayList<ValType>::TArrayList(TArrayList<ValType>& v){
	this->length = v.length;
	this->count = v.count;
	this->first = v.first;
	this->last = v.last;

	mas = new ValType[length];
	nextIndex = new ValType[length];
	prevIndex = new ValType[length];
	this->fElem = v.fElem;

	for (int i = 0; i < length; i++){
		this->mas[i] = v.mas[i];
		this->nextIndex[i] = v.nextIndex[i];
		this->prevIndex[i] = v.prevIndex[i];
	}
}

template <class ValType>
TArrayList<ValType>::~TArrayList(){
	delete[] mas;
	delete[] nextIndex;
	delete[] prevIndex;
}

template <class ValType>
void TArrayList<ValType>::Push(int index, ValType elem){
	if (IsFull())
		throw TMyException("Error! List is full!\n");
	
	else if (index<1 || index>count - 1)
		throw TMyException("Error! Index is out of range!\n");
	
	else{
		int freeIndex = fElem.Get();
		mas[freeIndex] = elem;
		int tmp1 = first;
		int tmp2 = nextIndex[first];
		
		for (int i = 0; i < index - 1; i++){
			tmp1 = tmp2;
			tmp2 = nextIndex[tmp2];
		}

		nextIndex[freeIndex] = tmp2;
		nextIndex[tmp1] = freeIndex;
		prevIndex[freeIndex] = tmp1;
		prevIndex[tmp2] = freeIndex;
		count++;
	}
}

template <class ValType>
void TArrayList<ValType>::PushFirst(ValType elem){
	if (IsFull())
		throw TMyException("Error! List is full!\n");
	else{
		int freeIndex = fElem.Get();
		mas[freeIndex] = elem;
		nextIndex[freeIndex] = first;

		if (first != -1)
			prevIndex[first] = freeIndex;
		else
			last = freeIndex;
		first = freeIndex;
		count++;
	}
}

template <class ValType>
void TArrayList<ValType>::PushLast(ValType elem){
	if (IsFull())
		throw TMyException("Error! List is full!\n");
	
	else{
		int freeIndex = fElem.Get();
		mas[freeIndex] = elem;
		
		if (last != -1)
			nextIndex[last] = freeIndex;
		else{
			first = freeIndex;
			prevIndex[freeIndex] = -1;
		}

		prevIndex[freeIndex] = last;
		last = freeIndex;
		count++;
	}
}

template <class ValType>
ValType TArrayList<ValType>::Get(int index){
	if (IsEmpty())
		throw TMyException("Error! List is empty!\n");
	
	else{
		if (index < 1 || index>count - 1)
			throw TMyException("Error! Index is out of range!\n");
		
		else{
			int ind = first;
			for (int i = 0; i < index; i++)
				ind = nextIndex[ind];

			nextIndex[prevIndex[ind]] = nextIndex[ind];
			prevIndex[nextIndex[ind]] = prevIndex[ind];

			ValType tmp = mas[ind];
			fElem.Push(ind);
			count--;
			return tmp;
		}
	}
}

template <class ValType>
ValType TArrayList<ValType>::GetFirst(){
	if (IsEmpty())
		throw TMyException("Error! List is empty!\n");
	
	else{
		ValType elem = mas[first];
		fElem.Push(first);
		int newStart = nextIndex[first];
		nextIndex[first] = prevIndex[first] = -2;

		if (newStart != -1)
			prevIndex[newStart] = -1;
		count--;
		first = newStart;
		return elem;
	}
}

template <class ValType>
ValType TArrayList<ValType>::GetLast(){
	if (IsEmpty())
		throw TMyException("Error! List is empty!\n");
	
	else{
		ValType elem = mas[last];
		int newEnd = prevIndex[last];
		prevIndex[last] = nextIndex[last] = -2;
		fElem.Push(last);
		last = newEnd;

		if (newEnd != -1)
			nextIndex[newEnd] = -1;
		else
			first = -1;
		count--;
		return elem;
	}
}

template <class ValType>
bool TArrayList<ValType>::IsFull() {
	return(count == length);
}

template <class ValType>
bool TArrayList<ValType>::IsEmpty(){
	return (count == 0);
	
	
}


