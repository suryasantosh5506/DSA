class Solution {
public:

    int n,m;
    vector<vector<int>>dp;

    bool solution(int i,int j,string &s,string &p){
        if(i==n && j==m) return true;
        if(i==n){
            while(j<m){
                if(j+1>=m || p[j+1]!='*') return false;
                j+=2;
            }
            return true;
        }
        if(j==m) return false;
        if(dp[i][j]!=-1) return dp[i][j];

        if(j+1<m && p[j+1]=='*'){
            int ans=solution(i,j+2,s,p);
            if(s[i]==p[j] || p[j]=='.') ans|=solution(i+1,j,s,p);
            return dp[i][j]=ans;
        }
        if(s[i]==p[j] || p[j]=='.') return dp[i][j]=solution(i+1,j+1,s,p);
        return dp[i][j]=false;
    }

    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();
        dp.assign(n,vector<int>(m,-1));
        return solution(0,0,s,p);
    }
};