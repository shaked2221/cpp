#pragma once
#ifndef _WORKER
#define _WORKER
#define _CRT_SECURE_NO_WARNINGS
#include "MyDate.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
class Student;
class MyDate;
using namespace std;
class Worker
{
private:
	char * name;
	char id[9];
	const MyDate birthday;
	float salery_houer;
	int num_of_hour;
	int extra_hour;
public:
	Worker(char *, char *, int,int,int,float);
	Worker( const Worker&);
	~Worker();
	void print() const;
	float salary() const;
	void set(int, int);
	friend bool check(Worker **&, Student **&, int , int , char *);
	friend int  birthey(Worker **&, Student **&, int, int, MyDate &);
	void printhelp() const;//for app birthday
	
};

#endif // !WORKER
