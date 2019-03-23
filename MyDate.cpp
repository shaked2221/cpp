#include "MyDate.h"
#include<string.h>
#include "Worker.h"
#include "Student.h"



MyDate::MyDate()
{
	this->year = 2000;
	this->month = 1;
	this->day = 1;

	if (MyDate::start_min != NULL)//בדיקה ראשונה
	{
		if (is_before(*MyDate::start_min) == 1)//אם התאריך יותר מוקדם
			MyDate::start_min = this;
		if (is_before(*MyDate::start_max) == 0)
			MyDate::start_max = this;
	}
	else//הצבה כפעם ראשונה
	{
		MyDate::start_min = this;
		MyDate::start_max = this;
	}
}

MyDate::MyDate(int other_year, int other_month, int other_day) 
{	
if ((other_year>=2017 || other_year<=0) || (other_month>12 ||other_month<=0)|| (other_day<=0|| other_day>=31))
{
	this->year = 2000;
	this->month = 1;
	this->day = 1;
	cout << "something you enter wrong it get depelt birthey\n";
}
else
{
	this->year = other_year;
	this->month = other_month;
	this->day = other_day;
}

	if (MyDate::start_min != NULL)//בדיקה ראשונה
	{
		if (is_before(*MyDate::start_min) == 1)//אם התאריך יותר מוקדם
			MyDate::start_min = this;
		if (is_before(*MyDate::start_max) == 0)
			MyDate::start_max = this;
	}
	else//הצבה כפעם ראשונה
	{
		MyDate::start_min = this;
		MyDate::start_max = this;
	}
}

bool MyDate:: is_before(const MyDate & other)
{
	if (this->year < other.year)//בדיקה לפי שנים
		return true;
	if ((this->year == other.year) && (this->month < other.month))//בהנחה שהשנים שוות בדיקה לפי חודשים
		return true;
	if ((this->year == other.year) && (this->month == other.month)&&(this->day<other.day))//בדיקה עד הימים
		return true;
	return false;//else retun false
}

void MyDate::print()const 
{
	if (this->day < 10)
		cout << "0" << this->day<<"/";
	else
		cout <<this->day<<"/";
	if (this->month < 10)
		cout << "0" << this->month << "/";
	else
		cout << this->month << "/";
	cout << this->year;
}

void MyDate::print_min_max()
{
	if (MyDate::start_max == NULL)//if therre no wat to print
	{
		cout << "there no objecst in system \n\n";
		return;
	}
	cout << "max date:" << endl;
	MyDate::start_max->print();
	cout << endl << "min date:" << endl;
	MyDate::start_min->print();
	cout << endl;
}
