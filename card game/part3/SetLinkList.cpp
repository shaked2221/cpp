#include "setLinkList.h"

////node
SetLinkList::Node::Node(int a)//ctor
{
	this->data = a;
	this->next = NULL;
}

SetLinkList::Node::Node(const SetLinkList::Node & other) : data(other.data) { //copy c'tor node 
	if (other.next != NULL)
		next = new Node(*(other.next));
	else
		next = NULL;
}

void SetLinkList::Node::printnode() const
{
	cout << this->data;
}


SetLinkList::SetLinkList()//ctor defplt
{
	list_head = NULL;
}


SetLinkList::SetLinkList(SetLinkList & other)//copy setlink
{
	if (other.empty())
		list_head = NULL;
	else
		list_head = new Node(*(other.list_head));
}

bool SetLinkList::empty() const//to check if empty
{
	return (list_head == NULL);//if true list head = null
}

SetLinkList::~SetLinkList()
{
	if (!empty())
	{
		Node *curnnt, *temp;
		curnnt = list_head;
		while (curnnt->next!= NULL)
		{
			temp = curnnt;
			curnnt = curnnt->next;
			delete temp;
		}
	}
}

SetLinkList & SetLinkList::operator+=(const int & num)
{
	int flag = 0;
	Node* temp = list_head;
	while (temp!=NULL)
	{
		if (temp->data == num)//to check if the num is exsis in the system
		{
			flag = 1;
			temp = temp->next;
			break;
		}
		else
			temp = temp->next;
	}
	if (flag == 0)//if the num not in the nod
	{
		Node* Newn = new Node(num);
		Newn->next = list_head;
		list_head = Newn;
	}
	return *this;
}

SetLinkList & SetLinkList::operator-=(const int & num)
{
	Node* temp = list_head;
	int count = 0;
	while (temp != NULL)
	{

		if (temp->data == num)//if the num exsist
		{
			Node *x;
			x = temp->next;
			delete[] temp;
			temp = list_head;
			for (int i = 0; i < count-1; i++)//to contine the link list from the end of what nedd to dlete
			{
				temp = temp->next;
			}
			temp->next = x;
		}
		else
		{
			count++;
			temp = temp->next;
		}
	}
	return *this;
}

SetLinkList & SetLinkList::operator+(const SetLinkList & other)
{
	SetLinkList Neww = *this;//copy the fierst
	Node* temp = other.list_head;
	while (temp!= NULL)
	{
		*this += temp->data;//to chack numby num
		temp = temp->next;//go to next
	}
	return *this;
}

SetLinkList & SetLinkList::operator-(const SetLinkList & other)
{
	SetLinkList Neww = *this;//copy the fierst êïîì
	Node* temp = other.list_head,*x;
	while (temp != NULL)
	{
		*this -= temp->data;//to chack numby num
		temp = temp->next;//go to next
	}
	this->list_head = list_head->next;//àí ëïñ àé÷ ðùò
	return *this;
}

SetLinkList & SetLinkList::operator-- ()
{
	Node * temp,*x;
	x = list_head;
	temp = this->list_head->next;//the new begin in the next and then delete the firest who was before
	list_head = temp;
	delete x;
	return *this;
}

SetLinkList & SetLinkList::operator--(int)
{
	Node *temp;
	int count = 0;
	temp = list_head;
	while (temp!=NULL)
	{
		temp = temp->next;
		count++;
	}
	delete[] temp;//delte the last one
	temp = NULL;
	temp = list_head;
		while (count>1)
		{
			count--;
			temp = temp->next;
		}
temp->next = NULL;//to deltet the point who was point to the last one
return *this;
}

bool  SetLinkList::operator==(SetLinkList &other)
{
	Node* one, *two, *temp1, *temp2;
	int cont1 = 0, conut2 = 0, counteqal = 0;
	one = this->list_head;
	two = other.list_head;
	temp1 = one;
	temp2 = two;
	while (temp1->next != NULL)//check theit two size
	{
		cont1 += 1;
		temp1 = temp1->next;
	}
	while (temp2->next != NULL)
	{
	conut2++;
	temp2 = temp2->next;
	}
	if (cont1 != conut2)//if the size dont same dont eqal
		return false;
	while (one->next!=NULL)
	{
		two = other.list_head;
		while (two->next!=NULL)//twho check if num in other exsis in the fiesrts
		{
			if (one->data == two->data)
			{
				counteqal++;
				break;
			}
			else
				two = two->next;
		}
		one = one->next;
	}
	if (counteqal == cont1)//not gat if not eqal so not need chae coun2
		return true;
	else
		return false;
}

bool  SetLinkList::operator!=(SetLinkList &other)
{
	Node* one, *two, *temp1, *temp2;
	int cont1 = 0, conut2 = 0, counteqal = 0;
	one = this->list_head;
	two = other.list_head;
	temp1 = one;
	temp2 = two;
	while (temp1->next != NULL)//check theit sizes
	{
		cont1 += 1;
		temp1 = temp1->next;
	}
	while (temp2->next != NULL)
	{
		conut2++;
		temp2 = temp2->next;
	}
	if (cont1 != conut2)//if the size dont same dont eqal
		return true;
	while (one->next != NULL)
	{
		two = other.list_head;
		while (two->next != NULL)
		{
			if (one->data == two->data)
			{
				counteqal++;//to check if num in one is in the other else
				break;
			}
			else
				two = two->next;
		}
		one = one->next;
	}
	if (counteqal == cont1)//not gat if not eqal so not need chae coun2
		return false;
	else
		return true;
}


void SetLinkList::print() const {//print nodes
	Node* current;
	current = list_head; //points on list head
	cout << '"';
	while (current!=NULL) 
		{ 
		current->printnode();//sent to print node
		cout << " ";
		current = current->next;//to the next
		}
		cout << '"' << endl;

}


ostream & operator << (ostream & out, SetLinkList & link) { //an operator that prints the nodes
	link.print();
	return out;
}
//bonos
void SetLinkList::Reverse()
{

	Node *nextNode, *current, *temp;

	for (nextNode = (list_head), current = NULL; NULL != nextNode; current = temp) {//change them from the end to begib

		temp = nextNode;
		nextNode = nextNode->next;
			temp->next = current;
	}

	(list_head) = current;//give hem the start
}

void SetLinkList::Sort()
{
	Node *a, *b, *c,*x;
	x = list_head;
	int flag=0;
	while (list_head->next!=NULL)
	{
		if (list_head->data > list_head->next->data)//if the next is bigger get int
		{
			a = list_head;
			b = list_head->next;
			c = list_head->next;
			b = a;
			a = c;
		}
		list_head = list_head->next;
	}
	list_head = x;
}
