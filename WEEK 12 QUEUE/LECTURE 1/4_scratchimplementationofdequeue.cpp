    #include <bits/stdc++.h>
    using namespace std;

    class Deque
    {
        private:
            int *arr;
            int n;
            int rear;
            int front;
        
        public:
            Deque(int size)
            {
                this->n = size;
                arr = new int(size);
                front = -1;
                rear = -1; 
            } 

            void pushfront(int val)
            {
                //there is no space to insert at lft of array deque
                if(front == 0)
                {
                    cout << "Overflow" << endl;
                    return;
                }
                //pehle se empty thi
                else if(front == -1 && rear == -1)
                {
                    front++;
                    rear++;
                    arr[front]=val;
                }

                //normal flow
                else
                {
                    front--;
                    arr[front]=val;
                }
            }

            void pushback(int val)
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

            void popfront()
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

            void popback()
            {
                //no elemnt to pop
                if(front == -1 && rear == -1)
                {
                    cout << "Queue underflow" << endl;
                    return;
                }
                
                //single element
                else if(front == rear)
                {
                    arr[front] = -1;
                    front= -1;
                    rear = -1;
                }

                //normal flow
                else
                {
                    arr[rear] = -1;
                    rear--;
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
        Deque dq(5);
        dq.pushfront(10);
        dq.print();
        dq.pushfront(20);
        dq.print();
        dq.pushback(15);
        dq.print();
        dq.pushback(30);
        dq.print();
        dq.pushfront(100);
        dq.print();
        dq.popback();
        dq.print();
        dq.popback();
        dq.print();
        return 0;
    } 