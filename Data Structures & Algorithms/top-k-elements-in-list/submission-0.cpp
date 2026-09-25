class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(int i=0;i<n;i++)
        m[nums[i]]++;
        priority_queue<pair<int,int>>q;
        for(auto it=m.begin();it!=m.end();it++)
        {
            q.push({it->second,it->first});
        }
        vector<int>v;
        while(!q.empty() && k>0)
        {
            int p=q.top().second;
            q.pop();
            v.push_back(p);
            k--;
        }
        return v;
    }
};
