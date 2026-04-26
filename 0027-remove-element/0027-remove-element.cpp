class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        int n=nums.size();
        for(;j<n;j++){
            if(nums[j]==val) break;
        }

        for(int i=j+1;i<n;i++){
            if(nums[i]!=val){
                swap(nums[i],nums[j]);
                j++;
            }
        }

        return j;
    }
};