class Solution {
public:

    vector<int>solution(int row){
        int ele=1;
        vector<int>ans;
        ans.emplace_back(ele);
        for(int i=0;i<row;i++){
            ele*=(row-i);
            ele/=i+1;
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