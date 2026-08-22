typedef long long ll;
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),[](auto &a,auto &b){
            if(a.size()!=b.size()) return a.size()>b.size();
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i]){
                    return a>b;
                }
            }
            return a>b;
        });
        return nums[k-1];
    }
};