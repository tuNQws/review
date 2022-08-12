#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int data;
    Node* pNext;
};

struct Stack
{
    Node* top;
};

Node* CreateNode(int data)
{
    Node* p = new Node();
    p->data = data;
    p->pNext = nullptr;
    return p;
}

void CreateStack(Stack& s){
    s.top = nullptr;
}

bool isEmpty(Stack s){
    if (s.top == nullptr){
        return true;
    }
    return false;
}

void Show(Stack s){
    if (s.top != nullptr)
    {
        for (Node* i = s.top; i != nullptr; i = i->pNext){
            cout << i->data;
            if (i->pNext != nullptr){
                cout << " --> ";
            }
        }
        cout << endl;
    }
    else
        cout << "Empty\n";
}

int random()
{
    srand(time(NULL));
    int res = rand() % 100;
    return res;
}

void enstack(Node* p, Stack& s){
    if (isEmpty(s)){
        s.top = p;
    } else{
        Node* q = s.top;
        p->pNext = q;
        s.top = p;
    }
}

void destack(Stack& s, Node*& p){
    if (!isEmpty(s)){
        p = s.top;
        s.top = s.top->pNext;
    }
}

void search(Stack s, int key, Node*& p){
    for (Node* i = s.top; i != nullptr; i = i->pNext){
        if (i->data == key){
            cout << "Founded!\n";
            p = i;
            return;
        }
    }
    cout << "Not founded!\n";
}

int main()
{
    int choice;
    Stack s;
    CreateStack(s);

    while (true)
    {
        Show(s);
        cout << "0. End \n";
        cout << "1. Enstack randomly \n";
        cout << "2. Destack \n";
        cout << "3. Search for \"a\" \n";
        cout << " ====================== \n";
        cout << "Your choice: ";
        cin >> choice;
        Node* p = new Node();
        int a;

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            enstack(CreateNode(random()), s);
            break;
        case 2:
            destack(s, p);
            break;
        case 3:
            cout<< "input a: ";
            cin >> a;
            search(s, a, p);
            break;
        default:
            break;
        }
    }
}
