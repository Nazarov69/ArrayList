#pragma once
#include <iostream>
using namespace std;

template <class ValType>
class ArrayIterator;

template <class ValType>
class ArrayList{
	ValType* array;
	ValType* pointers;
	int length;
	int count;
	int first;
public:
	ArrayList(int length = 1);
	ArrayList(ArrayList<ValType>& v);
	~ArrayList();

	ArrayList<ValType>& operator = (ArrayList<ValType>& v);

	void InsFirst(ValType num);
	void DelFirst();
	ValType GetFirst();

	void InsLast(ValType num);
	void DelLast();
	ValType GetLast();

	void Ins(ArrayIterator<ValType>& element, ValType num);
	void Del(ArrayIterator<ValType>& element);

	bool IsFull();
	bool IsEmpty();
	
	ArrayIterator<ValType> ListBegin();
	ArrayIterator<ValType> ListEnd();

	template <class ValType1>
	friend ostream& operator << (ostream& ostr, const ArrayList<ValType1>& v);
	template <class ValType1>
	friend istream& operator >> (istream& istr, ArrayList<ValType1>& v);

	template <class ValType>
	friend class ArrayIterator;

	int GetCount();
};

template<class ValType1>
ostream& operator<<(ostream& ostr, const ArrayList<ValType1>& v) {
	int temp = v.first;

	while (v.pointers[temp] != -1) {
		ostr << v.array[temp];
		i = v.pointers[temp];
	}

	return ostr;
}

template<class ValType1>
istream& operator>>(istream& istr, ArrayList<ValType1>& v) {
	int count;
	istr >> count;

	for (int i = 0; i < count; i++) {
		ValType1 temp;
		istr >> temp;
		v.InsLast(temp);
	}

	return istr;
}

template<class ValType>
ArrayList<ValType>::ArrayList(int length){
	if (length <= 0)
		throw logic_error("Input error: invalide value of ArrayList length in ArrayList");

	this->length = length;

	array = new ValType[length];
	pointers = new ValType[length];
	count = 0;
	first = -1;

	for (int i = 0; i < length; i++)
		pointers[i] = -2;
}

template<class ValType>
ArrayList<ValType>::ArrayList(ArrayList<ValType>& v){
	this->count = v.count;
	this->length = v.length;
	this->first = v.first;

	array = new ValType[length];
	pointers = new ValType[length];

	for (int i = 0; i < length; i++){
		this->pointers[i] = v.pointers[i];
		this->array[i] = v.array[i];
	}
}

template<class ValType>
ArrayList<ValType>::~ArrayList(){
	if (array != 0){
		delete[] array;
		delete[] pointers;

		first = -1;
		length = 0;
		count = 0;
	}
}

template<class ValType>
ArrayList<ValType>& ArrayList<ValType>::operator=(ArrayList<ValType>& v){
	if (this == &v)
		return *this;

	if (this->length != v.length) {
		delete[] array;
		delete[] pointers;

		array = new ValType[length];
		pointers = new ValType[length];
	}

	this->count = v.count;
	this->length = v.length;
	this->first = v.first;

	for (int i = 0; i < length; i++) {
		this->pointers[i] = v.pointers[i];
		this->array[i] = v.array[i];
	}

	return (*this);
}

template<class ValType>
void ArrayList<ValType>::InsFirst(ValType num){
	if (this->IsFull())
		throw logic_error("Input error: invalide value of ArrayList length in InsFirst");

	int i = 0;
	for (; i < length; i++){
		if (pointers[i] == -2)
			break;
	}

	array[i] = num;
	pointers[i] = first;
	first = i;
	count++;
}

template<class ValType>
void ArrayList<ValType>::DelFirst() {
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of ArrayList length in DelFirst");

	int temp = first;
	first = pointers[first];
	pointers[temp] = -2;
	count--;
}

template<class ValType>
ValType ArrayList<ValType>::GetFirst() {
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of ArrayList length in GetFirst");

	return array[first];
}

template<class ValType>
void ArrayList<ValType>::InsLast(ValType num){
	if (this->IsFull())
		throw logic_error("Input error: invalide value of ArrayList length in InsLast");

	if (this->IsEmpty()){
		first = 0;
		array[0] = num;
		pointers[0] = -1;
	}

	else{
		int i = 0;
		for (; i < length; i++){
			if (pointers[i] == -2)
				break;
		}

		int temp = first;
		while (pointers[temp] != -1)
			temp = pointers[temp];

		array[i] = num;
		pointers[i] = -1;
		pointers[temp] = i;
	}
	count++;
}

template<class ValType>
void ArrayList<ValType>::DelLast() {
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of ArrayList length in DelFirst");

	if (pointers[first] == -1) {
		pointers[first] = -2;
		first = -1;
	}

	else {
		int temp = first;
		int tmp = pointers[first];

		while (pointers[tmp] != -1) {
			temp = tmp;
			tmp = pointers[tmp];
		}

		pointers[temp] = -1;
		pointers[tmp] = -2;
	}
	count--;
}

template<class ValType>
ValType ArrayList<ValType>::GetLast() {
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of ArrayList length in GetLast");

	int i = first;
	while (pointers[i] != -1)
		i = pointers[i];

	return array[i];
}

template<class ValType>
void ArrayList<ValType>::Ins(ArrayIterator<ValType>& element, ValType num){
	if (this->IsFull())
		throw logic_error("Input error: invalide value of ArrayList length in Ins");

	if (this->IsEmpty()){
		first = 0;
		array[0] = num
		pointers[0] = -1;
	}

	else {
		int i = 0;
		for (; i < length; i++) {
			if (pointers[i] == -2)
				break;
		}

		array[i] = num;
		int temp = element.GetIndex();

		if (element.IsGoNext()) {
			element.GoNext();
			pointers[i] = element.GetIndex();
		}
		else
			pointers[i] = -1;
		pointers[temp] = i;
	}
	count++;
}

template<class ValType>
void ArrayList<ValType>::Del(ArrayIterator<ValType>& v)
{
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of ArrayList length in Del");

	if (pointers[first] == -1) {
		pointers[first] = -2;
		first = -1;
	}
	else {
		int temp = v.GetIndex();
		if (v.IsGoNext()) {
			v.GoNext();
			pointers[temp] = v.GetIndex();
		}
		else
			pointers[temp] = -1;
	}
	count--;
}

template<class ValType>
bool ArrayList<ValType>::IsFull(){
	return (count >= length);
}

template<class ValType>
bool ArrayList<ValType>::IsEmpty(){
	return (count == 0);
}

template<class ValType>
int ArrayList<ValType>::GetCount(){
	return count;
}

template<class ValType>
ArrayIterator<ValType> ArrayList<ValType>::ListBegin(){
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of ArrayList length in ListBegin");

	return ArrayIterator<ValType>(*this, first);
}

template<class ValType>
ArrayIterator<ValType> ArrayList<ValType>::ListEnd()
{
	if (this->IsEmpty())
		throw logic_error("Input error: invalide value of ArrayList length in ListEnd");

	int i = first;
	while (pointers[i] != -1)
		i = pointers[i];

	return ArrayIterator<ValType>(*this, i);
}



