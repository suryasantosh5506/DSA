class Solution {
  public:
  
    void reverse(stack<int>&st,int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }
        int top=st.top();
        st.pop();
        reverse(st,ele);
        st.push(top);
    }
  
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int top=st.top();
        st.pop();
        reverseStack(st);
        reverse(st,top);
    }
};