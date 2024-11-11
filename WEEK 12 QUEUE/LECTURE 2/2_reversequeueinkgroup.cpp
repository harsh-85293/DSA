    #include <bits/stdc++.h>
    using namespace std;
    
    void reverseinkgroup(queue<int>&q, int k, int count)
    {
        if(count>=k)
        {
            stack<int>s;
            for(int i=0; i<k; i++)
            //fetch k elements from queue,insert in stack
            {
                int ele=q.front();
                q.pop();

                s.push(ele);
            }

            //fetch k elements from stack,insert in queue
            for(int i=0; i<k; i++)
            {
                int ele=s.top();
                s.pop();

                q.push(ele);
            }

            //1 case maine sambhal liya hai 
            //baaki recursion sambhal lega
            reverseinkgroup(q, k, count-k);
        }

        else
        {
            for(int i=0; i<count; i++)
            {
                int ele=q.front();
                q.pop();
                q.push(ele);
            }
        }

    }

    int main()
    {
        queue<int>q;
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
        q.push(50);
        q.push(60);
        q.push(70);
        q.push(80);
        q.push(90);
        q.push(100);
        q.push(110);
        
        int k=3;
        //size will track the no of elements to be reversed
        int count=q.size();

        reverseinkgroup(q, k, count);

        while(!q.empty())
        {
            cout << q.front() << endl;
            q.pop();
        }
        return 0;
    } 