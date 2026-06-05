class Solution {
public:

    vector<int> solution(int row){
        vector<int>ans;
        ans.emplace_back(1);
        int ele=1;
        for(int col=0;col<row;col++){
            ele=ele*(row-col);
            ele/=(col+1);
            ans.emplace_back(ele);
        }
        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            ans.emplace_back(solution(i));
        }
        return ans;
    }
};