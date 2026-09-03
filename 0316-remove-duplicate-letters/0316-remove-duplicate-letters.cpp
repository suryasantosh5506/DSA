class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mpp;
        unordered_map<char,bool>used;
        for(char &x:s) mpp[x]++;
        stack<char>st;

        for(char &x:s){
            if(used.count(x)){
                mpp[x]--;
                continue;
            }
            while(!st.empty() && st.top()>=x && mpp[st.top()]>1){
                mpp[st.top()]--;
                used.erase(st.top());
                st.pop();
            }
            used[x]=true;
            st.push(x);
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};