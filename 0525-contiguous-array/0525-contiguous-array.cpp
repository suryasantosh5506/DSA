class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int sum=0;
        mpp[0]=-1;
        int maxi=0;

        for(int i=0;i<n;i++){
            sum+=(nums[i]==1)?1:-1;
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum]);
            }else{
                mpp[sum]=i;
            }
        }
        return maxi;
    }
};