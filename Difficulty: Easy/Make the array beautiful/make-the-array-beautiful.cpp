class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>ans;
        for(auto x:arr){
            if(ans.empty()) ans.emplace_back(x);
            else if((ans.back()<0 && x>=0) || ans.back()>=0 && x<0) ans.pop_back();
            else ans.emplace_back(x);
        }
        return ans;
    }
};