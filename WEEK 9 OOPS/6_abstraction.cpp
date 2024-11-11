    #include <bits/stdc++.h>
    using namespace std;

    class abstractionexample
    {
        private:
            int num;
            char ch;
        
        public :
            void setvalues(int n,char c)
            {
                num=n;
                ch=c;               
            }

            void getvalues()
            {
                cout << "No:" << num << endl;
                cout << "Character is:" << ch << endl;
            }
    };

    int main()
    {
        abstractionexample a;
        //not accesible
        // cout << a.num;
        // cout << a.ch;
        //only way to set and get these values
        a.setvalues(5,'h');
        a.getvalues();
        return 0;
    } 