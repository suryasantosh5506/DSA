class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        for(char &x:s){
            if(!st.empty() && st.top().first==x){
                st.top().second++;
            }else st.push({x,1});
            if(st.top().second==k) st.pop();
        }
        string ans="";
        while(!st.empty()){
            ans+=string(st.top().second,st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};