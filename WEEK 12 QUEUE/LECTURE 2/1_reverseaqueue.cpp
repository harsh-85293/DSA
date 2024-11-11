    #include <bits/stdc++.h>
    using namespace std;

    //using stack
    void reverseQueue( queue<int>&q)
    {
        stack<int>st;
        while(!q.empty())
        {
            int ele=q.front();
            q.pop();
            st.push(ele);
        }
        //ab tak saare eleements push ho jayenge 
        //ab unhe stack se nikalenge tab vo reverse order mai ho gaye honge
        while(!st.empty())
        {
            int ele=st.top();
            st.pop();
            q.push(ele);
        }
    }

    //using recursion
    void reverseQueueusingrec(queue<int>&q)
    {
        //base case
        if(q.empty())
        {
            return;
        }

        //ek case
        int ele=q.front();
        q.pop(); 

        //baaki recursion sambhal lega
        reverseQueue(q);

        //backtracking
        q.push(ele);
    }


    int main()
    {
        queue<int>q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        
        reverseQueue(q);
        //reverseQueueusingrec(q);

        //print all eleements of a queue
        while(!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        } 
        return 0;
    } 