/*shaked astemker
campus ber shave
id 311499917
job 3
*/

#include "setLinkList.h"

int main() {

	SetLinkList list1; 
	for (int i = 20; i<100; i += 30) 
		list1 += i;
	cout << " list1: " << list1 << endl; //  list1: ( 80 , 50, 20 ) 
	SetLinkList list2(list1); 
	list2+=200;  
	list2+=300; 
	cout<<" list2: "<<list2<<endl;// list2: ( 300 , 200 , 80 , 50 , 20 )  
	for(int i=25;i<60;i++)   
		list1-=i; 
	list1+=55;  
	cout<<endl<<endl; 
	cout<<" list1 : "<<list1<<endl;//  list1 : ( 55 , 80 , 20 )    
	cout<<" list2 : "<<list2<<endl;//  list2 : ( 300 , 200 , 80 , 50 , 20 ) 
	SetLinkList temp; 
	temp=list1+list2; 
		cout<<" Union : "<<temp;// Union : ( 55 , 80 , 20 , 300 , 200 , 50 )  
	cout<<endl<<endl; 
	cout<<" list1 : "<<list1<<endl; //  list1 : ( 55 , 80 , 20 )   
	cout<<" list2 : "<<list2<<endl;//  list2 : ( 300 , 200 , 80 , 50 , 20 )    
	temp=list1-list2; 
	cout<<" ----- Minus : "<<temp;// ----- Minus : ( 55 )
	cout<<endl<<endl; 
	SetLinkList list3(list2);// 300   200   80   50   20 

		cout << " prefix --:"; 
		cout << "list3:" << --list3 << endl;// prefix --:list3: (200 , 80 , 50 , 20 )   
		cout<<"list3 after prefix :"<<list3<<endl;// list3 after prefix : ( 200 , 80 , 50 , 20 )
		cout<<" postfix --:"; 
		cout<<"list2  :"<< list2--<<endl; // postfix --:list2  : ( 300 , 200 , 80 , 50 , 20 )  
		cout<<"list2 after postfix :"<<list2<<endl; // list2 after postfix : ( 300 , 200 , 80 , 50 ) 
		cout<<endl<<endl; 
		SetLinkList list4; 
		list4+=50; 
		list4+=200; 
		list4+=300; 
		cout<<" list 4 :"<<list4<<endl; // list 4 : ( 300 , 200 , 50 )
		if(list4==list2)   
			cout<<" equals";  
		else   
			cout<<" not equals";  //not equals  
		cout<<endl<<endl; 
		list4+=80; 
		if(list4==list2)  
			cout<<" equals";  //equals 
		else   
			cout<<" not equals";
		cout<<endl<<endl;  
		if(list1!=list2)  
			cout<<" not equals";  //not equals  
		else  
			cout<<"  equals";     
		cout<<endl<<endl;
		//////bonos
		cout << endl << list4; // ( 80 , 300 , 200 , 50 )
		list4.Reverse();
		cout<<endl<<list4; // ( 50 , 200 , 300 , 80 ) 
		SetLinkList listTest;
		listTest+=15; 
		listTest+=10;
		listTest+=30;
		listTest+=25;
		cout<<endl<<listTest; //  ( 25 , 30 , 10 , 15 )
		listTest.Sort(); 
		cout<<endl<<listTest;
		return 0; 
} 