#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Node{
    int data;
    Node* pNext;
};

struct Queue
{
    Node* front;
    Node* rear;
};

Node* preFront = new Node();

Node* CreateNode(int data)
{
    Node* p = new Node();
    p->data = data;
    p->pNext = nullptr;
    return p;
}

bool isEmpty(Queue q){
    if (q.front == nullptr)
        return true;
    else
        return false;
}

void CreateQueue(Queue& q){
    q.front = q.rear = nullptr;
}

void Show(Queue q){
    if (!isEmpty(q))
    {
        preFront = nullptr;
        for (Node* i = q.rear; i != nullptr; i = i->pNext){
            cout << i->data;
            if (i->pNext == q.front){
                preFront = i;
            }
            if (i != q.front){
                cout << " --> ";
            }
        }
        cout << endl;
    }
    else
        cout << "Empty\n";
}

void enqueue(Node* p, Queue& q){
    if (isEmpty(q)){
        q.front = q.rear = p;
    } else{
        p->pNext = q.rear;
        q.rear = p;
    }
}

void dequeue(Queue& q, Node*& p){
    if (!isEmpty(q)){
        p = q.front;
        if (preFront != nullptr) preFront->pNext = nullptr;
        q.front = preFront;
    }
}

void search(Queue q, int key, Node*& p){
    for (Node* i = q.rear; i != nullptr; i = i->pNext){
        if (i->data == key){
            cout << "Founded!\n";
            p = i;
            return;
        }
    }
    cout << "Not founded!\n";
}

int random()
{
    srand(time(NULL));
    int res = rand() % 100;
    return res;
}

int main()
{
    int choice;
    Queue q;
    CreateQueue(q);

    while (true)
    {
        Show(q);
        cout << "0. End \n";
        cout << "1. Enqueue randomly \n";
        cout << "2. Dequeue \n";
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
            enqueue(CreateNode(random()), q);
            break;
        case 2:
            dequeue(q, p);
            break;
        case 3:
            cout<< "input a: ";
            cin >> a;
            search(q, a, p);
            break;
        default:
            break;
        }
    }
}