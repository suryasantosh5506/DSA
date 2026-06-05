class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        ans.emplace_back(1);
        long long ele=1;
        for(int col=0;col<rowIndex;col++){
            ele=ele*(rowIndex-col);
            ele=ele/(col+1);
            ans.emplace_back(ele);
        }
        return ans;
    }
};