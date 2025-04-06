//Kahns algorithm
#include <bits/stdc++.h>
class Solution {
    public:
        bool toposort(unordered_map<int, list<int>>&adjList, int n){
            unordered_map<int, int>indegree;
            vector<int>topo;
    
            for(int i = 0; i < n; i++){
                indegree[i] = 0;
            }
    
            //now calculate indegree of each node
            for(auto i : adjList){
                int u = i.first; //this is a course that is a prerequisite for others
                for(auto j : i.second){
                    int v = j;  // course that depends on u
                    indegree[v]++; // so v has one more incoming edge
                }
            }
    
    
            //BFS LOGIC Kahn’s Algorithm
            queue<int>q;
            //initial state
            for(int i = 0; i < n; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
    
            while (!q.empty()) {
                // Get the front node (course with no remaining prerequisites)
                int front = q.front();
    
                // Add this course to the topological order
                topo.push_back(front);
    
                // Remove it from the queue
                q.pop();
    
                // Process all neighbors (courses that depend on 'front')
                for (auto nbr : adjList[front]) {
                    // One less prerequisite for this neighbor
                    indegree[nbr]--;
    
                    // If all prerequisites for 'nbr' are now done, add to queue
                    if (indegree[nbr] == 0) {
                        q.push(nbr);
                    }
                }
            }
    
    
            //valid or not valid
            if(topo.size() == n){
                return true;
            }
            return false;
        }
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            unordered_map<int, list<int>>adjList;
    
            for(auto i:prerequisites){
                int u = i[1]; // prerequisite course
                int v = i[0]; // course that depends on u
                adjList[u].push_back(v);
            }
            //graph is ready
    
            bool ans = toposort(adjList, numCourses);
            return ans;
        }
    };