#include<iostream>
using namespace std;

class Queue
{
        private:
        
        int* arr;
        int front, rear;
        int size;

        public:
        Queue();
        //if Q is full
        bool isFullQ();
        //if Q is empty
        bool isEmptyQ();
        //add to the Q
        void enQ(int val);
        //remove from the Q
        void deQ();
        //display all values from Q
        void displayQ();
};

