#include "Queues.hpp"

Queue::Queue()
{
        front = -1;
        rear = -1;
        size = 7;
        arr = new int[size];
}

bool Queue::isFullQ()
{
        if(front == 0 && rear == size - 1)
                return true;
        return false;
}

bool Queue::isEmptyQ()
{
        if(front == -1)
                return true;
        return false;
}

void Queue::enQ(int val)
{
        if(isFullQ())
        {
                cout << "Queue is full\n";
                return;
        }
        if(front == -1)
                front = 0;
        rear++;
        arr[rear] = val;
        cout << "Added " << val << endl;
}

void Queue::deQ()
{
        int val;
        if(isEmptyQ())
        {
                cout << "Empty Queue\n";
                return;
        }
        val = arr[front];
        if(front >= rear)
        {
                front = -1;
                rear = -1;
        }
        else
        {
                front++;
        }

        cout << "Deleted " << val << endl;
} 

void Queue::displayQ()
{
        cout << "-----Queue-----\n";
        if(isEmptyQ())
        {
                cout << "Empty\n";
                return;
        }
        cout << "vv Front\n";
        for(int i = front; i <= rear; ++i)
        {

                cout << i << " | " << arr[i] << "\n";
        }
        cout << "^^ Rear" << endl;
}

int main()
{
        Queue q;

        q.enQ(2);
        q.displayQ();
        q.enQ(3); 
        q.enQ(5);
        q.displayQ();
        q.deQ();
        q.displayQ();
        q.enQ(7);
        q.enQ(1);
        q.deQ();
        q.displayQ();
        q.enQ(8);
        q.enQ(0);
        q.displayQ();

        return 0;
}