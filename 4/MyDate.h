#pragma once
#ifndef _MYDATE
#define _MYDATE
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
class Student;
class Worker;

using namespace std;
class MyDate
{
private:
	int year;     
	int month;
	int day;

	static MyDate * start_min;
	static MyDate * start_max;

public:
	MyDate();
	MyDate(int,int,int);
	bool is_before(const MyDate &);//בודק מי קודם	
	~MyDate() {};
	void print() const;
	static void print_min_max();
	friend int  birthey(Worker **&, Student **&, int, int, MyDate &);
	friend bool checkerrr(const MyDate &, const MyDate &);

};

#endif 

