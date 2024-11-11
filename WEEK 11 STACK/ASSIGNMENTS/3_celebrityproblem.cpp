//optimal important approach pro
class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int>st;
        int n = mat.size();
        //step 1:push all person into stack
        for(int i=0; i<n; i++)
        {
            st.push(i);
        }
        
        //step2: run discard  method to get might be celebrity
        while(st.size() != 1)
        {
            int a = st.top();
            st.pop();
            int b =  st.top();
            st.pop();
            
            //if a knows b 
            if(mat[a][b])
            {
                //a is not celebrity , b might be
                st.push(b);
            }
            else
            {
                //b is not celebrity , a might be
                st.push(a);
            }
        }
        
        //step 3:check that single person is actually celebrity'
        int mightbecelebrity = st.top();
        st.pop();
        
        //cel should not know anyone
        for(int i=0; i<n; i++)
        {
            if(mat[mightbecelebrity][i] !=0)
            {
                return -1;
            }
        }
        
        //everyone should know celebrity
        for(int i=0; i<n; i++)
        {
            if(mat[i][mightbecelebrity] ==0 && i != mightbecelebrity)
            {
                return -1;
            }
        }
        //mightbeceleberity is celebrity
        return mightbecelebrity;
    }
};
