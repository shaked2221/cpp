/*shaked astemker
campus ber shave
id 311499917
job 2
*/


#include "MyDate.h" 
#include "Student.h"
#include "Worker.h"

MyDate * MyDate::start_max = NULL;
MyDate * MyDate::start_min = NULL;
bool check(Worker **&, Student **&, int , int , char *);
int  birthey(Worker **&, Student **&, int , int ,MyDate &);
void addsto(Student** &, int &, Worker** &, int &);//1
void addworker(Student** &, int &, Worker** &, int &);//2
void update_sto(int &num_stp, Student**& s);//1-3
void update_worker(int &numworker, Worker**&);//2-4
void print( Worker **&, int, Student **&, int) ;//5
void free(Worker **&, int, Student **&, int);//8
bool checkerrr(const MyDate &, const MyDate &);
MyDate make();//refrene to birthey

int main() 
{
	int choice;
	int numsto = 0;
	int numworker = 0;
	MyDate ff(1,1,2000);
	Student** students = NULL;
	Worker** workers = NULL;

	cout << "Choose the opption: " << endl;
	do {
		cout << endl << endl << "***********************************"<<endl;
		cout << "1 -add a student " << endl;
		cout << "2 -add a worker " << endl;
		cout << "3- update a student " << endl;
		cout << "4 -update a worker " << endl;
		cout << "5 -For print all the data about the workers and the students" << endl;
		cout << "6 -For print the earliest and the latest birthday   " << endl;
		cout << "7 -Birthday  " << endl;
		cout << "8 -For exit  " << endl;
		cin >> choice;
		switch (choice) {
		case 1: addsto(students, numsto,workers,numworker);
			break;
		case 2:addworker(students, numsto, workers, numworker);
			break; 
		case 3:update_sto(numsto, students);
			break;
		case 4:update_worker(numworker, workers);
			break;
		case 5:print( workers, numworker, students, numsto) ;
			break;
		case 6: MyDate::print_min_max();
			break;
		case 7:ff = make();
				birthey(workers,students, numworker,numsto,ff);
			break;
		case 8:	free(workers, numworker, students, numsto);
				cout << "****end****\n\n";
			break;
		default: cout << endl << "wrong choice chose agein" << endl;
		}
	} while (choice != 8);
	return 0;
}

bool check(Worker **& w, Student **& s, int sizes, int sizew, char *idd)
{
	int i = 0,k=0;
	int flag;
	for (i = 0; i < sizes; i++)//scan the arr student
	{
		flag = 0;
		for (k = 0; k < 9; k++)
		{
			if (idd[k] == s[i]->id[k])
				flag++;
		}
		if (flag == 9)
			return false;
	}

	for (i = 0; i < sizew; i++)//scan the arr worker
	{
		flag = 0;
		for (k = 0; k < 9; k++)
		{
			if (idd[k] == w[i]->id[k])
				flag++;
		}
		if (flag == 9)
			return false;
	}
		return true;
}
int  birthey(Worker **& w, Student **& s, int sizew, int sizes, MyDate & chabir)
{
	int count = 0;
	int i = 0, k = 0,c;
	int flag;
	for (i = 0; i < sizew; i++)//מערך עובדים
	{
		if (checkerrr(chabir, (w[i]->birthday))== true)
		{
			count++;
			w[i]->printhelp();
			c = 2017 - w[i]->birthday.year;
			cout << "he is " << c << " old";
			cout << endl;

		}
	}
	cout << endl<<"&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";

	for (k = 0; k < sizes; k++)//מערך 
	{
		if (checkerrr(chabir,(s[k]->birthday1))== true)
		{
			count++;
			s[k]->printhelp();
			c = 2017 - s[k]->birthday1.year;
			cout << "he is " << c << " old";
			cout << endl;

		}
	}
	cout << endl;
	cout << "** there are: " << count << " born in the same day\n";
	return 1;
}

void addsto(Student** & sto, int & num_sto, Worker** & w, int & n)
{
	int d, m, y;
	int i, count = 0;
	char id[9];
	char name[20];
	Student **tempsto = NULL;
	cout << "enter name student" << endl;
	cin >> name;
	cout << "enter id:" << endl;
	do
	{
		if (count > 0)
			cout << "wrong this id exsist in system try agein\n";
		count++;
		for (i = 0; i < 9; i++)
		{
			cin >> id[i];
		}
	} while (check(w, sto, num_sto, n, id) == 0);
	cout << "enter birday day enetr month enter year enter" << endl;
	cin >> d>>m>>y;

	num_sto++;
	tempsto = new Student*[num_sto];//מגידלים בשביל הסטודנט החדש
	if (sto != NULL)
	{
		for (i = 0; i < num_sto; i++)
		{
			tempsto[i] = sto[i];//מעתיק תמצביעים למשתנה זמני
		}
	}
	Student * new_sto = new Student(name, id, y, m, d);//יצרת אוביקט חדש
	tempsto[num_sto - 1] = new_sto;//סטודנט חדש
	
	delete[] sto;//מחיקת המערךהישן
	sto = new Student*[num_sto];//הקצאה מחדש
	for (i = 0; i < num_sto; i++)
	{
		sto[i] = tempsto[i];//מעתיק לחדש 
	}
	delete[] tempsto;
}
void addworker(Student** &s , int & nums,Worker** & w, int &numworker)
{
	int d, m, y;
	int i, hour_pay,count=0;
	char id[9];
	char name[20];
	Worker **tempwork = NULL;
	cout << "enter name worker" << endl;
	cin >> name;
	cout << "who much he get payed hour" << endl;
	cin >> hour_pay;
	cout << "enter id:" << endl;
	do
	{
		if (count > 0)
			cout << "wrong this id exsist in system try agein\n";
		count++;
		for (i = 0; i < 9; i++)
		{
			cin >> id[i];
		}
	} while (check(w, s, nums, numworker, id) == 0);
	cout << "enter birday day enetr month enter year enter" << endl;
	cin >> d >> m >> y;
	numworker++;
	tempwork = new Worker*[numworker];//
	if (w != NULL)
	{
		for (i = 0; i < numworker; i++)
		{
			tempwork[i] = w[i];//מעתיק תמצביעים למשתנה זמני
		}
	}
	Worker * new_sto = new Worker(name, id, y, m, d,hour_pay);//יצרת אוביקט חדש
	tempwork[numworker - 1] = new_sto;//

	delete[] w;//מחיקת המערךהישן
	w = new Worker*[numworker];//הקצאה מחדש
	for (i = 0; i < numworker; i++)
	{
		w[i] = tempwork[i];//מעתיק לחדש 
	}
	delete[] tempwork;
}

void update_sto(int &num_sto, Student**& s)
{
	int index, grade;
	cout << "enter the num of the student in the sistem:" << endl;
	cin >> index;
	--index;
	if (index<0 || index>=num_sto)
	{
		cout << "there is no student like this" << endl;
		return;
	}
	cout << "enter the grade you want add" << endl;
	cin >> grade;
	if (grade<0 || grade>100)
	{
		cout << "illigel grade" << endl;
		return;
	}
	s[index]->add_grade(grade);
}

void update_worker(int &numworker, Worker**& w) 
{
	int index, h,extre_h;
	cout << "enter the num of the worker in the sysetem" << endl;
	cin >> index;
	--index;
	if (index<0 || index>=numworker)
	{
		cout << "there is no worker like this " << endl;
		return;
	}
	cout << "enter the reglar hour " << endl;
	cin >> h;
	cout << "enter the extra hour " << endl;
	cin >> extre_h;
	w[index]->set(h, extre_h);
}

void print( Worker **&w,  int sizew,  Student **&s,  int sizes)
{
	int i;
	cout << "student:\n ";
	for (i = 0; i < sizes; i++)
	{
		s[i]->print();
		cout << endl;
	}
	cout << endl;
	cout << endl;
	cout << "workers:\n ";
	for (i = 0; i < sizew; i++) 
	{
		w[i]->print();
		cout << endl;
	}
	cout << endl;
	cout << endl;

}

void free(Worker **&w, int sw, Student **&s, int ss) 
{
	int i;
	for (i = 0; i < ss; i++)//student
	{
		delete s[i];
	}
	delete[] s;

	for ( i = 0; i < sw; i++)//worker
	{
		delete w[i];
	}
	delete[] w;
}

bool checkerrr(const MyDate & a, const MyDate & b)//fun helper i do it friend so it will gey mydate
{
	if ((b.day == a.day) && (b.month == a.month))
		return true;
	else 
		return false;
}

MyDate make()
{
	int d, m, y=2000;
	cout << "enter birthey to check by day montch (noneed year becese it doesnt meter birtheey)\n";
	cin >> d >> m ;
	//make pointer to this birt to chck
	return  MyDate(y, m, d);
}