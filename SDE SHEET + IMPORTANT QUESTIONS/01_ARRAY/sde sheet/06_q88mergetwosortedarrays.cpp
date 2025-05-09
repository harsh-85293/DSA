//brute approach
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            vector<int>temp;
            int i = 0;
            int j = 0;
    
            while(i < m && j < n){
                if(nums1[i] <= nums2[j]){
                    temp.push_back(nums1[i]);
                    i++;
                }
                else{
                    temp.push_back(nums2[j]);
                    j++;
                }
            }
    
            while(i < m){
                temp.push_back(nums1[i]);
                i++;
            }
    
            while(j < n){
                temp.push_back(nums2[j]);
                j++;
            }
    
            nums1 = temp;
        }
    };

//optimal approach
//without zeroes:
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;
            int j = 0;
    
            while(i >= 0 && j < n){
                if(nums1[i] > nums2[j]){
                    swap(nums1[i], nums2[j]);
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
    
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin, nums2.end());
        }
    };

