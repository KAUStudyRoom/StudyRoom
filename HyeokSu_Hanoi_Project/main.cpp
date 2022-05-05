#include <iostream>
#include "Stack.h"
using namespace std;

#define NUMBER_OF_AXIS 3 // ���� ���� ����

int main(void)
{
	Hanoi h(NUMBER_OF_AXIS);

	int  discs;
	std::cout << "�� ���� ������ ����ϰڽ��ϱ�?" << std::endl;
	std::cin >> discs;
	std::cout << std::endl;

	h.InputTerms(discs); // ������ ���� ���� Hanoi ��ü h�� ����
	h.Show_Hanoi();

	int n1, n2;
	do {
		std::cout << "������ ������ ��� �ű� �� ����" << std::endl;
		std::cin >> n1;
		if (n1 == 0) break; // 0�� �Է��� ��� �ݺ��� Ż��

		std::cin >> n2;
		if (!((n1 > 0 && n1 <= NUMBER_OF_AXIS) && (n2 > 0 && n2 <= NUMBER_OF_AXIS))) { // ������ ��� ���� �Է��� ���
			std::cout << std::endl << "Error! �ٽ� �Է��ϼ���!" << std::endl;
			continue;
		}

		h.move_discs(n1, n2); // n1�� ������ n2�࿡ �ű��
		h.Show_Hanoi(); // �ϳ����� ž �����ֱ�
	}while (!h.IsFinish()); // �ϳ����� ž�� �ϼ��� ������ �ݺ�

	if (h.IsFinish()) // �ϳ����� ž�� ������ ���
		std::cout << "�ϳ����� ž ����!" << std::endl;
	
	return 0;
}
