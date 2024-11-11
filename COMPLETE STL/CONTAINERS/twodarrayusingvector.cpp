    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {   
    //  outer   inner      name=v
        vector<vector<int>> v(4,vector<int>(4,0));//v(no of rows,har ek row me kya hona chahiye)
        
        //2d array created with 5 rows and 4 columns with intital valus as 0
        vector<vector<int>> arr(5,vector<int>(4,0));
        int totalrows=arr.size();//bahar wale vector ka size
        int totalcolumns=arr[0].size();//andar wale vector me se pehle wale ka size nikal lo kyuki kya pata aur kitne honge

        vector<vector<int>> a(4);//if columns are unknown
        a[0]=vector<int>(4);
        a[1]=vector<int>(2);
        a[2]=vector<int>(3);
        a[3]=vector<int>(5);
        
        int totalrow=a.size();
        //int totalcols=a[i].size();

        
        return 0;
    }