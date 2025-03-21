//hard question
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> answer(cars.size(), -1);//collisiion time of ith car with the next car
        stack<int>st;
        for(int i=cars.size()-1; i>=0; i--)
        {
            //check if car ahead of current car is faster?
            while(!st.empty() && cars[st.top()][1] >= cars[i][1])
            {
                st.pop();
            }
            while(!st.empty())
            {
                double coltime = (double)( cars[st.top()][0] - cars[i][0] ) / (cars[i][1] -cars[st.top()][1]);
                if(answer[st.top()] == -1 || coltime <= answer[st.top()])
                {
                    answer[i] = coltime;
                    break;
                } 
                st.pop();
            }
            st.push(i);
        }
        return answer;
    }
};