#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int data;
    Node* pNext;
};

struct SinglyLinkedList{
    Node* pHead;
    Node* pTail;
};

Node* CreateNode(int data){
    Node* p = new Node();
    p->data = data;
    p->pNext = nullptr;
    return p;
}

void CreateList(SinglyLinkedList& l){
    l.pHead = nullptr;
    l.pTail = nullptr;
}

void Show(SinglyLinkedList l){
    if (l.pHead != nullptr){
        for (Node* p = l.pHead; p != nullptr; p = p->pNext){
            cout << p->data;
            if (p != l.pTail){
                cout << " --> ";
            }
        }
        cout << endl;
    } 
    else
        cout << "Empty\n";
}

void addHead(Node* p, SinglyLinkedList& l){
    if (l.pHead == nullptr){
        l.pHead = l.pTail = p;
    }   else{
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail(Node* p, SinglyLinkedList& l){
    if (l.pHead == nullptr){
        l.pHead = l.pTail = p;
    }   else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void deleteNode(Node* p, SinglyLinkedList& l){
    if (p == l.pHead){
        Node* q = l.pHead->pNext;
        p->pNext = nullptr;
        delete p;
        l.pHead = q;
    } else if (p == l.pTail){
        Node* preTail = new Node();
        for (Node* i = l.pHead; i != nullptr; i = i->pNext){
            if (i->pNext == l.pTail){
                preTail = i;
            }
        }
        Node* q = l.pTail;
        preTail->pNext = nullptr;
        delete q;
        l.pTail = preTail;
    }
}

int random(){
    srand(time(NULL));
	int res = rand() % 100;
	return res;
}

int main(){
    int choice;
    SinglyLinkedList l;
    CreateList(l);

    while (true){
        Show(l);
        cout << "0. End \n";
        cout << "1. Add head randomly \n";
        cout << "2. Add tail randomly \n";
        cout << "3. Delete head \n";
        cout << "4. Delete tail \n";
        cout << "5. Sort \n";
        cout << " ====================== \n";
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            addHead(CreateNode(random()), l);
            break;
        case 2:
            addTail(CreateNode(random()), l);
            break;
        case 3:
            deleteNode(l.pHead, l);
            break;
        case 4:
            deleteNode(l.pTail, l);
            break;
        default:
            break;
        }
    }
}