class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums.end()-upper_bound(nums.begin(),nums.end(),nums[i])>=k) cnt++;
        }
        return cnt;
    }
};