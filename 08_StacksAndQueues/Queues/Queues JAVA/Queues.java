import java.io.*;

class Queues
{
        int front;
        int rear;
        int size;
        int arr[];
        
        public Queues()
        {
                front = -1;
                rear = -1;
                size = 7;
                arr = new int[size];
        }

        public boolean isFullQ()
        {
                if(front == 0 && rear == size - 1)
                        return true;
                return false;
        }

        public boolean isEmptyQ()
        {
                if(front == -1)
                        return true;
                return false;
        }

        public void enQ(int val)
        {
                if(isFullQ())
                {
                        System.out.println("Full Queue");
                        return;
                }
                if(front == -1)
                        front = 0;
                rear++;
                arr[rear] = val;
                System.out.println("Added " + val);
        }

        public void deQ()
        {
                int val;
                if(isEmptyQ())
                {
                        System.out.println("Empty Queue");
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
                System.out.println("Deleted " + val);
                
        }

        public void displayQ()
        {
                System.out.println("-----Queue-----");
                if(isEmptyQ())
                {
                        System.out.print("Empty\n");
                        return;
                }
                System.out.print("vv Front\n");
                for(int i = front; i <= rear; ++i)
                {

                        System.out.print( i + " | " + arr[i] + "\n");
                }
                System.out.println("^^ Rear");
        }


        public static void main(String[] args) throws IOException 
        {
                Queues q = new Queues();

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

        }
}