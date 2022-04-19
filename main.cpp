#include <iostream>
#include "Rectangle.h"

int main()
{
	//기존 r1, r2 이름을 R1, R2로 변경함
	Rectangle R1(1, 1, 3, 4);
	std::cout << R1;

	Rectangle* R2 = new Rectangle(2, 3, 5, 5);
	std::cout << *R2;

	R1 = R1 + *R2;
	
	std::cout << R1<<std::endl;
	

	//r1 생성
	Rectangle* r1 = new Rectangle();
	std::cin >> *r1;
	std::cout << std::endl;
	std::cout << *r1;
	r1->CulRectArea();

	std::cout << std::endl;

	//r2 생성
	Rectangle* r2 = new Rectangle();
	std::cin >> *r2;
	std::cout << std::endl;
	std::cout << *r2;
	r2->CulRectArea();
	std::cout << std::endl;

	//겹쳐진 영역에 대한 r3 생성
	Rectangle r3 = r1->OverlapRect(*r1, *r2);

	//동적으로 생성한 R2,r1,r2 객체 삭제
	delete R2;
	delete r1;
	delete r2;
}
