    #include <bits/stdc++.h>
    using namespace std;
    
    class Stack
    {
        public:
            int* arr; //pointer to an integer
            int size; //size of stack
            int top; //peek of stack

            Stack(int capacity) //parametrized constructor
            {
                arr = new int[capacity];
                size = capacity;
                top = -1;
            }

            void push(int value)
            {
                //stack pehle se bhara hua hai 
                if(top == size-1)
                {
                    cout << "stack overflow" << endl;
                }
                else
                {
                    //normal case isme stack mai jagah hai
                    top++;
                    arr[top]=value;
                }   
            }

            void pop()
            {
                //stack is empyty cannot pop as there is no element
                if(top == -1)
                {
                    cout << "stack underflow" << endl;
                }
                else
                {
                    arr[top]=-1;
                    top--;
                }
            }

            int getsize()
            {
                return top+1;
            }

            bool isempty()
            {
                if(top == -1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }

            int gettop()
            {
                if(top == -1)
                {
                    cout << "no element as stack is empty" << endl;
                    return -1;
                }
                else
                {
                    //normal condition
                    return arr[top];
                }
            }

            void printstack()
            {
                cout << "Printing" << endl;
                //printing all the elements of stack
                for(int i=0; i < size; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
    };

    int main()
    {
        //creating a stack of initial size 5
        Stack s(5);
        s.printstack();
        s.push(10);
        s.printstack();
        s.push(20);
        s.printstack();
        s.push(30);
        s.printstack();
        s.push(40);
        s.printstack();
        s.push(50);
        s.printstack();
        s.push(60);
        s.printstack();

        cout << "Top element:" << s.gettop() << endl;
        cout << "Size:" << s.getsize() << endl;
        (s.isempty()==0) ? cout << "Stack is not empty" << endl : cout <<"Stack is empty" << endl;
        
        s.pop();
        s.printstack();
        s.pop();
        s.printstack();
        s.pop();
        s.printstack();
        s.pop();
        s.printstack();
        s.pop();
        s.printstack();
        s.pop();

        
        
        return 0;
    } 