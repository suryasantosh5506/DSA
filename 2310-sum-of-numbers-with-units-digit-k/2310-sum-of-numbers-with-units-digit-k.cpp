class Solution {
public:

    vector<int>dp;

    int solution(int num,int k){
        if(num==0) return 0;
        if(num<0) return 1e8;
        if(dp[num]!=-1) return dp[num];

        int ans=1e8;
        for(int i=1;i<=num;i++){
            if(i%10==k){
                ans=min(ans,1+solution(num-i,k));
            }
        }

        return dp[num]=ans;
    }

    int minimumNumbers(int num, int k) {
        dp.assign(num+1,-1);
        int ans=solution(num,k);
        if(ans>=1e8) return -1;
        return ans;
    }
};