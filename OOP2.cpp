#include <iostream>
#include <string.h>
using namespace std;
class LinkedList;
class ListNode{
	private:
		int data;
		string name;
		ListNode *next = new ListNode("",0);
	public:
		ListNode(string n,int x):name(n),data(x),next(){};
		ListNode(string n):name(n),next(){}
		friend class LinkedList;
};
class LinkedList{
	private:
		ListNode *first = 0;
	public:
		LinkedList():first(0){};
		void print_list();
		void push_front(string,int);
		void push_back(string,int);
		void Delete(string,int);
		void Clear();
		void Reverse();
};
void LinkedList::print_list(){
	if(first == 0){
		cout<<"The list is empty\n";
		return ;
	}
	ListNode *current = first;
	while(current != 0){
		cout<<"Name = "<<current->name<<"("<<current->data<<")"<<endl;
		current = current ->next;
	}
	cout<<endl;
}
void LinkedList::push_back(string n,int x){
	ListNode *newNode = new ListNode(n,x);
	if(first == 0){
		first = newNode;
		return ;
	}
	ListNode *current = first;
	while(current->next != 0){
		current = current->next;
	}
	current -> next =newNode;
}
void LinkedList::push_front(string n,int x){
	ListNode *newNode = new ListNode(n,x);
	newNode->next = first;
	first = newNode;
}
void LinkedList::Reverse(){
	ListNode *previous = 0,
			 *current = first,
			 *preceding = first -> next;
	if(first == 0 || first -> next == 0){
		return ;
	}
	while(preceding != 0){
		current -> next = previous;
		previous = current;
		current = preceding;
		preceding = preceding -> next;
	}
	current -> next = previous;
	first = current;
}
void LinkedList::Clear(){
	while(first != 0){
		ListNode *current = first;
		first = first -> next;
		current =0;
		delete current;
	}
}
void LinkedList::Delete(string n,int x){
	ListNode *previous = 0,
			 *current = first;
	while(current != 0 && current->name != n){
		previous = current;
		current = current -> next;
	}
	if(current == 0){
		cout<<"The empty doesn't has "<<n<<endl;
	}else if(current == first){
		previous = first->next;
		current = 0;
		delete current;
		first = previous;
	}else{
		previous -> next =current -> next;
		current = 0;
		delete current;
	}	
}

int main(){
	LinkedList list;
	list.print_list();
	list.push_back("kevin",5);
	list.push_front("Rose",4);
	list.push_front("joe",3);
	list.push_back("Viecent",7);
	list.print_list();
	list.Reverse();
	list.print_list();
	list.Delete("fasir",10);
	list.print_list();
	list.Delete("Rose",4);
	list.print_list();
	list.Delete("Viecent",4);
	list.print_list();
	list.Clear();
	list.print_list();
	
	return 0;
}
