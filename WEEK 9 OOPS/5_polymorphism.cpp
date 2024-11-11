    //compile type polymomorphism or static polymorphism
    //1)function overloading
    #include <bits/stdc++.h>
    using namespace std;

    class add
    {
        public:
            //x,y two integer addition
            int sum(int x,int y)
            {
                return x+y;
            }
            //x,y two differenrt datatype addition
            double sum(double x,double y)
            {
                return x+y;
            }
            //3 int x,y,z addition
            int sum(int x,int y,int z)
            {
                return x+y+z;
            }
    };

    int main()
    {
        int x=5;
        int y=10;
        int z=9;
        add A;
        cout << A.sum(x,y) << endl;
        cout << A.sum(x,y,z) << endl;
        cout << A.sum(5.5,6.6) << endl;
        return 0;
    } 