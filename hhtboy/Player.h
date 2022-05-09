#pragma once
#include <iostream>
#include <string.h>

class Player{
private:
	std::string name;
	int id;
public:
	Player(){};
	Player(std::string& str)
	{
		name = str;
		std::cout<<name<<"님이  대기열에 추가되었습니다"<<std::endl;

	}
	void Exit()
	{
		std::cout<<name<<" 님이 탈주하였습니다"<<std::endl;
	}

	friend std::ostream& operator <<(std::ostream& os,Player& P)
	{
		os << P.name << " ";
		return os;
	}

};
