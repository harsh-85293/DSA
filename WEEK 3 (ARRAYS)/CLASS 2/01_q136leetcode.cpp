    //LEETCODE Q136 SINGLE NUMBER
    #include <iostream>
    using namespace std;
    int find_unique_element(int arr[],int n)
    {
        int a=0;
        for(int i=0;i<n;i++)
        {
            a=(a^arr[i]);
        }
        return a;
    }
    int main()
    {
        int a=2;
        cout << (1 ^ 1 ^ 3) <<endl;//LOGIC IT WILL RETURN
        cout << (a^0);//return a
        cout << endl;

        int arr[]={1,2,1,2,3};
        int n=sizeof(arr)/sizeof(arr[0]);
        int x=find_unique_element(arr,n);
        cout << x << " is the unique element";
        return 0;
    }

//     The number you're referring to is 0.

// For any number a:

// nginx
// Copy
// Edit
// a ^ 0 = a
// So, 0 is the number which, when XORed with another number, leaves it unchanged.







// You said:
// and what anbout 1


// ChatGPT said:
// If you XOR any number with 1, it flips the least significant bit (LSB) of that number.

// For example:

// a ^ 1 changes the last bit of a:

// If a is even (LSB is 0), a ^ 1 makes it odd.

// If a is odd (LSB is 1), a ^ 1 makes it even.

// So XOR with 1 does not leave the number unchanged — it toggles the last bit.