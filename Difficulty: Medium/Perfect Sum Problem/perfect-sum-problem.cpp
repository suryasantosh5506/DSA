class Solution {
  public:
  
  vector<vector<int>>dp;
  
    int solution(int i,vector<int>& arr, int target){
        if (i == arr.size()) {
            return (target==0) ? 1 : 0;
        }

        if(target<0) return 0;
        if(dp[i][target]!=-1) return dp[i][target];
        
        int cnt=0;
        
        cnt+=solution(i+1,arr,target-arr[i]);
        cnt+=solution(i+1,arr,target);
        
        return dp[i][target]=cnt;
    }
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        dp.assign(n,vector<int>(target+1,-1));
        return solution(0,arr,target);
    }
};