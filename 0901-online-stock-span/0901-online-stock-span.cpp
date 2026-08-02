class StockSpanner {
public:

    stack<pair<int,int>>st;
    int i=0;

    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first<=price) st.pop();
        int ans=0;
        if(st.empty()) ans=i+1;
        else ans=i-st.top().second;
        st.push({price,i});
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */