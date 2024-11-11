    #include <iostream>
    #include <stack>
    using namespace std;

    int main()
    {
        //creation
        stack<int> st;// follows LIFO

        //insertion
        st.push(10);//10
        st.push(20);//10 20
        st.push(30);//10 20 30
        st.push(40);//10 20 30 40

        //size
        cout << "size is:"<< st.size() <<endl; 
        

        st.pop();//10 20 30 

        cout << "new size is:"<< st.size() <<endl; 

        cout << "front element is:" <<st.top() << endl;
        
        //empty
        if(st.empty()==true)
        {
            cout << "vector is not empty" << endl;
        }
        else
        {
            cout << "vector is not empty" << endl;
        }

        stack<int> first;
        stack<int> second;

        first.push(10);    
        first.push(20);
        first.push(30);
        first.push(40);
        first.push(50);

        second.push(100);    
        second.push(200);
        second.push(300);
        second.push(400);
        second.push(500);

        cout << "old first element of first stueue is:" << first.top() << endl;

        first.swap(second);

        cout << "new first element of first stueue is:" << first.top() << endl;
        return 0;
    }