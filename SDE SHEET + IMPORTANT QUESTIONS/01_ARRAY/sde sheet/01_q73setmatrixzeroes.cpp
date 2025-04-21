//brute approach
class Solution {
    public:
        void markrow(int i, vector<vector<int>>& matrix){
            int m = matrix[0].size();
            for(int y = 0; y < m; y++){
                if(matrix[i][y] != 0){
                    matrix[i][y] = 121787;
                }
            }
        }
    
        void markcol(int j, vector<vector<int>>& matrix){
            int n = matrix.size();
            for(int x = 0; x < n; x++){
                if(matrix[x][j] != 0){
                    matrix[x][j] = 121787;
                }
            }
        }
    
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(matrix[i][j] == 0){
                        markrow(i, matrix);
                        markcol(j, matrix);
                    }
                }
            }
    
            // Replace -1 with 0
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(matrix[i][j] == 121787){
                        matrix[i][j] = 0;
                    }
                }
            }
    
        }
    };

//better approach
//better approach
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            vector<int>rows(n, 0);
            vector<int>cols(m, 0);
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(matrix[i][j] == 0){
                        rows[i] = 1;
                        cols[j] = 1;
                    }
                }
            }
    
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(rows[i] == 1 || cols[j] == 1){
                        matrix[i][j] = 0;
                    }
                }
            }
            
        }
    };
    //optimal approach
    //optimal approach
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
           int col0 = 1;
            // step 1: Traverse the matrix and
            // mark 1st row & col accordingly:
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        // mark i-th row:
                        matrix[i][0] = 0;
    
                        // mark j-th column:
                        if (j != 0)
                            matrix[0][j] = 0;
                        else
                            col0 = 0;
                    }
                }
            }
    
            // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
            for (int i = 1; i < n; i++) {
                for (int j = 1; j < m; j++) {
                    if (matrix[i][j] != 0) {
                        // check for col & row:
                        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                            matrix[i][j] = 0;
                        }
                    }
                }
            }
    
            //step 3: Finally mark the 1st col & then 1st row:
            if (matrix[0][0] == 0) {
                for (int j = 0; j < m; j++) {
                    matrix[0][j] = 0;
                }
            }
            if (col0 == 0) {
                for (int i = 0; i < n; i++) {
                    matrix[i][0] = 0;
                }
            }
    
        }
    };