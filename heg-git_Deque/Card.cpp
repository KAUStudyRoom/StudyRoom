#include "Card.h"
#include <iostream>
#include <vector>
#include <random>

int Card::cnt = 0;

Card::Card(int a) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> num(1, 13);
	std::uniform_int_distribution<int> shape(1, 4);

	info = (shape(gen) * 100) + num(gen);
	while (Same_Card(info)) {
		info = (shape(gen) * 100) + num(gen);
	}
	std::cout << "선택된 카드" << ++cnt << " ";
	Show_Card();
	std::cout << std::endl;
}

bool Card::Same_Card(int num) {
	static std::vector<int> v;
		for (int i = 0; i < v.size(); i++) {
			if (num == v[i]) {
				return true;
			}
		}
		v.push_back(num);
		return false;
}

void Card::Show_Card() {

	switch (info / 100) {
	case 1:
		std::cout << "♠" << info % 100 << " ";
		break;
	case 2:
		std::cout << "◆" << info % 100 << " ";
		break;
	case 3:
		std::cout << "♥" << info % 100 << " ";
		break;
	case 4:
		std::cout << "♣" << info % 100 << " ";
		break;
	}
}