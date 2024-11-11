    string ordercopy;  // A global string to store the order string.

    class Solution 
    {
    public:
        // Custom comparison function used by the sort algorithm.
        static bool cmp(char a, char b)
        {
            // Logic:
            // The function checks the positions of characters `a` and `b` in the `ordercopy` string.
            // If `a` appears before `b` in `ordercopy`, the function returns true (indicating that `a` should come before `b` in the sorted string).
            // If `b` appears before `a`, the function returns false.

            // find() returns the index of the first occurrence of the character in the string.
            return (ordercopy.find(a) < ordercopy.find(b));
        }

        string customSortString(string order, string s) 
        {
            ordercopy = order;  // Store the order string in the global variable `ordercopy`.
            sort(s.begin(), s.end(), cmp);  // Sort the string `s` using the custom comparison function `cmp`.
            return s;  // Return the sorted string.
        }
    };
