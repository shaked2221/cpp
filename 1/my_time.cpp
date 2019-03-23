#include "my_time.h"

my_time::my_time()//�����
{
	hours = 0;
	minutes = 0;
	seconds = 0;
}
my_time::my_time(int hours, int minets)//����� ��� ��� �������
{
	this->hours = hours;
	this->minutes = minets;
	this->seconds = 0;
}
my_time::my_time(my_time & other) //���� ����������
{
	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
}
void my_time::change_hour(my_time & other)//����� ��� 
{
	this->hours = other.hours;
	this->minutes = other.minutes;
	this->seconds = other.seconds;
}
bool my_time::change_time(int h, int m, int s)//����� ��� ������ ������
{
		if ((h > 23) || (h < 0))//���� �� ������ �����
			return false;
		if ((m > 59) || (m < 0))//���� �� ������ �����
			return false;
		if ((s > 59) || (s < 0))//����� �� ������ ������
			return false;
		this->hours = h;
		this->minutes = m;
		this->seconds = s;
		return true;
}
void my_time::add(int addhour, int addmin, int addsec)//����� ��� �����
{
		this->seconds = (seconds + addsec) % 60;
		this->minutes = (minutes + addmin) % 60 + (seconds / 60);
		this->hours = (hours + addhour) % 24 + (minutes / 60);
		if (this->hours >= 24)
			hours = hours % 24;
}
my_time * my_time::chacklower(my_time & other)//����� �� ���� ����
{
	if (this->hours == other.hours&& this->minutes==other.minutes && this->seconds==other.seconds)
		return this;
	if ((this->hours) < (other.hours))
		return this;
	if (other.hours < this->hours)
		return &other;

	if ((this->minutes) < (other.minutes))
		return this;
	if (other.minutes < this->minutes)
		return &other;

	if ((this->seconds) < (other.seconds))
		return this;
	if (other.seconds < this->seconds)
		return &other;

}
void my_time::print()//�����
{
	if (this->hours < 10)
		cout << "0" << hours<<":";
	else
		cout << hours << ":";
	if(this->minutes < 10)
		cout << "0" << minutes << ":";
	else
		cout << minutes << ":";
	if(this->seconds < 10)
		cout << "0" << seconds;
	else
		cout << seconds;
	cout << endl;
}
void my_time::print1()//����� ����� 2
{
	if (this->hours%12 < 10)
		cout << "0" << hours%12 << ":";
	else
		cout << hours%12 << ":";
	if (this->minutes < 10)
		cout << "0" << minutes << ":";
	else
		cout << minutes << ":";
	if (this->seconds < 10)
		cout << "0" << seconds;
	else
		cout << seconds;
	if (this->hours < 12)
		cout << " AM";
	else
		cout << " PM";
	cout << endl;
}
