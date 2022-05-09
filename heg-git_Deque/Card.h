#pragma once
class Card
{
public:
	friend class Deck;
	template< typename T > friend class Deque;
	Card() {};
	Card(int);
	void Show_Card();
	bool Same_Card(int);
	
private:
	static int cnt;
	int info;
};