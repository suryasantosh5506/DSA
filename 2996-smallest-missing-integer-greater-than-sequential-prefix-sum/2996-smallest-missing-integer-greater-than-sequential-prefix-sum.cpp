class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi=INT_MIN;
        unordered_set<int>st(nums.begin(),nums.end());
        int n=nums.size();
        int sum=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]+1) break;
            sum+=nums[i];
        }
        int ans=sum;
        while(true){
            if(!st.count(ans)) return ans;
            ans++;
        }
        return ans;
    }
};