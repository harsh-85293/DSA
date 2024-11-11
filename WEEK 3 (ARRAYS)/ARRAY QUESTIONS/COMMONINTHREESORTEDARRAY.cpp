 vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            set<int>nums;
            vector <int> ans;
            //code here.
            int i=0;
            int j=0;
            int k=0;
            
            while(i<n1 && j<n2 && k<n3)
            {
                if(A[i]==B[j] && B[j]==C[k])
                {
                    nums.insert(A[i]);
                    i++;
                    j++;
                    k++;
                }
                
                else if (A[i]<B[j])
                {
                    i++;
                }
                
                else if(B[j]<C[k])
                {
                    j++;
                }
                
                else
                {
                    k++;
                }
            }
            
            for(auto i:nums)
            {
                ans.push_back(i);
            }
            
            return ans;
        }
