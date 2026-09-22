class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        int m=tasks.size();
        if(n==0)
        return m;
        for(int i=0;i<m;i++)
        freq[tasks[i]-'A']++;
        int a=freq[0];
        int i=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]>a)
            a=freq[i];
        }
        int b=0;
        int q=0;
        for(int i=0;i<26;i++)
        {
            if(freq[i]==a)
            b++;
            if(freq[i]>0)
            q++;
        }
        int j=max(0,n-(q-1));
        int ans=(a-1)*(n+1);
        ans+=b;
        cout<<q<<" "<<j<<" "<<a<<" "<<b<<endl;
        return max(m,ans);
    }
};
