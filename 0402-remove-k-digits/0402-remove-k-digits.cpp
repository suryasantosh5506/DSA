class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans="";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        int i=0;
        for(;i<ans.size();i++){
            if(ans[i]!='0') break;
        }

        ans=ans.substr(i);

        return ans.empty()?"0":ans;
    }
};