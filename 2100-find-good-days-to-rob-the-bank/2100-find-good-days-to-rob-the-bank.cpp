class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>pre(n,0),suff(n,0);
        for(int i=1;i<n;i++) if(security[i]<=security[i-1]) pre[i]=pre[i-1]+1;
        for(int i=n-2;i>=0;i--) if(security[i]<=security[i+1]) suff[i]=suff[i+1]+1;
        vector<int>ans;
        for(int i=time;i<n-time;i++) if(pre[i]>=time && suff[i]>=time) ans.emplace_back(i);
        return ans;
    }
};