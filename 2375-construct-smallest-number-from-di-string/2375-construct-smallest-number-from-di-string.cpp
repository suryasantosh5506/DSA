class Solution {
public:
    string smallestNumber(string pattern) {
        stack<char>st;
        int n=pattern.size();
        string ans="";
        char ch='1';
        for(char &x:pattern){
            if(x=='I'){
                ans+=ch++;
                while(!st.empty()){
                    ans+=st.top();
                    st.pop();
                }
            }else st.push(ch++);
        }
        st.push(ch);
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};