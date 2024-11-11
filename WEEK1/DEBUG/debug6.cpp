#include<iostream>
using namespace std;

int main() {
    int i, j, n;
    cin >> n;
    for (i = 0; i < n; i++) {  // Changed to start from 0 to simplify the logic
        char p = 'E' - i;      // Initialize p to the correct starting character for each row
        for (j = 0; j <= i; j++) {
            cout << p;
            p++;
        }
        cout << endl;
    }
    return 0;
}
