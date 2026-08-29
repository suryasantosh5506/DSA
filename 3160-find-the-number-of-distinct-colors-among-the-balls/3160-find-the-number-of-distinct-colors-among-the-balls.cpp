class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int,set<int>>colorToBalls;
        unordered_map<int,int>ballToColor;
        vector<int>ans;
        for(auto &it:queries){
            int ball=it[0];
            int color=it[1];

            if(ballToColor.count(ball)){
                int prev=ballToColor[ball];
                colorToBalls[prev].erase(ball);
                ballToColor.erase(ball);
                if(colorToBalls[prev].size()==0){
                    colorToBalls.erase(prev);
                }
            }

            ballToColor[ball]=color;
            colorToBalls[color].insert(ball);
            ans.emplace_back(colorToBalls.size());
        }
        return ans;
    }
};