#include "Game.h"



Game::Game(const int num): havile(num)
{
	srand(time(NULL));
	cout << havile;
	int sec=30;
	clock_t start_time = clock();//time
	clock_t end_time = sec * 1000 + start_time;
	while (clock() != end_time);
	system("cls");
}

void Game::Run() 
{
	int chose, row, col1,col2, place, card1, card2,flag;//flag for do if incorrect
		for (int i = 0; i < havile.getnum(); i++)
		{
			!havile[i];//to make all card ? cant see
		}
		cout << havile;//after make posion 0

	do
	{
		flag = 0;
		cout << "\n enter place card 1 by row\n";
		cin >> row;
		cout << "enter place card 1 by col\n";
		cin >> col1;
		place = (row-1)*5+(col1-1);
		card1 = place;
		cout << "enter place card 2 by row\n";
		cin >> row;
		cout << "enter place card 2 by col\n";
		cin >> col2;
		place = (row - 1) * 5 + (col2 - 1);
		card2 = place;
		if ((col1 > 5) || (col2>5))
		{
			cout << "eror col doest exsist\n";
			flag = 1;
		}
		if (card1 == card2) //if chose same card
		{
			cout << "eror ** you chose the same card\n";//card same
			flag = 1;
		}
		if ((havile.retun_cardposion(card1) == 1) || (havile.retun_cardposion(card2) == 1))//if the card alredy seen
		{
			cout << "thid card alredy seen\n";
			flag = 1;
		}
		if(flag!=1)
		{
				if (havile[card1] == havile[card2])
				{
					coreect_get += 2;
					cout << havile;
				}
				if (coreect_get == havile.getnum())//if the correct get the num of pile end game
				{
					cout << "\n you won have a nice day!\n";
					exit(1);
				}
		}
		cout << "\n if you want play 1 go out  0 \n";
		cin >> chose;
	} while (chose!=0);

}

Game::~Game()
{
}
