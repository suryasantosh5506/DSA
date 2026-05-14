class SpecialStack {
  public:
  
    stack<pair<int,int>>st;
    
    SpecialStack() {
        // Define Stack
    }

    void push(int x) {
        // Push an element into the stack
        int maxi=(st.empty())?x:max(x,st.top().second);
        st.push({x,maxi});
    }

    void pop() {
        // Remove the top element from the Stack
        st.pop();
    }

    int peek() {
        // Returns the top element
        if(isEmpty()) return -1;
        return st.top().first;
    }

    bool isEmpty() {
        // Check if stack is empty
        return st.empty();
    }

    int getMax() {
        // Return maximum element of Stack
        if(isEmpty()) return -1;
        return st.top().second;
    }
};