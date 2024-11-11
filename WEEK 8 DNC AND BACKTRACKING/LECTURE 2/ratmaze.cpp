#include <bits/stdc++.h>
bool issafe(int newx, int newy, vector<vector<int>> &arr, vector<vector<bool>> &visited, int n) {
    // Check if the cell is within boundaries
    if (newx < 0 || newy < 0 || newx >= n || newy >= n) {
        return false;
    }
    // Check if the cell is already visited or blocked (arr[newx][newy] == 0)
    if (visited[newx][newy] || arr[newx][newy] == 0) {
        return false; 
    }
    return true;  // The cell is safe to visit
}

void solve(vector<vector<int>> &arr, vector<vector<bool>> &visited, int n, vector<string> &ans, int srcx, int srcy, int destx, int desty, string output) {
    // Base case: If the rat has reached the destination
    if (srcx == destx && srcy == desty) {
        ans.push_back(output);
        return;
    }

    // Explore all possible directions: Up, Down, Left, Right
    
    // Down direction (i+1, j)
    int newx = srcx + 1;
    int newy = srcy;
    if (issafe(newx, newy, arr, visited, n)) {
        visited[newx][newy] = true;
        solve(arr, visited, n, ans, newx, newy, destx, desty, output + "D");
        visited[newx][newy] = false;  // Backtracking
    }
    
    // Left direction (i, j-1)
    newx = srcx;
    newy = srcy - 1;
    if (issafe(newx, newy, arr, visited, n)) {
        visited[newx][newy] = true;
        solve(arr, visited, n, ans, newx, newy, destx, desty, output + "L");
        visited[newx][newy] = false;  // Backtracking
    }

    // Right direction (i, j+1)
    newx = srcx;
    newy = srcy + 1;
    if (issafe(newx, newy, arr, visited, n)) {
        visited[newx][newy] = true;
        solve(arr, visited, n, ans, newx, newy, destx, desty, output + "R");
        visited[newx][newy] = false;  // Backtracking
    }
    

    // Up direction (i-1, j)
    newx = srcx - 1;
    newy = srcy;
    if (issafe(newx, newy, arr, visited, n)) {
        visited[newx][newy] = true;
        solve(arr, visited, n, ans, newx, newy, destx, desty, output + "U");
        visited[newx][newy] = false;  // Backtracking
    }

    

    
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
     vector<string> ans;
    vector<vector<bool>>visited(n,vector<bool>(n,0));
    int srcx=0;
    int srcy=0;
    visited[0][0]=true;
    int destx=n-1;
    int desty=n-1;
    string output="";

    //important case
    if(arr[0][0]==0)
    {
        return ans;
    }

    solve(arr,visited,n,ans,srcx,srcy,destx,desty,output);

    return ans;
}