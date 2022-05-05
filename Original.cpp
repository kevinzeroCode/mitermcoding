// 
// Linkedlist.cpp
// C++ code, harshly and successfully compiled by g++
//

#include <iostream>
using std::cout;
using std::endl;

class LinkedList;    // ���F�Nclass LinkedList�]��class ListNode��friend,
                     // �ݭn���ŧi
class ListNode{
private:
    int data;
    ListNode *next = new ListNode;
public:
    ListNode():data(0),next(0){};
    ListNode(int a):data(a),next(0){};

    friend class LinkedList;
};

class LinkedList{
private:
    // int size;                // size�O�ΨӰO��Linked list������, �D���n
    ListNode *first= new ListNode;            // list���Ĥ@��node
public:
    LinkedList():first(0){};
    void PrintList();           // �L�Xlist���Ҧ����
    void Push_front(int x);     // �blist���}�Y�s�Wnode
    void Push_back(int x);      // �blist�����ڷs�Wnode
    void Delete(int x);         // �R��list���� int x
    void Clear();               // ����list�R��
    void Reverse();             // �Nlist����: 7->3->14 => 14->3->7
};


void LinkedList::PrintList(){

    if (first == 0) {                      // �p�Gfirst node���VNULL, ���list�S�����
        cout << "List is empty.\n";
        return;
    }

    ListNode *current = first;             // ��pointer *current�blist������
    while (current != 0) {                 // Traversal
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


void LinkedList::Push_front(int x){

    ListNode *newNode = new ListNode(x);   // �t�m�s���O����
    newNode->next = first;                 // ����first���bnewNode�᭱
    first = newNode;                       // �A��first���VnewNode�ҫ��V���O�����m
}


void LinkedList::Push_back(int x){

    ListNode *newNode = new ListNode(x);   // �t�m�s���O����

    if (first == 0) {                      // �Ylist�S��node, �OnewNode��first
        first = newNode;
        return;
    }

    ListNode *current = first;
    while (current->next != 0) {           // Traversal
        current = current->next;
    }
    current->next = newNode;               // �NnewNode���blist������
}


void LinkedList::Delete(int x){

    ListNode *current = first,      
             *previous = 0;
    while (current != 0 && current->data != x) {  // Traversal
        previous = current;                       // �p�Gcurrent���VNULL
        current = current->next;                  // �άOcurrent->data == x
    }                                             // �Y����while loop

    if (current == 0) {                 // list�S���n�R��node, �άOlist��empty
        std::cout << "There is no " << x << " in list.\n";
        // return;
    }
    else if (current == first) {        // �n�R����node��n�blist���}�Y
    	first = current->next;          // ��first����U�@��node
        delete current;                 // �p�Glist�u���@��node, ����first�N�|���VNULL
        current = 0;                    // ����гQdelete��, �N����VNULL, �i�H�קK�����nbug
        // return;                     
    }
    else {                              // ��l���p, list�������R����node, 
        previous->next = current->next; // �ӥBnode����first, ����previous����NULL
        delete current;
        current = 0;
        // return;
    }
}


void LinkedList::Clear(){

    while (first != 0) {            // Traversal
        ListNode *current = first;
        first = first->next;
        delete current;
        current = 0;
    }
}


void LinkedList::Reverse(){

    if (first == 0 || first->next == 0) {
        // list is empty or list has only one node
        return;
    }

    ListNode *previous = 0,
             *current = first,
             *preceding = first->next;

    while (preceding != 0) {
        current->next = previous;      // ��current->next��V
        previous = current;            // previous���ᮿ
        current = preceding;           // current���ᮿ
        preceding = preceding->next;   // preceding���ᮿ
    }                                  // preceding��s��NULL�Y���Xwhile loop

    current->next = previous;          // ����current���̫�@��node, �Ncurrent->next��V
    first = current;                   // ��sfirst��current
}


int main() {

    LinkedList list;     // �إ�LinkedList��object
    list.PrintList();    // �ثelist�O�Ū�
    list.Delete(4);      // list�O�Ū�, �S��4
    list.Push_back(5);   // list: 5
    list.Push_back(3);   // list: 5 3
    list.Push_front(9);  // list: 9 5 3
    list.PrintList();    // �L�X:  9 5 3
    list.Push_back(4);   // list: 9 5 3 4
    list.Delete(9);      // list: 5 3 4
    list.PrintList();    // �L�X:  5 3 4
    list.Push_front(8);  // list: 8 5 3 4
    list.PrintList();    // �L�X:  8 5 3 4
    list.Reverse();      // list: 4 3 5 8
    list.PrintList();    // �L�X:  4 3 5 8
    list.Clear();        // �M��list
    list.PrintList();    // �L�X: List is empty.

    return 0;
}

