typedef long long ll;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++){
            mpp[nums[i]].push_back(i);
        }

        vector<ll> ans(n, 0);

        for(auto &it : mpp){
            vector<int> &v = it.second;

            ll sum = 0;
            int count = 0;

            for(int i=0;i<v.size();i++){
                ans[v[i]]+=1ll*v[i]*count-sum;
                count++;
                sum+=v[i];
            }

            sum=0;
            count=0;

            for(int i=v.size()-1;i>=0;i--){
                ans[v[i]]+=abs(1ll*v[i]*count-sum);
                count++;
                sum+=v[i];
            }
        }

        return ans;
    }
};