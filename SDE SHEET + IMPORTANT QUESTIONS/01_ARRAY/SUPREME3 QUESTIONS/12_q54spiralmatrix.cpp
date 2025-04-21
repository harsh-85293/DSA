class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) 
        {
            vector<int> ans;
            int m=matrix.size();
            int n=matrix[0].size();
            int total_elements=(m*n);

            int starting_row=0;
            int ending_column=n-1;
            int ending_row=m-1;
            int starting_column=0;

            int count=0;
            while(count < total_elements)
            {
                for(int i=starting_column;i<=ending_column && count <total_elements;i++)
                {
                    ans.push_back(matrix[starting_row][i]);
                    count++;
                }
                starting_row++;

                for(int i=starting_row;i<=ending_row && count <total_elements ;i++)
                {
                    ans.push_back(matrix[i][ending_column]);
                    count++;
                }
                ending_column--;

                for(int i=ending_column;i>=starting_column && count <total_elements;i--)
                {
                    ans.push_back(matrix[ending_row][i]);
                    count++;
                }
                ending_row--;

                for(int i=ending_row;i>=starting_row && count <total_elements;i--)
                {
                    ans.push_back(matrix[i][starting_column]);
                    count++;
                }
                starting_column++;
            }
            return ans;
            
        }
    };