class MyCalendar {
public:

    set<vector<int>>st;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        if(st.empty()){
            st.insert({startTime,endTime});
            return true;
        }
        for(auto it:st){
            int estart=it[0],eend=it[1];
            if(estart<endTime && eend>startTime) return false;
        }
        st.insert({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */