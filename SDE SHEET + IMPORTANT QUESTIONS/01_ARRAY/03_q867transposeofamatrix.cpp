class Solution {
    public:
        vector<vector<int>> transpose(vector<vector<int>>& matrix) {
            int rs = matrix.size();
            int cs = matrix[0].size();
            vector<vector<int>>res(cs, vector<int>(rs, 0));
    
            for(int i = 0; i < rs; i++){
                for(int j = 0; j < cs; j++){
                    res[j][i] = matrix[i][j];
                }
            }
            return res;
        }
    };