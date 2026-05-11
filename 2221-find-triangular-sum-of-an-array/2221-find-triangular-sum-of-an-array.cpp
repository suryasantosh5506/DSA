class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(true){
            int n=nums.size();
            if(n==1) break;
            vector<int>arr;
            for(int i=0;i<n-1;i++){
                int sum=nums[i]+nums[i+1];
                arr.emplace_back(sum%10);
            }
            nums=arr;
        }
        return nums[0];
    }
};