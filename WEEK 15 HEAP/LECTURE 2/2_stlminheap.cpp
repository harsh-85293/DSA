   #include <bits/stdc++.h>
   using namespace std;
     
   int main()
   {
        //min heap creation
        priority_queue< int, vector<int>, greater<int> > pq;
        pq.push(10);
        pq.push(5);
        pq.push(30);
        pq.push(20);

        cout << pq.top() << endl;
        pq.pop();
        cout << pq.top() << endl;
        return 0;
   }
