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
	my_time(int, int);//אתחול שני קלטים מהמשתמש
	my_time(my_time & );
	void change_hour(my_time &);//שינוי שעה
	bool change_time(int, int, int);//שינוי שעה
	void add(int, int, int);//הוספת זמן
	my_time * chacklower(my_time &);//בדירה מי קודם
	void print();//הדפסה
	void print1();
};
#endif 

