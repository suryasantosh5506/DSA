class Solution {
public:

    const int mod=1e9+7; 

    int power(int base,int exp){
        int ans=1;
        while(exp>0){
            if(exp%2==0){
                base=(1ll*base*base)%mod;
                exp/=2;
            }else{
                ans=(1ll*ans*base)%mod;
                exp--;
            }
        }
        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<=j){
            int sum=nums[i]+nums[j];
            if(sum<=target){
                ans=(ans+power(2,j-i))%mod;
                i++;
            }else j--;
        }
        return ans;
    }
};