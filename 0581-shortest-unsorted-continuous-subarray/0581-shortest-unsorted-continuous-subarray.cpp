class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int>sorted(nums.begin(),nums.end());
        sort(sorted.begin(),sorted.end());
        int n=nums.size();
        int start=-1,last=-1;

        for(int i=0;i<n;i++){
            if(nums[i]!=sorted[i]){
                if(start==-1) start=i;
                else last=i;
            }
        }
        return (start==-1)?0:last-start+1;
    }
};