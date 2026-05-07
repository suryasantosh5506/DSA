class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());

        int i=0;
        long long sum=0;
        int num=1;
        int n=nums.size();

        while(k>0){

            if(i<n && nums[i]==num) i++;
            else{
                sum+=num;
                k--;
            }
            num++;
        }
        return sum;
    }
};