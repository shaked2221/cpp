/*shaked astemker
campus ber shave
id 311499917
job 1
*/
#include "Winners.h"
int main()
{
	char name1[30];
	char name2[30];
	char name3[30];
	char new_name[30];
	int score1, score2, score3;
	char chocse;
	int new_score;

	cout << "enter from the higerst score to the lowest score  \n enter name 1 "<<endl;//הכנסת משתמשים
	cin >> name1;
	cout << "enter score 1 "<< endl;
	cin >> score1;

	cout << "enter name 2 "<<endl;
	cin >> name2;
	cout << "enter score 2 " << endl;
	cin >> score2;

	cout << "enter name 3 "<< endl;
	cin >> name3;
	cout << "enter score 3 " << endl;
	cin >> score3;

	winners w(name1, score1, name2, score2, name3, score3);//אתחול אוביקט
	winners x = w;//בנאי מעתיק
	do
	{
	cout << "chocse your option: " << endl  << "1 - Print " << endl << "2 - Update" << endl << "3 - Exit" << endl;
	cin >> chocse;

	switch (chocse)
	{
	case '1': w.print();
		break;
	case '2': 
		cout << "enter the new name" << endl;
		cin >> new_name;
		cout << "enter the new score" << endl;
		cin >> new_score;
		w.add(new_name, new_score);
			break;
	case '3':
		exit(0);
		break;
	}
	} while (chocse != '3');

	return 0;
}