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
		ListNode():data(0),name(""),next(){};
		ListNode(int x):data(x),name(""),next(){};
		ListNode(string s):data(0),name(s),next(){};
		ListNode(string s,int x):data(x),name(s),next(){};
		~ListNode()=default;
		friend class LinkedList;
};
class LinkedList{
	private:
		ListNode *first = new ListNode(0);
	public:
		LinkedList():first(0){};
		void Push_back(string ,int);
		void Push_front(string ,int);
		void PrintList();
//		void Delete(int x);
//		void Delete(string s);
		void Delete(string s,int x);
		void Reverse();
		void Clear();
};
void LinkedList::PrintList(){
	ListNode *current = first;
	int size = 0;
	while(current != 0){
		cout<<current->name<<"("<<current->data<<")"<<endl;
		current = current -> next; 
		size++;
	}
	if(size==0){
		cout<<"List is empty\n";
		return ;
	}
	cout<<"The List is for size  "<<size<<endl;
}
void LinkedList::Push_back(string s,int x){
	ListNode *newNode = new ListNode(s,x);
	if(first == 0){
		first = newNode;
		return ;
	}
	ListNode *current = first;
	while(current -> next != 0){
		current = current -> next;
	}
	current -> next = newNode;
}
void LinkedList::Push_front(string s,int x){
	ListNode *newNode = new ListNode(s,x);
	newNode ->next =first;
	first = newNode;
}
void LinkedList::Delete(string s,int x){
	ListNode *current = first, *previous = 0;
	while( current != 0 && (current->data != x && current->name != s) ){
		previous = current;
		current =current->next;
	}
	if(current == 0){
		cout<<"The List didn't has this element\n";
	}else if(current == first){
		first = current->next;
		delete current;
		current = 0;
	}else{
		previous->next = current->next;
		delete current;
		current = 0;
	}
}
void LinkedList::Reverse(){
	if(first == 0 || first->next == 0){
		return ;
	}
	ListNode *previous = 0,*current = first, *preceding = first->next;
	
	while(preceding != 0){
		current->next = previous;
		previous = current;
		current = preceding;
		preceding = preceding->next;
	}
	current->next = previous;
	first = current;
}
void LinkedList::Clear(){
	while(first != 0 ){
		ListNode *newNode = first;
		first = first->next;
		delete newNode;
		newNode = 0;
	}
}
int main(){
	LinkedList list;     
	list.Push_back("B", 5); 
	list.Push_back("A", 3);
	list.Push_front("C", 9);
	list.Push_front("N", 7);
	list.Delete("C",9);
	list.Reverse();
	list.PrintList();
	list.Clear();
	list.PrintList();
	return 0;
}
