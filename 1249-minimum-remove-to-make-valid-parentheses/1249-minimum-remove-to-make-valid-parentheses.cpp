class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        unordered_set<int>invalid;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                if(st.empty()) invalid.insert(i);
                else st.pop();
            }
        }
        while(!st.empty()){
            invalid.insert(st.top());
            st.pop();
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(!invalid.count(i)) ans+=s[i];
        }
        return ans;
    }
};