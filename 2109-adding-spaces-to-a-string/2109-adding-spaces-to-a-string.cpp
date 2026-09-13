class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        unordered_set<int>st(spaces.begin(),spaces.end());
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.count(i)){
                ans+=' ';
            }
            ans+=s[i];
        }
        return ans;
    }
};