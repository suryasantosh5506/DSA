class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        vector<int>ans;
        for(int &x:nums){
            if(x%2==0) sum+=x;
        }

        for(auto query:queries){
            int index=query[1];
            int val=query[0];

            if(nums[index]%2==0) sum-=nums[index];
            nums[index]+=val;
            if(nums[index]%2==0) sum+=nums[index];
            ans.emplace_back(sum);
        }
        return ans;
    }
};