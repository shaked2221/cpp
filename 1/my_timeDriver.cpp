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
	my_time one(h1,m1);//����� ����� 1
	cout << "enter hours sec cloclk ";
	cin >> h2;
	cout << "enter minuts sec clock ";
	cin >> m2;
	my_time two(h2, m2);//����� ����� 2
	one.print();
	two.print();
	cout << "the lower time is:\n ";
	check = one.chacklower(two);//����� �� ���� ����
	check->print();
	one.change_time(14, 1, 00);//����� ����� ��� ����� ���� ��� �������
	two.change_time(16, 1, 00);//����� ����� ��� ����� ���� ��� �������
	one.print();
	two.print();

}
