class Solution {
public:

    int n;

    int solution(int i,vector<int>&nums){
        if(i==n) return 0;

        int prev=INT_MAX;
        int ans=0;
        for(int j=i+1;j<n;j++){
            if(prev==INT_MAX){
                prev=nums[j]-nums[j-1];
                continue;
            }
            if(nums[j]-nums[j-1]!=prev)  break;

            if(j-i+1>=3) ans++;

        }
        return ans+solution(i+1,nums);
    }

    int numberOfArithmeticSlices(vector<int>& nums) {
        n=nums.size();
        return solution(0,nums);
    }
};
