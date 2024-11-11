class Solution {
public:
    int converttomin(string time)
    {
        //Direct Parsing: The hours and minutes are extracted using substr() and converted using stoi()
        int hr=stoi(time.substr(0,2));//substr(index,length)
        int min=stoi(time.substr(3,2));
        return (60*hr)+(min);
    }
    int findMinDifference(vector<string>& timePoints) 
    {
        vector<int> mins;
        for(auto time:timePoints)
        {
            mins.push_back(converttomin(time));
        }

        sort(mins.begin(),mins.end());

        int ans=INT_MAX;

        for(int i=0;i<mins.size()-1;i++)
        {
            ans=min(ans , mins[i+1]-mins[i] );
        }

        int lastdifference=mins[0]+1440-mins[mins.size()-1];
        ans=min(ans,lastdifference);
        return ans;
    }
};