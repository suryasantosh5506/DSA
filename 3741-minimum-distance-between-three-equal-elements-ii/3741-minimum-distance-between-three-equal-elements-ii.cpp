class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,vector<int>>mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]].emplace_back(i);
        }

        for(auto it:mpp){
            auto &v=it.second;
            if(v.size()<3) continue;

            int sum=0;

            for(int i=0;i+2<v.size();i++){
                sum=2*(v[i+2]-v[i]);
                ans=min(ans,sum);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};