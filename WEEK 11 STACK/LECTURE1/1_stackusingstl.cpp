    #include <iostream>
    #include <stack>
    using namespace std;
    int main()
    {
        //creation
        stack<int> s;//name s

        //insertion
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        
        //size
        cout << "size of stack is:" << s.size() << endl;

        //check empty or not
        cout << "0 if empty 1 and if not empty:"<< s.empty() << endl;//0 if empty 1 if not empty

        //peek->stack ko upar se dekhne ke liye
        cout << "peek element:" << s.top() << endl;

        //element removal->.pop()->LIFO will be used
        s.pop();
        
        //now top element will be 30
        cout << "after pop peek element:" << s.top() << endl;
        return 0;
    } 