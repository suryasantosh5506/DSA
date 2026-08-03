class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solution(int i,int turn,vector<int>&arr){
        if(i==n) return 0;
        if(dp[i][turn]!=-1) return dp[i][turn];

        int ans=(turn==0)?INT_MIN:INT_MAX;
        int sum=0;
        for(int j=i;j<min(i+3,n);j++){
            sum+=arr[j];
            if(turn==0){
                ans=max(ans,sum+solution(j+1,1,arr));
            }else{
                ans=min(ans,-sum+solution(j+1,0,arr));
            }
        }
        return dp[i][turn]=ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.assign(n,vector<int>(2,-1));
        int ans=solution(0,0,stoneValue);
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        else return "Tie";
    }
};