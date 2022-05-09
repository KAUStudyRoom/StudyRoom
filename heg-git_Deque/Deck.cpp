#include "Deck.h"
#include "Card.h"
#include "Bag.h"
//#include <stdlib.h>
#include <iostream>

Deck::Deck(int cap) {
	A = new Deque<Card> (cap);
	for (int i = 0; i < cap; i++) {
		Insert_Card();
	}
}

void Deck::Show_Deck(){
	int i = ((A->front) + 1) % A->capacity;
	for (int j=0; j < A->data_size; j++) {
		A->array[i].Show_Card();
		i = (i + 1) % A->capacity;
	}
	std::cout << '\n';
}

void Deck::Insert_Card() {
	if (A->data_size == 0) {
		Card c(1);
		A->Push_Front(c);
		Show_Deck();
		std::cout << std::endl;
	}
	else {
		Card c(1);
		Show_Deck();
		if (c.info < A->Front().info) {
			A->Push_Front(c);
		}
		else if(c.info > A->Rear().info){
			A->Push_Rear(c);
		}
		else {
			int cnt = 0;
			if (Eval_Distance_Front(c.info) <= Eval_Distance_Rear(c.info)) {
				while (c.info > A->Front().info) {
					A->Push_Rear(A->Pop_Front());
					Show_Deck();
					cnt++;
				}
				A->Push_Front(c);
				Show_Deck();
				for(int i=0; i<cnt;i++)	A->Push_Front(A->Pop_Rear());
			}
			else {
				while (c.info < A->Rear().info) {
					A->Push_Front(A->Pop_Rear());
					Show_Deck();
					cnt++;
				}
				A->Push_Rear(c);
				Show_Deck();
				for (int i = 0; i < cnt; i++){
					A->Push_Rear(A->Pop_Front());
					Show_Deck();
				}
			}
		}
		std::cout << std::endl;
	}
}

int Deck::Eval_Distance_Front(int n) {
	int i = abs(n / 100 - (A->Front().info) / 100);
	int j = n % 100 - (A->Front().info) % 100;
	int distance = i * 13 + j;
	return abs(distance);
}

int Deck::Eval_Distance_Rear(int n) {
	int i = abs(n / 100 - (A->Rear().info) / 100);
	int j = (A->Rear().info) % 100 -  n % 100 ;
	int distance = i * 13 + j;
	return abs(distance);
}