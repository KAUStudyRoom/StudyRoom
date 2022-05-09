#pragma once
#include "Card.h"
#include "Bag.h"

class Deck
{
public:
	Deck() {};
	Deck(int);
	void Show_Deck();
	void Insert_Card();
	int Eval_Distance_Front(int);
	int Eval_Distance_Rear(int);
	Deque<Card>* A;
};


