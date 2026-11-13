class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>noofmatches;
        unordered_map<int,int>win,loss;
        for(auto &match:matches){
            noofmatches[match[0]]++;
            noofmatches[match[1]]++;
            win[match[0]]++;
            loss[match[1]]++;
        }
        vector<int>noloss;
        vector<int>oneloss;
        for(auto x:win) if(!loss.count(x.first)) noloss.emplace_back(x.first);
        for(auto x:loss) if(x.second==1) oneloss.emplace_back(x.first);
        sort(noloss.begin(),noloss.end());
        sort(oneloss.begin(),oneloss.end());
        return {noloss,oneloss};
    }
};