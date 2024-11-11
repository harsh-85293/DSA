    //implement 2 stack in an array
    #include <bits/stdc++.h>
    using namespace std;

    class Stack
    {
        public:
            int* arr;
            int size;
            int top1;
            int top2;

            Stack(int capacity)
            {
                arr = new int(capacity);
                size = capacity;
                top1 = -1;
                top2 = size;
            }

            void push1(int value)
            {
                //if space available then push if not dont push
                //else stack overflow kar jayega
                if(top2-top2 == 1)
                {
                    //cannot insert
                    cout << "Stack overflow" << endl;  
                }
                else
                {
                    top1++;
                    arr[top1]=value;
                }
            }

            void push2(int value)
            {
                //if space available then push if not dont push
                //else stack overflow kar jayega
                if(top2-top2 == 1)
                {
                    //cannot indrt
                    cout << "Stack overflow" << endl;  
                }
                else
                {
                    top2++;
                    arr[top2]=value;
                }
            }

            void pop1()
            {
                if(top1==-1)
                {
                    cout << "Stack underflow" << endl;
                }

                else
                {
                    arr[top1]=0;
                    top1--;
                }
            }

            void pop2()
            {
                if(top2==size)
                {
                    cout << "Stack underflow" << endl;
                }

                else
                {
                    arr[top2]=0;
                    top2++;
                }
            }

            void print()
            {
                cout << "Top1:" << top1 << endl;
                cout << "Top2:" << top2 << endl;
                for(int i=0;i<size;i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl; 
            }
    };

    int main()
    {
        Stack s(5);
        s.push1(10);
        s.print();
        s.push1(90);
        s.print();
        s.push1(80);
        s.print();
        s.pop1(); 
        s.print();
        
        s.push2(1);
        s.print();
        s.push2(2);
        s.print();
        s.push2(3);
        s.print();
        return 0;
    } 