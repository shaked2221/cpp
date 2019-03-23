#ifndef WINNERS
#define _CRT_SECURE_NO_WARNINGS
#define WINNERS
#pragma once
#include <iostream>
#include <iomanip>
#include<string.h>
using namespace std;
class winners {
private:
	char *first_name;
	char *second_name;
	char *third_name;

	int  first_score;
	int second_score;
	int third_score;

public:
	winners(char *, int, char *, int, char *, int);
	winners(const winners &);
	~winners();
	void print();
	void add(char *, int);
};
#endif 