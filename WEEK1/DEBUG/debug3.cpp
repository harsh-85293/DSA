#include <iostream>
using namespace std;

int main() {
    int n = 5; // Number of rows in the pattern

    for (int row = 0; row < n; row++) 
    {
        // Print leading spaces
        for (int col = row; col < n+2; col++) 
        {
            cout << " ";
        }

        // Print stars
        for (int col = 0; col < (2 * row - 1); col++) 
        {
            cout << "*";
        }

        // Move to the next line
        cout << endl;
    }

    return 0;
}
