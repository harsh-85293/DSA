class Solution


{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        int freshOranges = 0;

        // Step 1: all the rotten oranges to the queue
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    freshOranges++;
            }
        }

        if (!freshOranges)
            return 0;

        int minutes = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Step 2: Perform BFS
        while (!q.empty())
        {
            int size = q.size();
            bool hasRottenNew = false;

            // processing current level / T / minute
            for (int i = 0; i < size; i++)
            {
                auto curr = q.front();
                q.pop();

                for (auto dir : directions)
                {
                    int newRow = curr.first + dir.first;
                    int newCol = curr.second + dir.second;

                    // if adj cell is a fresh Orange, rot it.
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1)
                    {
                        grid[newRow][newCol] = 2;
                        freshOranges--;
                        q.push({newRow, newCol}); // for next level
                        hasRottenNew = true;
                    }
                }
            }

            if (hasRottenNew)
                minutes++;
        }

        // Step 3: checking
        if (freshOranges > 0)
            return -1;
        return minutes;
    }
};


// 2nd

class Solution {
    public:
        int orangesRotting(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
    
            queue<pair<pair<int, int>, int>> q;
            vector<vector<int>> vis(n, vector<int>(m, 0));
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 2) {
                        q.push({{i, j}, 0});
                        vis[i][j] = 2;
                    }
                }
            }
    
            int time = 0;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
    
            while (!q.empty()) {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int t = q.front().second;
                q.pop();
                time = max(time, t);
    
                for (int i = 0; i < 4; i++) {
                    int nrow = r + drow[i];
                    int ncol = c + dcol[i];
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                        q.push({{nrow, ncol}, t + 1});
                        vis[nrow][ncol] = 2;
                    }
                }
            }
    
            for (int i = 0; i < n; i++) {
                for (int k = 0; k < m; k++) {
                    if (grid[i][k] == 1 && vis[i][k] != 2) {
                        return -1;
                    }
                }
            }
    
            return time;
        }
    };
    