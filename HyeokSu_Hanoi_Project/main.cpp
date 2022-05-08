#include <iostream>
#include "Stack.h"
using namespace std;

#define NUMBER_OF_AXIS 3 // 축의 개수 설정

int main(void)
{
	Hanoi h(NUMBER_OF_AXIS);

	int  discs;
	std::cout << "몇 개의 원판을 사용하겠습니까?" << std::endl;
	std::cin >> discs;
	std::cout << std::endl;

	h.InputTerms(discs); // 원판의 개수 값을 Hanoi 객체 h에 전달
	h.Show_Hanoi();

	int n1, n2;
	do {
		std::cout << "움직일 원판의 축과 옮길 축 선택" << std::endl;
		std::cin >> n1;
		if (n1 == 0) break; // 0을 입력한 경우 반복문 탈출

		std::cin >> n2;
		if (!((n1 > 0 && n1 <= NUMBER_OF_AXIS) && (n2 > 0 && n2 <= NUMBER_OF_AXIS))) { // 범위를 벗어난 값을 입력한 경우
			std::cout << std::endl << "Error! 다시 입력하세요!" << std::endl;
			continue;
		}

		h.move_discs(n1, n2); // n1축 원판을 n2축에 옮기기
		h.Show_Hanoi(); // 하노이의 탑 보여주기
	}while (!h.IsFinish()); // 하노이의 탑이 완성될 때까지 반복

	if (h.IsFinish()) // 하노이의 탑이 성공한 경우
		std::cout << "하노이의 탑 성공!" << std::endl;
	
	return 0;
}
