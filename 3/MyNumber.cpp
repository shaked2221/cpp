#include "MyNumber.h"

MyNumber::MyNumber(int num) //בנאי
{
	int count=0;
	int num2 = num;
	int i;
	if (num == 0) //אם המספר 0
	{
		this->sign_number = 1;//חיובי
		this->numdigets = 1;
		this->num = new int[1];//הקצאת זיכרון למספר
		this->num = 0;
		return;
	}
	if (num > 0)
		this->sign_number = 1;//חיובי מספר
	else
		this->sign_number = 0;//שלילי

	while (num2 != 0)//כמות הספרות
	{
		count++;
		num2=num2/10;
	}
	this->numdigets = count;
	this->num = new int[count];//הקצאת זיכרון למספר
	int x = count;//תיקון בשביל מיקום המספר 
	for (i = 0; i < count; i++)
	{
		x--;
		this->num[x] = (num % 10);//שמירת הספרה האחרונה במיקום האחרון
		num /= 10;//הורדת סיפרה
	}
}

MyNumber::MyNumber(const MyNumber& other)//בנאי מעתיק
{
	this->sign_number = other.sign_number;
	this->numdigets = other.numdigets;
	this->num = new int[other.numdigets];
	for (int i = 0; i < other.numdigets; i++)
	{
		num[i] = other.num[i];//העתקת המספר
	}
}

MyNumber::~MyNumber()//הורס
{
	delete[] num;
}

void MyNumber::print()//מדפיס
{
	int i;
	if (!sign_number) cout << '-';
	for (i =0; i < numdigets; i++)
	{
		cout <<abs(this->num[i]);
	}
	cout << endl;
}

void MyNumber::change_num(int new_num)//שינוי מספר
{
	cout << " start... Change by number function:\n";
	int count = 0;
	int num2 = new_num;
	int i;
	if (num == 0) //אם המספר 0
	{
		this->sign_number = 1;//חיובי
		this->numdigets = 1;
		this->num = new int[1];//הקצאת זיכרון למספר
		this->num = 0;
		return;
	}
	if (num > 0)
		this->sign_number = 1;//חיובי מספר
	else
		this->sign_number = 0;//שלילי

	while (num2 != 0)//כמות הספרות
	{//for(counter = 0 ; num2 != 0 ; count ++, num2/=10);
		count++;
		num2 = num2 / 10;
	}
	delete[] num;
	this->num = new int[count];//הקצאת זיכרון למספר
	this->numdigets = count;//שינוי גודל ההקצאה בכיתה
	int x = count;//תיקון בשביל מיקום המספר 
	for (i = 0; i < count; i++)
	{
		--x;
		this->num[x] = (new_num % 10);//שמירת הספרה האחרונה במיקום האחרון
		new_num /= 10;//הורדת סיפרה
	}
}

void MyNumber::change_num(const MyNumber &other) //שינוימספר על ידי אוביקט
{
	this->numdigets = other.numdigets;
	this->sign_number = other.sign_number;
	delete[] this->num;//מחיקת המספר הישן
	num = new int[other.numdigets];//הקצאת זיכרון לגודל המספר
	for (int i = 0; i < other.numdigets; i++)
	{
		this->num[i] = other.num[i];//העתקת המספר
	}
}

bool  MyNumber::comper_other_object(const MyNumber & other)//השוואה
{
	if (this->sign_number != other.sign_number)//בדיקת סימנים
		return false;
	if (this->numdigets != other.numdigets)//בדיקת כמות מספרים
		return false;

	//בדיקתהמספר עמנובהנחה שהם באותו גודל ואותו סימן
	for (int i = 0; i < numdigets; i++)
	{
		if (this->num[i] != other.num[i])
			return false;
	}
	cout << "they are equell\n";
	return true;
}

MyNumber * MyNumber::add(MyNumber& other) 
{
	int i;
	int n1=0, n2=0;
	for (i = 0; i < numdigets; i++)
	{
		n1 = n1 * 10 + this->num[i];//מספר 1
	}
	for (i = 0; i < numdigets; i++)
	{
		n2 = n2 * 10 + other.num[i];//מספר 2
	}
	other.change_num(n1 + n2);
	return &other;
}

MyNumber * MyNumber::minus(MyNumber& other)
{
	int i;
	int n1 = 0, n2 = 0;
	for (i = 0; i < numdigets; i++)
	{
		n1 = n1 * 10 + this->num[i];//מספר 1
	}
	for (i = 0; i < numdigets; i++)
	{
		n2 = n2 * 10 + other.num[i];//מספר 2
	}
	other.change_num(n1 - n2);
	return &other;
}

long MyNumber::all_num()//המספר השלם
{
	int allnum = 0;
	for (int i = 0; i < this->numdigets; i++) 
	{
		allnum *= 10;
		allnum +=  this->num[i];
	}
	return allnum;
}


