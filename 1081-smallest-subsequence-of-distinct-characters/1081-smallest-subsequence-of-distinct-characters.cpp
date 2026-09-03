class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>mpp;
        unordered_map<char,bool>used;
        stack<char>st;
        string ans="";

        for(char &x:s) mpp[x]++;

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

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};