class Solution {
public:

    int n,m;
    string s,t;
    vector<vector<int>>dp;

    int solution(int i,int j){
        if(j==m) return 1;
        if(i==n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(s[i]==t[j]){
            ans+=solution(i+1,j+1);
        }
        ans+=solution(i+1,j);
        return dp[i][j]=ans;
    }

    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        this->s=s;
        this->t=t;
        dp.assign(n,vector<int>(m,-1));
        return solution(0,0);
    }
};