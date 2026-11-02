class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        sort(nums.begin(),nums.end());
        int med1=n/2;
        int med2=n/2-1;
        int op1=0,op2=0;
        for(int &x:nums){
            op1+=abs(x-nums[med1]);
            op2+=abs(x-nums[med2]);
        }
        if(n&1) return op1;
        return min(op1,op2);
    }
};