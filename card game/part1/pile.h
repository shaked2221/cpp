#ifndef  PILE_H
#define PILE_H
#include "card.h"

using namespace std;
class pile
{
private:	
	card *cards;
	int num_cards;
public:
	pile(int);//constrctor
	char operator [](int ) const;//retun the char in the index place
	friend ostream & operator <<(ostream &,   const pile & );//print
	~pile();//dtor;
	void mix();//mix cards
	int getnum()const;////retun num cards
	int retun_cardposion(int);//return posion card
};
#endif //PILE_H
