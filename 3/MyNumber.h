	#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class MyNumber
{
private:
	int numdigets;
	int * num;
	bool sign_number;//1- positve 0-negative

public:
	MyNumber(int = 0);//����
	MyNumber(const MyNumber &);//���� �����
	~MyNumber();
	void print();//�����
	void change_num(int);//����� ���� �� ���� ����
	void change_num(const MyNumber &);//����� ���� �� ��� ���� ������
	bool comper_other_object(const MyNumber &);//����� �� ������ �����
	MyNumber * add(MyNumber&);//�����
	MyNumber * minus(MyNumber&);//�����
	long all_num();

};

