class StockPrice {
public:

    multiset<int>st;
    int latest=INT_MIN;
    unordered_map<int,int>prices;

    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(!prices.count(timestamp)) latest=max(latest,timestamp);
        else st.erase(st.find(prices[timestamp]));
        prices[timestamp]=price;
        st.insert(price);
    }
    
    int current() {
        return prices[latest];
    }
    
    int maximum() {
        return *st.rbegin();
    }
    
    int minimum() {
        return *st.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */