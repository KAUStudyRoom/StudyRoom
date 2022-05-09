#pragma once
#include <string>
#include <iostream>
#include "Card.h"
#include "Deck.h"

class Deck;

using namespace std;

template <class T>
class Bag{
public:
	Bag(int Capacity = 10);
	//virtual ~Bag();
	virtual int Size()=0;
	virtual bool IsEmpty()=0;
	//virtual T& Element() const;
	//virtual void push(const T&);
	//virtual void Pop();

protected:
	T* array;
	int capacity;
	int top;
};

template <class T>
Bag<T>::Bag(int cap){
	this->capacity = cap;
	if (this->capacity < 1) "Capacity must be > 0";
	this->array = new T[this->capacity];
}

template <class T>
class Deque : public Bag<T> {
public:
	friend class Deck;
	Deque() {};
	Deque(int);
	~Deque();
	bool IsEmpty();
	int Size();
	void Push_Front(T a);
	void Push_Rear(T a);
	T Pop_Front();
	T Pop_Rear();
	T Front();
	T Rear();

protected:
	int front;       //현재 맨앞
	int rear;		 //현재 맨뒤 
	int data_size;   //데이터 개수
};

template <class T>
Deque<T>::Deque(int cap) {
	//cout << "Deque의 생성자 호출!\n";
	this->capacity = cap;
	if (this->capacity < 1) "Capacity must be > 0";
	//cout << "크기는 " << this->capacity << endl;
	this->array = new T[this->capacity];
	rear = 0;
	front = 0;
	data_size = 0;
}

template <class T>
Deque<T>::~Deque() {
	delete[] this->array;
}


template <class T>
bool Deque<T>::IsEmpty() { return Size() == 0; }

template <class T>
int Deque<T>::Size() { return data_size; }

template <class T>
void Deque<T>::Push_Front(T a) {
	if (data_size == this->capacity) cout<< "deque is full\n";
	else {
		this->array[front] = a;
		front = (front - 1 + this->capacity) % this->capacity;
		data_size++;
	}
}

template <class T>
void Deque<T>::Push_Rear(T a) {
	if (data_size == this->capacity) cout << "deque is full\n";
	else  {
		rear = (rear + 1) % this->capacity;
		this->array[rear] = a;
		data_size++;
	}
}

template <class T>
T Deque<T>::Front() {
	if (IsEmpty()) {
		cout << "deque is empty\n";
		exit(1);
	}
	int temp_index = (front + 1) % this->capacity;
	return this->array[temp_index];
}

template <class T>
T Deque<T>::Rear() {
	if (IsEmpty()) {
		cout << "deque is empty\n";
		exit(1);
	}
	int temp_index = rear;
	return this->array[temp_index];
}

template <class T>
T Deque<T>::Pop_Front(){
	T front_data = Front();
	this->array[front].~T();
	front = (front + 1) % this->capacity;
	data_size--;
	return front_data;
}

template <class T>
T Deque<T>::Pop_Rear() {
	T rear_data = Rear();
	this->array[rear].~T();
	rear = (rear - 1 + this->capacity) % this->capacity;
	data_size--;
	return rear_data;
}
