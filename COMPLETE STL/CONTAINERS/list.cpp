    //doubly linked list allows faster insertion and removal no random access
    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //creation
        list<int> mylist;
        
        //insertion and deletion
        mylist.push_back(10);//10
        mylist.push_back(20);//10->20
        mylist.push_back(30);//10->20->30

        mylist.push_front(100);//100->10->20->30

        mylist.pop_back();//100->10->20

        mylist.pop_front();//10->20

        mylist.push_back(100);//10->20->100
        
        //size
        cout << "size is:" << mylist.size() << endl;

        //clear
        //mylist.clear();
        cout << mylist.size() << endl;

        if(mylist.empty()==true)
        {
            cout << "list is empty" << endl;
        }
        else
        {
            cout << "list is not empty" << endl;
        }

        
        cout << "front element:" << mylist.front() << endl;
        cout << "front element:" << mylist.back() << endl;

        //iterator ->before removing
        list <int>:: iterator it=mylist.begin();
        while(it!=mylist.end())
        {
            cout << *(it) << " ";
            it++;
        }
        cout << endl;
        //remove
        mylist.remove(100);//remove(element)

        //iterator ->after removing
        list <int>:: iterator it2=mylist.begin();
        while(it2!=mylist.end())
        {
            cout << *(it2) << " ";
            it2++;
        }
        cout << endl;

        //swap
        list<int> l1;
        l1.push_back(10);
        l1.push_back(20);
        l1.push_back(30);

        list<int> l2;
        l2.push_back(100);
        l2.push_back(200);
        l2.push_back(300);

        l1.swap(l2);

        list <int>:: iterator it3=l1.begin();
        while(it3!=l1.end())
        {
            cout << *(it3) << " ";
            it3++;
        }
        cout << endl;

        l1.insert(l1.begin(),420);

        list <int>:: iterator it4=l1.begin();
        while(it4!=l1.end())
        {
            cout << *(it4) << " ";
            it4++;
        }
        cout << endl;

        //erase
        auto it_erase_start = l1.begin();
        advance(it_erase_start, 2); // Move iterator to the 2nd position
        l1.erase(it_erase_start, l1.end()); // Erase from 2nd position to end
        cout << l1.size() << endl;
        
        return 0;
    }