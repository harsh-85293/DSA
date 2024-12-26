   #include <bits/stdc++.h>
   using namespace std;

   int main()
   {
        //max heap
        //creation
        priority_queue<int> pq;
        //by default -> max heap

        //insertion
        pq.push(10);
        pq.push(5);
        pq.push(30);
        pq.push(15);
        
        //access front element
        cout << pq.top() << endl;

        //removal
        pq.pop();
        cout << pq.top() << endl;

        if(!pq.empty()){
            cout << "pq is not empty" << endl;
        }
        return 0;
   }
