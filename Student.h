#pragma once
#ifndef _STUDENT
#define  _STUDENT
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "MyDate.h"
#include "Worker.h"
class Worker;
class MyDate;
using namespace std;
class Student
{
private:
	char * name;
	char id[9];
	const MyDate birthday1;
	int num_of_cours;
	int *arr_grade;

public:
	Student(char *,char*,int,int,int);
	Student(const Student&);
	~Student();
	void print() const;
	int average() const;

	bool add_grade(int);//מקבלת ציון 
	bool check(Worker ** w, Student ** s, int w_size, int s_size, char *id);
	friend bool check(Worker **&, Student **&, int , int , char *);
	friend int  birthey(Worker **&, Student **&, int, int, MyDate &);
	void printhelp() const;//for app birthey
};
#endif // !1