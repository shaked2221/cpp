#ifndef CARD_H
#define CARD_H


#include <iostream>
#include <cstring>
#include <stdlib.h> 
#include <ctime>
using namespace std;

class card
{
private:
	char somecard;
	bool posion;// 1 card open you can see  0  card close 
public:
	card();//costrcotr difulet
	card(char);//costrcotr 
	void operator !();//to chabge card state
	bool operator == (const card &);//if the card the same
	friend ostream & operator <<(ostream &,const card & ) ;//print
	card(card &);////do the card same
	void setCard(card &);//do the card same by other card
	void setCard(int & a);//put the chers letters in card
	char rutun()const;////return the char card
	card operator[](int);
	int return_card_posion();//retutn posion card
};
#endif // !CARD.H


