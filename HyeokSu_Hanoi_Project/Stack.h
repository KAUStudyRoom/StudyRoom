#ifndef STACK_H
#define STACK_H

#include <iostream>

class Hanoi; // 전방선언

template <class T>
class Stack
{
	friend Hanoi;
private:
	T* stack;
	int top; // 스택의 최상위 원소를 가르킴
	int capacity; // 저장용량

public:
	Stack(int stackCapacity = 3)
	{
		capacity = stackCapacity;
		if (capacity < 1) throw "Stack Capacity must be >= 0";
		stack = new T[capacity]; // stackCapacity 길이만큼 T배열 할당
		top = -1;
	}// 생성자

	~Stack()
	{
		delete[] stack;
	}

	inline bool IsEmpty() const { return top == -1; }	// 스택 내에 있는 원소의 수가 0인 경우 TRUE(1)
														// 그렇지 않은 경우 False(0) 반환

	inline int ShowTop() const { return top; } // 객체의 top의 값을 반환

	inline T& Top() const // 스택의 top 원소 반환
	{
		{
			if (IsEmpty()) throw "Stack is emty";
			return stack[top];
		}
	}

	void push(const T& item) // 스택의 top에 item삽입
	{
		{
			if (top == capacity - 1) {
				ChangeSize1D(stack, capacity, 2 * capacity);
				capacity *= 2;
			}
			stack[++top] = item;
		}
	}

	void pop()
	{
		if (IsEmpty()) throw "Stack is empty. Cannot delete";
		stack[top--].~T(); // T에 대한 파괴자
	}// 스택의 top 원소 삭제

	void ChangeSize1D(T*& a, const int oldSize, const int newSize)
	{
		if (newSize < 0)
			throw "New length must be >= 0";

		T* temp = new T[newSize];            // 새로운 배열
		int number = std::min(oldSize, newSize);  // 복사할 원소 수
		std::copy(a, a + number, temp);
		delete[]a;                          // 이전 메모리 제거
		a = temp;
	}
};

class Hanoi 
{
private:
	Stack<int>* Term; 
	int capacity; // 저장공간 = 축의 개수
	int terms; // 원판의 개수
public:
	Hanoi(int HanoiCapacity = 3) // default value를 3으로 초기화
	{
		capacity = HanoiCapacity;
		Term = new Stack<int>[capacity];
		terms = 0;
	}

	~Hanoi() // 파괴자
	{
		delete[] Term;
	}

	void InputTerms(int t)
	{ 
		terms = t;
		for (int i = t; i > 0; i--)
			Term[0].push(i);
	} // terms에 t값 대입 후 첫 번째 축에 모든 원판 넣기

	void Show_Hanoi() // 하노이의 탑의 모습을 보여주는 함수
	{
		for (int i = 0; i < capacity; i++) { // 각각의 축에 내용을 보여주는 반복문
			std::cout << i+1 << " 번째 축 : ";
			for (int j = -1; j < Term[i].top; j++)
				std::cout << Term[i].stack[j+1] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	bool IsFinish() // 하노이의 탑이 완성되었나 확인하는 함수
	{
		if (Term[1].ShowTop() == (terms - 1)) // 2번째 축에 모든 원판이 있는 경우
			return 1;
		return 0;
	}

	void move_discs(int a1, int a2) // a1축에 있는 원판을 a2축에 옮기는 함수
	{
		int x;

		std::cout << std::endl;
		if (Term[a1 - 1].IsEmpty()) // a1축에 원판이 없는 경우
			std::cout << "비어있는 축을 선택했습니다. 다시 입력하세요" << std::endl;

		else if (!(Term[a2 - 1].IsEmpty()) && (Term[a1 - 1].Top() > Term[a2 - 1].Top()))
			std::cout << "규칙에 어긋났습니다. 다시 입력하세요" << std::endl;
		// a2축에 원판이 있나 없나 먼저 확인
		// 그리고 옮기는 곳의 원판의 크기가 옮기는 원판의 크기보다 작은 지 확인

		else { // 정상적인 경우
			x = Term[a1 - 1].Top();
			Term[a1 - 1].pop();
			Term[a2 - 1].push(x);
		}
	}
};
#endif