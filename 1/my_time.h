/*shaked astemker 
campus ber shave 
id 311499917
job 1
*/

#ifndef _MY_TIME
#define _MY_TIME
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
 class my_time {
private:
	int hours;     // 0-23
	int minutes;   // 0-59
	int seconds;   //0-59
public:
	my_time();
	my_time(int, int);//����� ��� ����� �������
	my_time(my_time & );
	void change_hour(my_time &);//����� ���
	bool change_time(int, int, int);//����� ���
	void add(int, int, int);//����� ���
	my_time * chacklower(my_time &);//����� �� ����
	void print();//�����
	void print1();
};
#endif 

