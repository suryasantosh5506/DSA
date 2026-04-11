class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mpp;
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            mpp[nums[i]].emplace_back(i);
        }

        for(auto x:mpp){
            auto &v=x.second;
            if(v.size()<3) continue;

            for(int i=0;i+2<v.size();i++){
                ans=min(ans,2*(v[i+2]-v[i]));
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};