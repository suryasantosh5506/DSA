class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(auto &x:nums){
            string str=to_string(x);
            for(auto ch:str){
                ans.emplace_back(ch-'0');
            }
        }
        return ans;
    }
};