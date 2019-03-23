#ifndef SETLINKLIST_H
#define SetLinkList_H 

#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class SetLinkList 
{
private:
	class Node
	{
	private:
		int data;
		Node * next;
	public:
		Node(int a=NULL); //ctor
		Node(const Node &);//copy
		void printnode()const;
		friend class SetLinkList;
	};// end of class Node  Node* list_head; public: 
	Node* list_head;
	void print()const;
	public:
		SetLinkList();//ctor defalt
		SetLinkList(SetLinkList &);//copy
		bool empty()const;// for see if empty
		~SetLinkList();//dtor for setlink fixx
		SetLinkList & operator+=(const int &);//1
		SetLinkList & operator-=(const int &);//2
		SetLinkList & operator+(const SetLinkList & );//3
		SetLinkList & operator-(const SetLinkList &);
		SetLinkList & operator-- ();//6
		SetLinkList & operator-- (int);//7
		bool operator==(SetLinkList&);//9
		bool operator!=(SetLinkList&);//10
		friend ostream & operator << (ostream & , SetLinkList & );

		void Reverse();//bonos
		void Sort();//bonos


};


#endif//SETLINKLIST_H 