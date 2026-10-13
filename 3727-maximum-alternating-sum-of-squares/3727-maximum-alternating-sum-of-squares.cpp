typedef long long ll;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        ll sum=0;
        sort(nums.begin(),nums.end(),[](auto &a,auto &b){
            return abs(a)<abs(b);
        });
        int i=0,j=n-1;
        bool add=true;
        while(i<=j){
            if(add){
                sum+=(1ll*nums[j]*nums[j]);
                j--;
            }else{
                sum-=(1ll*nums[i]*nums[i]);
                i++;
            }
            add=!add;
        }
        return sum;
    }
};