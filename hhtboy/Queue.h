#pragma once
#include <iostream>

template <class T>
class Queue {
private:
	T* array;
	int capacity;
	int front;
	int rear;
	
public:
	Queue(){};
	Queue(int n)
	{
		capacity = n + 1;
		front = 0;
		rear = 0;
		array = new T[n];
	}
	bool isFull();

	void Push(const T& x);
	void Pop();
	void ShowQueue();
	void StartGame();
	
	
};


template <class T>
bool Queue<T>::isFull()
{
	if((rear+1)%capacity == front%capacity)
		return true;
	else
		return false;
}


template <class T>
void Queue<T>::Push(const T& x)
{
	array[(rear + 1)%capacity] = x;
	rear++;
}

template <class T>
void Queue<T>::Pop()
{
	array[(front + 1)%capacity].Exit();
	array[(front + 1)%capacity].~T();
	front++;
}

template <class T>
void Queue<T>::ShowQueue()
{
	for(int i = 0 ; i < capacity ; i ++)
	{
		std::cout<<array[(front + i + 1)%capacity]<<std::endl;
		if(front + i + 1 == rear)
			break;
	}
}

template <class T>
void Queue<T>::StartGame()
{
	std::cout<<"블루팀 : ";
	for(int i = 0; i<5; i++)
	{
		std::cout<<array[(front+i+1)%capacity];
	}
	std::cout<<std::endl;
	std::cout<<"레드팀 : ";
	for(int i = 0; i<5; i++)
	{
		std::cout<<array[(front+i+6)%capacity];
	}
}
