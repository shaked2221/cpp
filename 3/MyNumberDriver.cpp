#include "MyNumber.h"
/*shaked astemker
campus ber shave
id 311499917
job 1
*/
int main() {
	int num;
	cout << "enter a num ";
	cin >> num;
	MyNumber num1(num);
	num1.print();
	cout << "copy ctor\n";
	MyNumber num2 = num1;//בנאי מעתיק
	num2.print();
	cout << "the full num in print is:\n";
	cout << num2.all_num() << endl;
	cout << "enter a num to change the num ";
	cin >> num;
	num1.change_num(num);//שינוי על ידי מספר אחר
	num1.print();
	cout << "change by object:\n";
	num2.change_num(num1);//שינוי על ידי אוביקט
	num2.print();
	cout << " chack compare:\n";
	cout << num1.comper_other_object(num2)<<endl; 
	cout << " add:\n";
	MyNumber* num3 = num1.add(num2);
	cout << endl;
	num3->print();
	cout << " minus:\n";
	MyNumber* num4 = num1.minus(num2);
	num3->print();

}