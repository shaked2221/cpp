#include "pile.h"
#define DEFAULTSIZE 20

pile::pile(int num)
{
	if (num % 2 == 0)//if num card zogi
		num_cards = num;
	else
		num_cards = (num - 1);
	if (num_cards > 52 || num_cards <= 0)//if the law of amount card dont exsist
	{
		cards = new card[DEFAULTSIZE];
		num_cards = DEFAULTSIZE;
	}
	else
		cards = new card[num_cards];
	for (int i = 1 ; i <= num_cards/2; i++)//fuul the piile
	{
		cards[i - 1].setCard(i);
		cards[i-1].setCard(cards[num_cards - i]);
	}
		mix();
}

void pile::mix()
{
	int randindex;
	card temp;
	for (int i = 0; i < this->num_cards; i++)
	{
		randindex = (rand() % this->num_cards);
		if (randindex !=i)
		{
			temp = cards[randindex];
			cards[randindex] = cards[i];
			cards[i] = temp;
		}
	}
}

char pile:: operator [](int index) const
{
	if (index >= this->num_cards ||index <0)//if index not in arr
	{
		cout << "wrong this  index not exsist end game\n *******************************\n";
		exit(1);
	}
char x = cards[index].rutun();
	!cards[index];
	return x;
}

ostream & operator <<(ostream & out, const pile  & Pile)//print
{
	int i=0, counter=1,row=1,col=4;
//to print matrix size
	while (col >= 0)
	{
		out << "  " << i + 1;
		col--;
		i++;
	}
	cout << endl;
	for (i = 0; i <Pile.num_cards ; i++)//print pile
	{
	if (counter==1)
		out << row++<<" ";
		if (counter == 5)
		{
			out << Pile.cards[i]<<endl;
			counter = 1;
		}
		else
		{
			out << Pile.cards[i];
			counter++;
		}
	}
	return out;
}

int pile::getnum()const //retun num cards
{
	return num_cards;
}
int pile::retun_cardposion(int index)
{
	return (this->cards[index].return_card_posion());
}

pile::~pile()//dtor
{
	if(cards!= NULL)
		delete[] cards;
}
