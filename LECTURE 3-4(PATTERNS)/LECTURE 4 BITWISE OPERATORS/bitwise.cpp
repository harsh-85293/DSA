#include <iostream>
using namespace std;

int main()
{
    cout << (2&3) <<endl;
    cout << (5&7) <<endl;
    
    cout << (2|4) <<endl;
    cout << (3|6) << endl;
    
    int a=2;
    cout << (~(a)) <<endl;

    int c=5,d=7;
    cout << (c^d) << endl;
    
    return 0;
}