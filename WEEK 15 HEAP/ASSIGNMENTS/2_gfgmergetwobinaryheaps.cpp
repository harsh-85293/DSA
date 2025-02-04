  #include <bits/stdc++.h>
  using namespace std;
  // just heapify in vector
  void heapify(vector<int>& arr, int n, int currIndex) {
      int largestIndex = currIndex;
      int left = 2 * currIndex + 1;
      int right = 2 * currIndex + 2;
      
      if (left < n && arr[left] > arr[largestIndex]) {
          largestIndex = left;
      }
      if (right < n && arr[right] > arr[largestIndex]) {
          largestIndex = right;
      }
      
      if (largestIndex != currIndex) {
          swap(arr[currIndex], arr[largestIndex]);
          heapify(arr, n, largestIndex);
      }
  }

  void buildheap(vector<int>& arr, int n) {
      // Loop from the last non-leaf node down to the root.
      for (int i = n / 2 - 1; i >= 0; i--) {
          heapify(arr, n, i);
      }
  }

  vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
      vector<int> arr(a.begin(), a.end());
      arr.insert(arr.end(), b.begin(), b.end());
      int g = arr.size();
      buildheap(arr, g);
      
      return arr;
  }

  int main() {
      int n = 4;
      int m = 3;
      vector<int> a = {10, 5, 6, 2};
      vector<int> b = {12, 7, 9};
      
      vector<int> ans = mergeHeaps(a, b, n, m);
      
      for (auto it : ans) {
          cout << it << " ";
      }
      return 0;
  }
