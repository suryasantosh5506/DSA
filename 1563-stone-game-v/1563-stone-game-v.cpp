class Solution {
public:

    int n;
    vector<vector<int>>dp;

    int solution(int i,int j,vector<int>&arr){
        if(i>j) return 0;
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int totalsum=accumulate(arr.begin()+i,arr.begin()+j+1,0);
        int leftsum=0;
        int ans=INT_MIN;

        for(int k=i;k<=j;k++){
            leftsum+=arr[k];
            int rightsum=totalsum-leftsum;
            if(rightsum==leftsum){
                ans=max(ans,leftsum+solution(i,k,arr));
                ans=max(ans,rightsum+solution(k+1,j,arr));
            }else if(leftsum<rightsum) ans=max(ans,leftsum+solution(i,k,arr));
            else ans=max(ans,rightsum+solution(k+1,j,arr));
        }

        return dp[i][j]=ans;
    }

    int stoneGameV(vector<int>& stoneValue) {
        n=stoneValue.size();
        dp.assign(n,vector<int>(n,-1));
        return solution(0,n-1,stoneValue);
    }
};