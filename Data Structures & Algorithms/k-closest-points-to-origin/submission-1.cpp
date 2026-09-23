class Solution {
public:
    long long power(int a,int b)
    {
        if(b<=0)
        return 1;
        long long x=power(a,b/2);
        if(b%2==0)
        return x*x;
        else
        return a*x*x;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long,int>>q;
        int n=points.size();
        for(int i=0;i<k;i++)
        {
            long long d=(power(points[i][0],2)+power(points[i][1],2));
            q.push({d,i});
        }
        for(int i=k;i<n;i++)
        {
            long long d=(power(points[i][0],2)+power(points[i][1],2));
            if(d<q.top().first)
            {
                q.pop();
                q.push({d,i});
            }
        }
        vector<vector<int>>v;
        while(!q.empty())
        {
            int i=q.top().second;
            q.pop();
            v.push_back({points[i][0],points[i][1]});
        }
        return v;
    }
};
