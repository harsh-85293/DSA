    #include <bits/stdc++.h>
    using namespace std;
    class Solution 
    {
    public:
        unordered_map<int,bool>rowcheck;
        unordered_map<int,bool>lowerdiagonalcheck;
        unordered_map<int,bool>upperdiagonalcheck;

        //convert board to string
        void storesolution(vector<vector<string>>&ans,vector<vector<char>>&board,int n)
        {
            vector<string>temp;
            for(int i=0;i<n;i++)
            {
                string output="";
                for(int j=0;j<n;j++)
                {
                    output.push_back(board[i][j]); 
                }
                //transfer board to temp
                temp.push_back(output) ;
            }
            //string is ready
            ans.push_back(temp);
        }

        bool issafe(int row,int col,vector<vector<char>>&board)
        {
            //check row
            if(rowcheck[row]==true)
            {
                return false;
            }
            //check upperdiagonal
            if(upperdiagonalcheck[row-col]==true)
            {
                return false;
            }
            //check lowerdiagonal
            if(lowerdiagonalcheck[row+col]==true)
            {
                return false;
            }
            return true;
        }

      
        void solve(int n,vector<vector<char>>&board,vector<vector<string>>&ans,int col)
        {
            //base case
            if(col>=n)
            {
                //all queens are places
                //store arrangements in ans
                storesolution(ans,board,n);
                return;
            }
            //1 case hum solve karenge and baaki recursion
            //mere paas column ka index hai usme se konsi column pe place karna hai vo yaha decide karenge
            for(int row=0;row<n;row++)
            {
                if(issafe(row,col,board))
                {
                    board[row][col]='Q';
                    rowcheck[row]=true;
                    lowerdiagonalcheck[row+col]=true;//marks position occupied
                    upperdiagonalcheck[row-col]=true;//marks position occupied
                
                    solve(n,board,ans,col+1);

                    board[row][col]='.';
                    rowcheck[row]=false;
                    lowerdiagonalcheck[row+col]=false;//marks position occupied
                    upperdiagonalcheck[row-col]=false;//marks position occupied
                }
            }
        }

        vector<vector<string>> solveNQueens(int n) 
        {
            vector<vector<string>>ans;
            //board
            vector<vector<char>>board(n,vector<char>(n,'.'));
            int col=0;
            solve(n,board,ans,col);
            return ans;
        }
    };