class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        for(int &x:nums) mini=min(mini,x);
        int ans=0;
        for(int &x:nums){
            if(x==mini) continue;
            else ans+=x-mini;
        }
        return ans;
    }
};