class SummaryRanges {
public:

    set<int>st;

    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        set<int>used;
        for(auto it:st){
            if(used.count(it)) continue;
            vector<int>interval(2,0);
            interval[0]=it;
            used.insert(it);
            int req=it+1;
            while(st.count(req)){
                used.insert(req);
                req++;
            }
            interval[1]=req-1;
            ans.emplace_back(interval);
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */