    #include <bits/stdc++.h>
    using namespace std;

    bool checksorted(stack<int>&s, int element1)
    {
        //basecase
        if(s.empty())
        {
            //stack pura compare ho chuka hai matlab stack sorted hai
            return true;
        }

        int element2 = s.top();
        s.pop();
        if(element2 < element1)
        {
            //iska matlab aage check kar sakte hai
            bool aagekaans=checksorted(s, element2);
            s.push(element2);//to fill stack again after 10 is popped call will return
            return aagekaans;
        }

        else
        {
            //sorted nahi hai
            return false;
        }
    }
    
    int main()
    {
        stack<int>s;
        s.push(10);
        s.push(20);
        s.push(30);
        s.push(40);
        s.push(50);
        int element1=INT_MAX;
        cout << checksorted(s, element1) << endl;
        return 0;
    } 