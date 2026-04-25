class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,maxi=0;
        for(auto x:nums){
            if(x==0){
                maxi=max(maxi,cnt);
                cnt=0;
            }else cnt++;
        }
        return max(maxi,cnt);
    }
};