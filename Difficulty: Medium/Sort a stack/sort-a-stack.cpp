class Solution {
  public:
  
    void sort(stack<int>&st,int ele){
        if(st.empty() || st.top()<=ele){
            st.push(ele);
            return;
        }
        int top=st.top();
        st.pop();
        sort(st,ele);
        st.push(top);
    }
  
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        int top=st.top();
        st.pop();
        sortStack(st);
        sort(st,top);
    }
};
