    #include <bits/stdc++.h>
    using namespace std;

    class CircularQueue
    {   
        private:
            int *arr;
            int n;
            int front;
            int rear;
        public:
            CircularQueue(int size)
            {
                this->n = size;
                arr = new int[size];
                front = -1;
                rear = -1;
            }     

            void push(int val)
            {
                //4 cases:overflow,first element,circular nature, normal flow
                if( (front == 0 && rear == n-1) || (rear==front-1) )
                {
                    cout << "overflow" << endl;
                    return;
                }

                //single eelemtn insert
                else if(front == -1 && rear ==-1)
                {
                    front++;
                    rear++;
                    arr[rear]=val;
                }  

                //circular nature
                else if(rear == n-1)
                {
                    rear=0;
                    arr[rear] = val;
                }

                //normal condition
                else
                {
                    rear++;
                    arr[rear]=val;
                }
            }

            void pop()
            {
                //cases:underflow,first element,circular nature, normal flow
                if(front==-1 && rear==-1)
                {
                    cout << "underflow" << endl;
                    return;
                }

                //single element
                else if(front == rear)
                {
                    arr[front] = -1;
                    front = -1;
                    rear = -1;
                }

                //circular nature
                else if(front == n-1)
                {
                    arr[front] = -1;
                    front = 0;

                }

                //normal case
                else
                {
                    arr[front] = -1;
                    front++;
                }
            }

            int getsize()
            {
                if(front==-1 & rear ==-1)
                {
                    return 0;
                }
                else if(rear>front)
                {
                    return rear-front+1;
                }
                else if(rear == front)
                {
                    return 1;
                }
                else
                {
                    return n-front+rear+1;
                }
            }
            
            int getfront()
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

            bool isempty()
            {
                if(front==-1 && rear==-1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            void print()
            {
                for(int i=0; i<n; i++)
                {
                    cout << arr[i] << " ";
                }cout << endl;
            }
    };

    int main()
    {
        CircularQueue q(5);
        q.push(5);
        q.print();
        q.push(20);
        q.print();
        q.push(30);
        q.print();
        q.push(40);
        q.print();
        q.push(50);
        q.print();

        q.pop();
        q.pop();
        q.print();
        //circular
        q.push(100);
        q.print();

        q.push(101);
        q.print();

        cout << q.getsize() << endl;
        cout << q.isempty() << endl;
        cout << q.getfront() << endl; 
        return 0;
    } 