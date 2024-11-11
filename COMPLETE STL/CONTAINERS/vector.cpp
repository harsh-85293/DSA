    #include <bits/stdc++.h>
    //#include <vector>
    using namespace std;
    int main()
    {
        //creation
        vector<int> marks;
        vector<int> miles(10);//10 sized vector
        vector<int> distances(10,0);//10 sized vector initialized with 0 value

        //begin()->address of starting block
        vector<int> v={1,2,3,4,5,6,7,8,9};
        cout << *(v.begin()) << endl;
      
        miles.push_back(10);
        miles.push_back(20);
        miles.push_back(30);
        miles.push_back(40);

        //size()
        cout << "size of mles vector:" << miles.size();
        
        miles.pop_back();//40 will be removed
        cout << "size of mles vector now:" << miles.size();

        //front and back
        cout << miles.front() << endl;//first element 10
        cout << miles.back() << endl;//rightmost element or last element inserted

        //empty or not
       
        miles[1]=100;//can be accessed through indices and also can be updated

        // size and capacity=double the size when vector is full
        cout << "size:" << miles.size() << endl;
        cout <<  "capacity:" <<miles.capacity() << endl;
        cout << "maximum size:" << miles.max_size() << endl;//depend on system

        //vector can be accessed as array
        vector<int>g(10);
        g[0]=12;//it can only be defined if size of g is defined
        cout << g[0] << endl;
        cout << g.at(0) << endl;

        //clear
        g.clear();
        cout  << "size is 0 as we cleared the vector"<< g.size() << endl;

        //insert->insert(iterator,value)
        vector <int> newvector={10,20,30,40,50};
        newvector.insert(newvector.begin(),50);
        cout << "first element of newvector:" << newvector[0] << endl;

        //erase->erase(iterator position)  or erase(iterator first,iterator last)
        newvector.erase(newvector.begin()+2,newvector.end());
        cout << newvector.size() << endl;//only 10 and 20 are left

        //swap
        vector<int> first;
        first.push_back(100);
        first.push_back(200);
        first.push_back(300);
        first.push_back(400);
        first.push_back(500);

        vector<int> second;
        second.push_back(10);
        second.push_back(20);
        second.push_back(30);
        second.push_back(40);
        second.push_back(50);
        first.swap(second);//first is swapped with second

        //iterate vector through for each loop

        for(int i:first)//for each integer in vector first
        {
            cout << i << " " ;
        }
        cout << endl; 
        
        for(int i:second)//for each integer in vector first
        {
            cout << i << " " ;
        }
        cout << endl; 

        //traversal through iterator
        vector<int>::iterator it=first.begin();
        while(it!=first.end())
        {
            cout << *(it) << " ";
            it++;
        }
        return 0;
    }