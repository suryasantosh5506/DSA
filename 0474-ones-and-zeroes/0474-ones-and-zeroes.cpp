class Solution {
public:

    int size;
    vector<int>zeroes;
    vector<int>ones;
    vector<vector<vector<int>>>dp;

    int solution(int i,int m,int n){
        if(i==size) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];

        int ans=INT_MIN;
        if(m-zeroes[i] >=0 && n-ones[i]>=0){
            ans=max(ans,1+solution(i+1,m-zeroes[i],n-ones[i]));
        }
        ans=max(ans,solution(i+1,m,n));
        return dp[i][m][n]=ans;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        size=strs.size();
        dp.assign(size,
            vector<vector<int>>(m+1,
                vector<int>(n+1,-1)
            )
        );
        for(string str:strs){
            int cnt0=0,cnt1=0;
            for(char &ch:str){
                if(ch=='0') cnt0++;
                else cnt1++;
            }
            zeroes.emplace_back(cnt0);
            ones.emplace_back(cnt1);
        }
        return solution(0,m,n);
    }
};