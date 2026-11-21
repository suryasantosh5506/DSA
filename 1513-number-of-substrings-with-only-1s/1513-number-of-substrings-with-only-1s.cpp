class Solution {
public:
    int numSub(string s) {
        int n=s.size();
        const int mod=1e9+7;
        vector<int>stringending(n,0);
        if(s[0]=='0') stringending[0]=0;
        else stringending[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                stringending[i]=(stringending[i-1]+1)%mod;
            }
        }
        int ans=0;
        for(int &x:stringending) ans=(ans+x)%mod;
        return ans;
    }
};