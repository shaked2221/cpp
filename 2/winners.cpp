#include "Winners.h"
winners::winners(char *name1, int s1, char * name2, int s2, char *name3, int s3)
{
	first_name = new char [strlen(name1)+1];
	strcpy(first_name, name1);
	this->first_score = s1;

	second_name = new char[strlen(name2) + 1];
	strcpy(second_name, name2);
	this->second_score = s2;

	third_name = new char[strlen(name3) + 1];
	strcpy(third_name, name3);
	this->third_score = s3;

}
void winners::print() 
{
	cout << " first place " << first_name << " his score: " << first_score << endl;
	cout << " second place " << second_name << " his score: " << second_score << endl;
	cout << " third place " << third_name << " his score: " << third_score << endl;
 }
winners::winners(const winners & other)
{
	this->first_name = new char[strlen((other.first_name) + 1)];
	strcpy(this->first_name, other.first_name);
	this->first_score = other.first_score;

	this->second_name = new char[strlen((other.second_name) + 1)];
	strcpy(this->second_name, other.second_name);
	this->second_score = other.second_score;

	this->third_name = new char[strlen((other.third_name) + 1)];
	strcpy(this->third_name, other.third_name);
	this->third_score = other.third_score;

}
winners::~winners() 
{
	delete []first_name;
	delete []second_name;
	delete []third_name;
}
void winners::add(char *name, int scorenew)
{
	if (this->first_score < scorenew)
	{
		third_score = second_score;
		second_score = first_score;
		first_score = scorenew;

		second_name = new char[strlen(first_name) + 1];
		strcpy(second_name, first_name);

		third_name = new char[strlen(second_name) + 1];
		strcpy(third_name, second_name);

		first_name = new char[strlen(name) + 1];
		strcpy(first_name, name);
		
		return;
	}
	if (this->second_score < scorenew) 
	{
		third_score = second_score;
		second_score = scorenew;

		third_name = new char[strlen(second_name) + 1];
		strcpy(third_name, second_name);

		second_name = new char[strlen(name) + 1];
		strcpy(second_name, name);

		return;
	}
	if (this->third_score < scorenew) 
	{
		third_score = scorenew;

		third_name = new char[strlen(name) + 1];
		strcpy(third_name, name);

		return;
	}

	return;
}