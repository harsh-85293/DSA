#include <bits/stdc++.h> 
using namespace std;

vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    // Convert vectors to sets to remove duplicates and allow for set operations
    set<int> a1(a.begin(), a.end());
    set<int> b1(b.begin(), b.end());
    set<int> c1(c.begin(), c.end());

    // Vector to store common elements
    vector<int> common_ab;

    // Find common elements between set a1 and b1
    set_intersection(a1.begin(), a1.end(), b1.begin(), b1.end(), back_inserter(common_ab));

    // Now find common elements between common_ab and c1
    vector<int> result;
    set_intersection(common_ab.begin(), common_ab.end(), c1.begin(), c1.end(), back_inserter(result));

    return result;
}

int main() {
    vector<int> a = {2, 3, 4, 7};
    vector<int> b = {0, 0, 3, 5};
    vector<int> c = {1, 3, 8, 9};

    vector<int> common = findCommonElements(a, b, c);

    for (int x : common) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
