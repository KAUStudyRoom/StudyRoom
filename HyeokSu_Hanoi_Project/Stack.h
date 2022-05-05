#ifndef STACK_H
#define STACK_H

#include <iostream>

class Hanoi; // ���漱��

template <class T>
class Stack
{
	friend Hanoi;
private:
	T* stack;
	int top; // ������ �ֻ��� ���Ҹ� ����Ŵ
	int capacity; // ����뷮

public:
	Stack(int stackCapacity = 3)
	{
		capacity = stackCapacity;
		if (capacity < 1) throw "Stack Capacity must be >= 0";
		stack = new T[capacity]; // stackCapacity ���̸�ŭ T�迭 �Ҵ�
		top = -1;
	}// ������

	~Stack()
	{
		delete[] stack;
	}

	inline bool IsEmpty() const { return top == -1; }	// ���� ���� �ִ� ������ ���� 0�� ��� TRUE(1)
														// �׷��� ���� ��� False(0) ��ȯ

	inline int ShowTop() const { return top; } // ��ü�� top�� ���� ��ȯ

	inline T& Top() const // ������ top ���� ��ȯ
	{
		{
			if (IsEmpty()) throw "Stack is emty";
			return stack[top];
		}
	}

	void push(const T& item) // ������ top�� item����
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
		stack[top--].~T(); // T�� ���� �ı���
	}// ������ top ���� ����

	void ChangeSize1D(T*& a, const int oldSize, const int newSize)
	{
		if (newSize < 0)
			throw "New length must be >= 0";

		T* temp = new T[newSize];            // ���ο� �迭
		int number = std::min(oldSize, newSize);  // ������ ���� ��
		std::copy(a, a + number, temp);
		delete[]a;                          // ���� �޸� ����
		a = temp;
	}
};

class Hanoi 
{
private:
	Stack<int>* Term; 
	int capacity; // ������� = ���� ����
	int terms; // ������ ����
public:
	Hanoi(int HanoiCapacity = 3) // default value�� 3���� �ʱ�ȭ
	{
		capacity = HanoiCapacity;
		Term = new Stack<int>[capacity];
		terms = 0;
	}

	~Hanoi() // �ı���
	{
		delete[] Term;
	}

	void InputTerms(int t)
	{ 
		terms = t;
		for (int i = t; i > 0; i--)
			Term[0].push(i);
	} // terms�� t�� ���� �� ù ��° �࿡ ��� ���� �ֱ�

	void Show_Hanoi() // �ϳ����� ž�� ����� �����ִ� �Լ�
	{
		for (int i = 0; i < capacity; i++) { // ������ �࿡ ������ �����ִ� �ݺ���
			std::cout << i+1 << " ��° �� : ";
			for (int j = -1; j < Term[i].top; j++)
				std::cout << Term[i].stack[j+1] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	bool IsFinish() // �ϳ����� ž�� �ϼ��Ǿ��� Ȯ���ϴ� �Լ�
	{
		if (Term[1].ShowTop() == (terms - 1)) // 2��° �࿡ ��� ������ �ִ� ���
			return 1;
		return 0;
	}

	void move_discs(int a1, int a2) // a1�࿡ �ִ� ������ a2�࿡ �ű�� �Լ�
	{
		int x;

		std::cout << std::endl;
		if (Term[a1 - 1].IsEmpty()) // a1�࿡ ������ ���� ���
			std::cout << "����ִ� ���� �����߽��ϴ�. �ٽ� �Է��ϼ���" << std::endl;

		else if (!(Term[a2 - 1].IsEmpty()) && (Term[a1 - 1].Top() > Term[a2 - 1].Top()))
			std::cout << "��Ģ�� ��߳����ϴ�. �ٽ� �Է��ϼ���" << std::endl;
		// a2�࿡ ������ �ֳ� ���� ���� Ȯ��
		// �׸��� �ű�� ���� ������ ũ�Ⱑ �ű�� ������ ũ�⺸�� ���� �� Ȯ��

		else { // �������� ���
			x = Term[a1 - 1].Top();
			Term[a1 - 1].pop();
			Term[a2 - 1].push(x);
		}
	}
};
#endif