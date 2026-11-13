class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(str1[i]==str2[j]) dp[i][j]=1+dp[i+1][j+1];
                else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        int len=n+m-dp[0][0];
        string ans(len,'#');
        int i=0,j=0;
        int ind=0;
        while(i<n && j<m){
            if(str1[i]==str2[j]){
                ans[ind++]=str1[i];
                i++;
                j++;
            }else if(dp[i+1][j]>dp[i][j+1]){
                ans[ind++]=str1[i++];
            }else{
                ans[ind++]=str2[j++];
            }
        }
        while(i<n) ans[ind++]=str1[i++];
        while(j<m) ans[ind++]=str2[j++];
        cout << ans << endl;
        return ans;
    }
};