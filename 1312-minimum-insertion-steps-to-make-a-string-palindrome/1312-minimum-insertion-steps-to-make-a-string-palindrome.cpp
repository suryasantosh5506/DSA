class Solution {
public:

    vector<vector<int>>dp;
    int n;

    int solution(int i,int j,string &s1,string &s2){
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]=1+solution(i+1,j+1,s1,s2);
        return dp[i][j]=max(solution(i+1,j,s1,s2),solution(i,j+1,s1,s2));
    }

    int minInsertions(string s) {
        n=s.size();
        string s1=s,s2=s;
        reverse(s2.begin(),s2.end());
        dp.assign(n,vector<int>(n,-1));
        return n-solution(0,0,s1,s2);
    }
};