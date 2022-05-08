#include <iostream>
#include "Queue.h"
#include "Player.h"
#include <string.h>


int main()
{
	std::cout<<"소환사의 협곡에 오신 것을 환영합니다"<<std::endl;
	Queue<Player> Q(10);
	while(!Q.isFull())
	{
		int n;
		std::string temp_name;
		std::cout<<"기능을 골라주세요"<<std::endl;
		std::cout<<"1. 대기열 추가"<<std::endl<<
				   "2. 대기열 삭제"<<std::endl;
		std::cin>>n;
		if(n == 1)
		{
			std::cout<<"대기열에 추가할 이름을 입력해주세요 : ";
			std::cin>>temp_name;
			Player P(temp_name);
			Q.Push(P);

		}
		else if(n == 2)
		{
			Q.Pop();
		}
		else
		{
			std::cout<<"잘못된 값이 입력되었습니다"<<std::endl;
		}
		Q.ShowQueue();

	}

	std::cout<<"곧 게임이 시작됩니다 !"<<std::endl;
	Q.StartGame();


}

