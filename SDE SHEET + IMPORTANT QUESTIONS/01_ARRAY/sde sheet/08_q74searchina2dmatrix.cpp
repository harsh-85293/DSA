
//brute
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            bool ans = false;
            for(int i = 0; i < matrix.size(); i++){
                for(int j = 0; j < matrix[0].size(); j++){
                    if(matrix[i][j] == target){
                        ans = true;
                    }
                }
            }
            return ans;
        }
    };

//optimal
//binary search
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int n = rows*cols;
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s)/2;

        while(s <= e)
        {
            int rowindex = mid/cols;
            int colindex = mid%cols;

            if(matrix[rowindex][colindex] == target){
                return true;
            }

            else if(target < matrix[rowindex][colindex]){
                e = mid - 1;
            }

            else if(target > matrix[rowindex][colindex]){ 
                s =mid + 1;
            }
            mid = s + (e - s) / 2;
        }
        return false;
    }
};