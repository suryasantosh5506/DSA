class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int ans=0;
        stack<int>st;
        st.push(0);
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(0);
            }else{
                int open=st.top();
                st.pop();
                int value=0;
                if(open==0) value=1;
                else value=2*open;
                st.top()+=value;
            }
        }
        return st.top();
    }
};