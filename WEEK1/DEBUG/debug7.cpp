#include<iostream>
using namespace std;

int main() 
{
    int n = 3; // Middle line has 5 stars (2*n - 1)
    
    // Upper part including the middle line
    for (int i = 1; i <= n; ++i) 
    {
        // Print leading spaces
        for (int j = i; j < n; ++j) 
        {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= (2*i - 1); ++j) 
        {
            cout << "*";
        }
        cout << endl;
    }

    // Lower part
    for (int i = n-1; i >= 1; --i) 
    {
        // Print leading spaces
        for (int j = n; j > i; --j) 
        {
            cout << " ";
        }
        // Print stars
        for (int j = 1; j <= (2*i - 1); ++j) 
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
