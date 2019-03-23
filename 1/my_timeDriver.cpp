#include "my_time.h"
int main()
{

	my_time * check;
	int h1, m1, s1;
	int h2, m2, s2;
	cout << "enter hours fierst clock ";
	cin >> h1;
	cout << "enter minuts fierst clock ";
	cin >> m1;
	my_time one(h1,m1);//הכנסה לשעון 1
	cout << "enter hours sec cloclk ";
	cin >> h2;
	cout << "enter minuts sec clock ";
	cin >> m2;
	my_time two(h2, m2);//הכנסה לשעון 2
	one.print();
	two.print();
	cout << "the lower time is:\n ";
	check = one.chacklower(two);//בדיקה מי נמוך יותר
	check->print();
	one.change_time(14, 1, 00);//שינוי השעון אין דרישה לקבל קלט מהמשתמש
	two.change_time(16, 1, 00);//שינוי השעון אין דרישה לקבל קלט מהמשתמש
	one.print();
	two.print();

}
