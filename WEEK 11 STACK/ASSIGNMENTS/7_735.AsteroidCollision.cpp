class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto it:asteroids)
        {
            //initially nothing is destroyed
            bool destroy = false;

            if(it > 0)
            {
                st.push(it);
            }

            else
            {
                // -ve set
                if(st.empty() || (st.top() < 0 && it < 0) )
                {
                    st.push(it);
                }
                else
                {
                    //collisions
                    while(!st.empty() && st.top() > 0)
                    {
                        if(abs(it) == st.top())
                        {
                            destroy = true;
                            st.pop();
                            break;
                        }
                        else if(abs(it) > st.top())
                        {
                            st.pop();
                        }
                        else
                        {
                            destroy = true;
                            break;
                        }
                    }
                    if(!destroy)
                    {
                        st.push(it);
                    }
                }
            }
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};