    #include <iostream>
    using namespace std;
    int main()
    {
        int n;
        cout << "enter n:";
        cin >> n;

        int flag=0;//assume no is prime

        for(int i=2;i<n;i++)
        {
            if((n%i)==0)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            cout << "number is prime." << endl;
        }
        else
        {
            cout << "number is not prime"<< endl;
        }
        return 0;
    }