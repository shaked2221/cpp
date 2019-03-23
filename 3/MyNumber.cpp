#include "MyNumber.h"

MyNumber::MyNumber(int num) //����
{
	int count=0;
	int num2 = num;
	int i;
	if (num == 0) //�� ����� 0
	{
		this->sign_number = 1;//�����
		this->numdigets = 1;
		this->num = new int[1];//����� ������ �����
		this->num = 0;
		return;
	}
	if (num > 0)
		this->sign_number = 1;//����� ����
	else
		this->sign_number = 0;//�����

	while (num2 != 0)//���� ������
	{
		count++;
		num2=num2/10;
	}
	this->numdigets = count;
	this->num = new int[count];//����� ������ �����
	int x = count;//����� ����� ����� ����� 
	for (i = 0; i < count; i++)
	{
		x--;
		this->num[x] = (num % 10);//����� ����� ������� ������ ������
		num /= 10;//����� �����
	}
}

MyNumber::MyNumber(const MyNumber& other)//���� �����
{
	this->sign_number = other.sign_number;
	this->numdigets = other.numdigets;
	this->num = new int[other.numdigets];
	for (int i = 0; i < other.numdigets; i++)
	{
		num[i] = other.num[i];//����� �����
	}
}

MyNumber::~MyNumber()//����
{
	delete[] num;
}

void MyNumber::print()//�����
{
	int i;
	if (!sign_number) cout << '-';
	for (i =0; i < numdigets; i++)
	{
		cout <<abs(this->num[i]);
	}
	cout << endl;
}

void MyNumber::change_num(int new_num)//����� ����
{
	cout << " start... Change by number function:\n";
	int count = 0;
	int num2 = new_num;
	int i;
	if (num == 0) //�� ����� 0
	{
		this->sign_number = 1;//�����
		this->numdigets = 1;
		this->num = new int[1];//����� ������ �����
		this->num = 0;
		return;
	}
	if (num > 0)
		this->sign_number = 1;//����� ����
	else
		this->sign_number = 0;//�����

	while (num2 != 0)//���� ������
	{//for(counter = 0 ; num2 != 0 ; count ++, num2/=10);
		count++;
		num2 = num2 / 10;
	}
	delete[] num;
	this->num = new int[count];//����� ������ �����
	this->numdigets = count;//����� ���� ������ �����
	int x = count;//����� ����� ����� ����� 
	for (i = 0; i < count; i++)
	{
		--x;
		this->num[x] = (new_num % 10);//����� ����� ������� ������ ������
		new_num /= 10;//����� �����
	}
}

void MyNumber::change_num(const MyNumber &other) //��������� �� ��� ������
{
	this->numdigets = other.numdigets;
	this->sign_number = other.sign_number;
	delete[] this->num;//����� ����� ����
	num = new int[other.numdigets];//����� ������ ����� �����
	for (int i = 0; i < other.numdigets; i++)
	{
		this->num[i] = other.num[i];//����� �����
	}
}

bool  MyNumber::comper_other_object(const MyNumber & other)//������
{
	if (this->sign_number != other.sign_number)//����� ������
		return false;
	if (this->numdigets != other.numdigets)//����� ���� ������
		return false;

	//���������� ��������� ��� ����� ���� ����� ����
	for (int i = 0; i < numdigets; i++)
	{
		if (this->num[i] != other.num[i])
			return false;
	}
	cout << "they are equell\n";
	return true;
}

MyNumber * MyNumber::add(MyNumber& other) 
{
	int i;
	int n1=0, n2=0;
	for (i = 0; i < numdigets; i++)
	{
		n1 = n1 * 10 + this->num[i];//���� 1
	}
	for (i = 0; i < numdigets; i++)
	{
		n2 = n2 * 10 + other.num[i];//���� 2
	}
	other.change_num(n1 + n2);
	return &other;
}

MyNumber * MyNumber::minus(MyNumber& other)
{
	int i;
	int n1 = 0, n2 = 0;
	for (i = 0; i < numdigets; i++)
	{
		n1 = n1 * 10 + this->num[i];//���� 1
	}
	for (i = 0; i < numdigets; i++)
	{
		n2 = n2 * 10 + other.num[i];//���� 2
	}
	other.change_num(n1 - n2);
	return &other;
}

long MyNumber::all_num()//����� ����
{
	int allnum = 0;
	for (int i = 0; i < this->numdigets; i++) 
	{
		allnum *= 10;
		allnum +=  this->num[i];
	}
	return allnum;
}


