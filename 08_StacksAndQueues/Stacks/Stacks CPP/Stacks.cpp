#include "Stacks.hpp"

Stack::Stack() 
{
        top = -1;
        size = 7;
        arr = new int[size];
}


bool Stack::isFull() 
{
        return top == size - 1;
}

bool Stack::isEmpty() 
{
        return top == -1;
}

void Stack::push(int val) 
{
        if (isFull()) {
                cout << "Full Stack" << endl;
                return;
        }
        arr[++top] = val;
        cout << "Pushed " << val << endl;
}

void Stack::pop() 
{
        if (isEmpty()) {
                cout << "Empty Stack" << endl;
                return;
        }
        int val = arr[top--];
        cout << "Popped " << val << endl;
}

void Stack::display() 
{
        cout << "-----Stack-----" << endl;
        if (isEmpty()) {
                cout << "Empty" << endl;
                return;
        }
        for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
        }
}


int main() {
    Stack s;

    s.push(2);
    s.display();
    s.push(3);
    s.push(5);
    s.display();
    s.pop();
    s.display();
    s.push(7);
    s.push(1);
    s.pop();
    s.display();
    s.push(8);
    s.push(0);
    s.display();

    return 0;
}
