class ExamRoom {
public:

    int n;
    set<int>st;

    ExamRoom(int n) {
        this->n=n;
    }
    
    int seat() {
        if(st.empty()){
            st.insert(0);
            return 0;
        }
        int prev=-1;
        int label=0;
        int maxi=*st.begin();
        for(auto it:st){
            if(prev!=-1){
                int dist=(it-prev)/2;

                if(dist>maxi){
                    maxi=dist;
                    label=prev+dist;
                }
            }
            prev=it;
        }

        if(n-1-*st.rbegin()>maxi){
            st.insert(n-1);
            return n-1;
        }
        st.insert(label);
        return label;
    }
    
    void leave(int p) {
        st.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */