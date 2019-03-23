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
	MyNumber(int = 0);//בנאי
	MyNumber(const MyNumber &);//בנאי מעתיק
	~MyNumber();
	void print();//הדפסה
	void change_num(int);//שינוי מספר עי קבלת מספר
	void change_num(const MyNumber &);//שינוי מספר על ידי קבלת אוביקט
	bool comper_other_object(const MyNumber &);//בדיקה אם מספרים שווים
	MyNumber * add(MyNumber&);//חיבור
	MyNumber * minus(MyNumber&);//חיסור
	long all_num();

};

