#include "Student.h"
#include<string.h>
#include "MyDate.h"

#define _CRT_SECURE_NO_WARNINGS


Student::Student(char * other_name, char * other_id, int d, int m, int y) :birthday1(d, m, y)
{
	this->name = new char[strlen(other_name)+1];//give space
	strcpy(this->name, other_name);//copy the name 2place
	for (int i = 8; i >= 0; i--)
	{
		this->id[i] = other_id[i];
	}
	this->num_of_cours = 0;
}

Student::Student(const Student& other): birthday1(other.birthday1)//copoycotor
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	for (int i = 9; i != 0; i--)
	{
		this->id[i] = other.id[i];
	}
	this->num_of_cours = other.num_of_cours;
}


Student::~Student()
{
		delete[] name;
		delete[] arr_grade;

}

void Student::print() const 
{
	cout << "the name of the student " << this->name;
	cout << endl;
	cout << "is id:  " << this->id;
	cout << endl;
	cout << "the num of course that he take: " << this->num_of_cours;
	cout << endl;
	if (this->num_of_cours != NULL)
	{
		int i = this->num_of_cours;
		while (i >= 1)
		{
			cout << "grade in place : " << i+1 << " is " << arr_grade[--i] << endl;
		}
	}
	cout << "is avverage is  " << average() << endl;
}

int Student::average() const 
{
	int sum = 0;
	if (this->num_of_cours == 0)
		return 0;
	for (int i = 0; i < this->num_of_cours; i++)
	{
		sum += arr_grade[i];
	}
	return(sum / num_of_cours);
}

bool Student::add_grade(int new_grade)
{
	int i;
	if ((new_grade > 100) && (new_grade < 0))
		return false;
	this->num_of_cours++;
	int *temp = new int[num_of_cours];//הקצאת זיכרון מחדש לציון
	if (num_of_cours!=1)
	{
		for (i = 0; i < this->num_of_cours; i++)
		{
			temp[i] = arr_grade[i];
		}
	}
	temp[num_of_cours - 1] = new_grade;//הכנסתציון חדש למערך הזמני
	delete[] arr_grade;
	arr_grade = new int[num_of_cours];
	for (i = 0; i < num_of_cours; i++)
	{
		arr_grade[i] = temp[i];//העתקה למערך החדש
	}
	delete[] temp;
	return true;
}

void Student::printhelp() const
{
	cout << "the name of the student is :" <<this->name;
	cout << endl;
}
