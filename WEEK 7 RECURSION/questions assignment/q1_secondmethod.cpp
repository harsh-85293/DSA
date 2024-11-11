#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcddefg";
    char p = 'e';

    // Convert std::string to C-style string using c_str()
    char* ptr = strrchr(s.c_str(), p);

    // Check if the character is found
    if (ptr != nullptr) 
    {
        int index = ptr - s.c_str(); // Calculate the index
        cout << "Last occurrence of '" << p << "' found at index: " << index << endl;
    } 

    else 
    {
        cout << "Character '" << p << "' not found" << endl;
    }

    return 0;
}
