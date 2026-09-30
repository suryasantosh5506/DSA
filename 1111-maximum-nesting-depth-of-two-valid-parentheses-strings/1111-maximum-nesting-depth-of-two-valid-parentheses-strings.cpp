class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth=0;
        vector<int>ans;
        for(char &x:seq){
            if(x=='(') ans.emplace_back(depth++%2);
            else ans.emplace_back(--depth%2);
        }
        return ans;
    }
};