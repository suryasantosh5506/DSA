class Solution {
public:
    int countHomogenous(string s) {
        const int mod=1e9+7;
        int n=s.size();
        vector<int>stringsending(n,1);
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]) stringsending[i]=(stringsending[i]+stringsending[i-1])%mod;
        }
        int ans=0;
        for(int &x:stringsending) ans=(ans+x)%mod;
        return ans;
    }
};