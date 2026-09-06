class Solution {
public:

    int n,k;
    vector<vector<vector<int>>>dp;

    int solution(int i,int op1,int op2,vector<int>&nums){
        if(i==n) return 0;
        if(dp[i][op1][op2]!=-1) return dp[i][op1][op2];

        int ans=1e8;
        ans=min(ans,nums[i]+solution(i+1,op1,op2,nums));
        if(op1>0){
            ans=min(ans,(int)ceil(nums[i]/2.0)+solution(i+1,op1-1,op2,nums));
        }
        if(op2>0 && nums[i]>=k){
            ans=min(ans,nums[i]-k+solution(i+1,op1,op2-1,nums));
        }

        if(op1>0 && op2>0){
            int x=ceil(nums[i]/2.0);
            if(x>=k){
                x-=k;
                ans=min(ans,x+solution(i+1,op1-1,op2-1,nums));
            }

            if(nums[i]>=k){
                x=nums[i]-k;
                x=ceil(x/2.0);
                ans=min(ans,x+solution(i+1,op1-1,op2-1,nums));
            }
        }
        return dp[i][op1][op2]=ans;
    }

    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        n=nums.size();
        this->k=k;
        dp.assign(n,vector<vector<int>>(op1+1,vector<int>(op2+1,-1)));
        return solution(0,op1,op2,nums);
    }
};