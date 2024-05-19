import java.io.*;

class Stack {
    int top;
    int size;
    int arr[];

    public Stack() {
        top = -1;
        size = 7;
        arr = new int[size];
    }

    public boolean isFull() {
        return top == size - 1;
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public void push(int val) {
        if (isFull()) {
            System.out.println("Full Stack");
            return;
        }
        arr[++top] = val;
        System.out.println("Pushed " + val);
    }

    public void pop() {
        if (isEmpty()) {
            System.out.println("Empty Stack");
            return;
        }
        int val = arr[top--];
        System.out.println("Popped " + val);
    }

    public void display() {
        System.out.println("-----Stack-----");
        if (isEmpty()) {
            System.out.println("Empty");
            return;
        }
        for (int i = top; i >= 0; i--) {
            System.out.println(arr[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        Stack s = new Stack();

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
    }
}
