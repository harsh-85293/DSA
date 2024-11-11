    #include <bits/stdc++.h>
    using namespace std;

    class Solution 
    {
    public:

        bool solve(vector<vector<char>>& B, string word, int row, int col, int i)
        {
            // Base case: If all characters in the word are matched
            if(i == word.size())
            {
                return true;
            }

            // Boundary and character match check
            if(row < 0 || col < 0 || row >= B.size() || col >= B[0].size() || B[row][col] != word[i] || B[row][col] == '%')
            {
                return false;
            }

            // Mark the current cell as visited
            char temp = B[row][col];
            B[row][col] = '%';

            // Recursively check all 4 directions (up, down, left, right)
            bool found = solve(B, word, row+1, col, i+1)    // Down
                    || solve(B, word, row-1, col, i+1)    // Up
                    || solve(B, word, row, col+1, i+1)    // Right
                    || solve(B, word, row, col-1, i+1);   // Left

            // Backtrack by resetting the current cell
            B[row][col] = temp;

            return found;
        } 

        bool exist(vector<vector<char>>& board, string word) 
        {
            for(int i = 0; i < board.size(); i++)
            {
                for(int j = 0; j < board[0].size(); j++)
                {
                    // Start backtracking from every cell
                    if(solve(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    };
    int main()
    {
        return 0;
    } 