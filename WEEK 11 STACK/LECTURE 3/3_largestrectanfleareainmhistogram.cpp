//leetcode q84
class Solution {
public:
    void nextSmallerElement(vector<int>& arr, vector<int>& nextAns) {
        stack<int> st;
        int n = arr.size();
        nextAns.resize(n);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nextAns[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void prevSmallerElement(vector<int>& arr, vector<int>& prevAns) {
        stack<int> st;
        int n = arr.size();
        prevAns.resize(n);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            prevAns[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextAns;
        vector<int> prevAns;
        
        // Fill next smaller and previous smaller arrays
        nextSmallerElement(heights, nextAns);
        prevSmallerElement(heights, prevAns);

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            int width = nextAns[i] - prevAns[i] - 1;
            int height = heights[i];
            int currArea = width * height;
            maxArea = max(maxArea, currArea);
        }
        
        return maxArea;
    }
};