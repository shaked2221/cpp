#include "Worker.h"
#include "MyDate.h"
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS



Worker::Worker(char *other_name, char * other_id,int d,int m,int y, float hour_pay) :birthday(d,m,y)
{
	this->name = new char[strlen(other_name) + 1];
	strcpy(this->name, other_name);

	for (int i = 8; i >= 0; i--)
	{
		this->id[i] = other_id[i];
	}
	this->salery_houer = hour_pay;
	this->num_of_hour = 0;
	this->extra_hour = 0;
}

Worker:: Worker(const Worker&other)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);

	for (int i = 8; i >= 0; i--)
	{
		this->id[i] = other.id[i];
	}
	this->salery_houer = other.salery_houer;
	this->num_of_hour= other.num_of_hour;
	this->extra_hour = other.extra_hour;

}

Worker::~Worker()
{
	delete[]this->name;
}

void Worker::print() const
{
	cout << "the name of the worker is :" << this->name;
	cout << endl;
	cout << "is id :" << this->id;
	cout << endl;
	cout << "he get for a hour  " << this->salery_houer;
	cout << endl;
	cout << "he work in this month " << this->num_of_hour;
	cout << endl;
	cout << "the extra hous is  " << this->extra_hour;
	cout << endl;
	cout << "is salary :  " << salary();
	cout << endl;
}

float Worker::salary() const
{
	float sum = 0;
	sum = (this->num_of_hour*this->salery_houer);
	sum = sum + (this->salery_houer*1.5)*(this->extra_hour);
	return sum;
}
void Worker::set(int new_houer,int mew_extra_hour) 
{
	this->extra_hour = mew_extra_hour;
	this->num_of_hour= new_houer;
}
void Worker::printhelp() const
{
	cout << "the name of the worker is :" << this->name;
	cout << endl;

}
