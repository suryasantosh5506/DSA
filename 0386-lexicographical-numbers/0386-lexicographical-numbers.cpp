class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>temp;
        for(int i=1;i<=n;i++) temp.emplace_back(to_string(i));
        sort(temp.begin(),temp.end());
        vector<int>ans;
        for(string &x:temp) ans.emplace_back(stoi(x));
        return ans;
    }
};