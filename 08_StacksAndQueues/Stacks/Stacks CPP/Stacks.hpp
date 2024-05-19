#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int* arr;

public:
    Stack();
    bool isFull();
    bool isEmpty();
    void push(int val);
    void pop();
    void display();
};

