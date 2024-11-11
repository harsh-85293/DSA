 // Loop to get all substrings
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j <= n; j++) 
        {
            ans.push_back(str.substr(i, j - i)); // Fix: j - i gives the correct length
        }
    }