#include <bits/stdc++.h> 

void harsh(string str, vector<string>& ans, string output, int index) {
    // Base case: when we've processed all characters in the string
    if (index == str.length()) 
	{
        if (!output.empty()) 
		{  // Add only non-empty subsequences
            ans.push_back(output);
        }
        return;
    }

    char ch = str[index];

    // Include the current character in the subsequence
    harsh(str, ans, output + ch, index + 1);

    // Exclude the current character from the subsequence
    harsh(str, ans, output, index + 1);
}

vector<string> subsequences(string str) {
    int index = 0;
    string output = "";
    vector<string> ans;
    harsh(str, ans, output, index);
    return ans;
}