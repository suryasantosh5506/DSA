class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[j]){
                swap(nums[j+1],nums[i]);
                j++;
            }
        }
        return j+1;
    }
};