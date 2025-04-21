class Solution {
    public:
        vector<int>generaterow(int n){
            vector<int>ansrow;
            long long ans = 1;
            ansrow.push_back(1);
    
            for(int col = 1; col < n; col++){
                ans = ans * (n - col);
                ans = ans/col;
                ansrow.push_back(ans);
            }
            return ansrow;
        }        
    
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>>ans;
            for(int i = 1; i <= numRows; i++){
                ans.push_back(generaterow(i));
            }
            return ans;
        }
    };