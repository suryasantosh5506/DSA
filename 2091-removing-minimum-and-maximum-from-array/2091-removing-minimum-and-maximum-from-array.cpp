class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX,minInd=-1;
        int maxi=INT_MIN,maxInd=-1;

        for(int i=0;i<n;i++){
            if(nums[i]<mini){
                mini=nums[i];
                minInd=i;
            }

            if(nums[i]>maxi){
                maxi=nums[i];
                maxInd=i;
            }
        }

        int front=max(minInd,maxInd)+1;
        int back=n-min(minInd,maxInd);
        int middle=min(minInd,maxInd)+1+n-max(minInd,maxInd);
        return min({front,middle,back});
    }
};