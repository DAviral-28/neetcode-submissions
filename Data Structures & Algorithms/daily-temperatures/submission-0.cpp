class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<pair<int,int>>s;
        vector<int>v(n);
        v[n-1]=0;
        s.push({temperatures[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && temperatures[i]>=s.top().first)
            s.pop();
            if(s.empty())
            v[i]=0;
            else
            v[i]=s.top().second-i;
            s.push({temperatures[i],i});
        }
        return v;
    }
};
