#pragma once
#include <iostream>
#include "Stack.h"
#include "MyException.h"


template <class ValType>
class TQueue : public TStack<ValType>{
protected:
    int first;
    int count;
public:
    TQueue(int length = 0);
    TQueue(TQueue<ValType>& v);

    void Push(ValType elem);
    ValType Get();
    ValType ShowTop();

    bool IsEmpty();
    bool IsFull();
};

template <class ValType>
TQueue<ValType>::TQueue(int length) :TStack<ValType>(length){
    first = 0;
    count = 0;
}

template <class ValType>
TQueue<ValType>::TQueue(TQueue<ValType>& v) :TStack<ValType>(v){
    this->first = v.first;
    this->count = v.count;
}


template <class ValType>
inline ValType TQueue<ValType>::ShowTop(){
    return TStack<ValType>::mas[first];
}

template <class ValType>
void TQueue<ValType>::Push(ValType elem){
    if (IsFull())
        throw TMyException("Error! Queue is full!\n");
   
    else{
        TStack<ValType>::Push(elem);
        TStack<ValType>::top = TStack<ValType>::top % TStack<ValType>::length;
        count++;
    }
}

template <class ValType>
ValType TQueue<ValType>::Get(){
    if (IsEmpty())
        throw TMyException("Error! Queue is empty!\n");
    
    else{
        ValType tmp = TStack<ValType>::mas[first];
        first = (first + 1) % TStack<ValType>::length;
        count--;
        return tmp;
    }
}

template <class ValType>
bool TQueue<ValType>::IsEmpty(){
    return (count == 0);  
}

template <class ValType>
bool TQueue<ValType>::IsFull(){
    return (count == TStack<ValType>::length);  
}