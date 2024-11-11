#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool issafe(vector<vector<char>>& board,char digit,int row,int col)
    {
        //row check
        int n=board.size();
        for(int k=0;k<n;k++)
        {
            if(board[row][k]==digit)
            {
                return false;
            }
        }
        //col check
        for(int k=0;k<n;k++)
        {
            if(board[k][col]==digit)
            {
                return false;
            }
        }
        //3x3 box check
         for(int k=0;k<n;k++)
        {
           if(board[3*(row/3)+(k/3)][3*(col/3)+(k%3)]==digit)
           {
            return false;
           }
        }

        return true;
    } 

    bool solve(vector<vector<char>>& board)
    {
        //entire logic
        //base case
        //1 case hum solve karenge 
        //baaki recursion sambhal lega
        //sabse pehle empty cell find karenge
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='.')
                {
                    for(char digit='1';digit<='9';digit++)  
                    {
                        
                        //konsa digit rakhna safe hai usse rakh do
                        if(issafe(board,digit,i,j)==true)
                        {
                            //agar safe hai to rakho
                            board[i][j]=digit;

                            bool aagekasolvehopaya=solve(board);
                            if(aagekasolvehopaya==true)
                            {
                                return true;
                            }
                            else
                            {
                                //backtrack karo
                                board[i][j]='.';
                            }
                        }
                    }
                    //agar yaha aa gaye to koi digit galati huyi hai peeche
                    return false;
                }
            }
        }  
        //board is completely filled
        return true;
    }


    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};