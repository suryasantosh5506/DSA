typedef long long ll;
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<ll,int>>sorted;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            ll place=1;
            ll mappednumber=0;
            if(x==0) mappednumber=mapping[0];
            while(x>0){
                int rem=x%10;
                mappednumber+=place*mapping[rem];
                x/=10;
                place*=10;
            }
            sorted.emplace_back(mappednumber,i);
        }
        sort(sorted.begin(),sorted.end(),[&](auto &a,auto &b){
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first;
        });
        vector<int>ans;
        for(auto &x:sorted) ans.emplace_back(nums[x.second]);
        return ans;
    }
};