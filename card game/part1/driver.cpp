/*shaked astemker
campus ber shave
id 311499917
job 3
*/#include "pile.h"
#include "Game.h"
#include <time.h>


int main()
{
int no;
cout << "Enter number of cards you want to play with" << endl; 
cin >> no;
Game m(no); 
m.Run(); 
return 0;
}