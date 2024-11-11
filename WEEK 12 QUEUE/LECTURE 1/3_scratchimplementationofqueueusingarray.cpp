    #include <bits/stdc++.h>
    using namespace std;

    class Queue
    {
        private:
            int *arr;
            int n;
            int front;
            int rear;

        public:
            Queue(int size)
            {
                arr = new int(size);
                n = size;
                front = -1;
                rear = -1;
            }
            
            void push(int val)//tc=0(1)
            {
                //overflow case
                if(rear == n-1)
                {
                    cout << "Queue overflow" << endl;
                    return;
                }          
                //no element
                else if(front == -1 && rear == -1)
                {
                    rear++;
                    arr[rear]=val;
                    front++;
                }     
                //normal case
                else
                {
                    rear++;
                    arr[rear]=val;
                }
            }

            void pop()//tc=0(1)
            {
                //no element to delete
                if(front == -1 && rear == -1)
                {
                    cout << "Queue underflow" << endl;
                    return;
                }
                //single element
                else if(front == rear)
                {
                    front = -1;
                    rear = -1;
                } 
                //normal flow of deletion
                else
                {
                    arr[front] = -1;
                    front = front+1;
                }
            }

            int getfront()//tc=0(1)
            {
                if(front == -1)
                {
                    cout << "Queue is empty" << endl;
                }
                else
                { 
                    return arr[front];
                }
            }

            int getrear()//tc=0(1)
            {
                if(rear == -1)
                {
                    cout << "Queue is empty" << endl;
                }
                else
                { 
                    return arr[rear];
                }
            }

            int getsize()//tc=0(1)
            {
                //number of elements in a queue
                if(front == -1 && rear == -1)
                {
                    return 0;
                }
                else
                {
                    return rear-front+1;
                }
            }

            bool isempty()//tc=0(1)
            {
                if(front == -1 && rear == -1)
                {
                    return true;
                }
                return false;
            }
    };

    int main()
    {
        Queue q(5);
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);
        cout << "size of queue:"<< q.getsize() << endl;
        q.push(40);
        cout << q.getfront() << endl;
        q.isempty() == 1 ? cout << "Queue is empty":cout << "Queue is not empty" << endl;
        q.pop();
        q.pop();
        cout << "size of queue:"<< q.getsize() << endl;
        return 0;
    } 