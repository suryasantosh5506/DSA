class Solution {
public:

    int lcs(string &s,string &t){
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s[i]==t[j]) dp[i][j]=(int)s[i]+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        int total=0;
        for(char &x:s) total+=x;
        for(char &x:t) total+=x;
        return total-2*dp[0][0];
    }

    int minimumDeleteSum(string s1, string s2) {
        return lcs(s1,s2);
    }
};