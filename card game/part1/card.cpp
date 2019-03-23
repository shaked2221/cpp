#include "card.h"


card::card()
{
	//somecard = (rand() % 26)+'A';
	posion = 1;
}

card:: card(char c)
{
	somecard = c;
	posion = 1;
}

void card:: operator!()
{
	if (posion == 1)
		posion = 0;
	else if (posion == 0)
			posion = 1;
}


bool card::operator==(const card & c)
{
	if (c.somecard == this->somecard)
		return true;
	else
		return false;
}

ostream &  operator <<(ostream & out, const card& x ) 
{
	if (x.posion == 1)//if card open print the card else print ?
		return out << "[" << x.somecard << "]";
	if (x.posion == 0)
		return out << "[" << "?" << "]";
}

card::card(card & other)//get card to do the card 2 times in pille
{
	other.somecard = this->somecard;
}
void card::setCard(int & a)
{
     this->somecard =char( a+'A');//give big latter in card 
}
void card::setCard(card & c)//do the card same by other card
{
	c.somecard=this->somecard ;
}
char card::rutun()const //return the char card
{
	return this->somecard;

}

card card::operator[](int)
{

	return card();
}

int card::return_card_posion()
{
	return (this->posion);
}
