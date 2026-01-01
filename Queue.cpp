#include <iostream>
using namespace std;

struct Node{

    int value;
    Node* next;
};

class queue{

private:
    Node* front;
    Node* end;

public:
    queue(){
        front = NULL;
        end = NULL;
    }

    void enqueue(int x){

        Node* newNode = new Node;
        newNode -> value = x;
        newNode -> next = NULL;

        if (end == NULL){ //queue is empty
            front = newNode;
            end = newNode;
            return;
        }

        end -> next = newNode;
        end = newNode;

    }

    int dequeue(){

        if (front == NULL){

            cout << "Queue is empty!";
            return -1;
        }

        Node* temp = front;
        int returnVal = front -> value;
        front = front -> next;
        
        if (front == NULL){ // The queue has been emptied
            end = NULL;
        }

        delete temp;
        return returnVal;

    }

    bool isEmpty(){
        return front == NULL;
    }
};

int main(){ //test

    queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << endl; // 1
    cout << q.dequeue() << endl; // 2
    cout << q.dequeue() << endl; // 3
}