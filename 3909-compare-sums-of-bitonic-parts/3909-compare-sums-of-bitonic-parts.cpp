class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long maxi=*max_element(nums.begin(),nums.end());
        int k=0,n=nums.size();
        for(;k<n;k++){
            if(nums[k]==maxi) break;
        }
        long long lsum=accumulate(nums.begin(),nums.begin()+k+1,0ll);
        long long rsum=accumulate(nums.begin()+k,nums.end(),0ll);
        if(lsum==rsum) return -1;
        return (lsum>rsum)?0:1;
    }
};