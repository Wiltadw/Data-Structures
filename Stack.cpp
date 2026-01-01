#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class Stack{
private:
    Node* top;
public:
    Stack(){ top = NULL; };

    void push(int x){

        Node* newNode = new Node;
        newNode -> value = x;
        newNode -> next = top;
        top = newNode;
    }

    int pop(){

        if (top == NULL){

            cout << "Stack is empty!\n";
            return -1;
        }

        Node* temp = top;
        int returnVal = top -> value;
        top = top -> next;
        delete temp;
        return returnVal;
    }
};

int main(){ //test
    
    Stack s;

    s.push(1);
    s.push(2);
    cout << s.pop() << "\n";
    cout << s.pop();
    
}