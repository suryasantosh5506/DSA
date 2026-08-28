class Solution {
public:

    int n,m;

    set<vector<int>>st;

    Solution(int m, int n) {
        this->n=m;
        this->m=n;
    }
    
    vector<int> flip() {
        vector<int>arr;

        do{
            arr.clear();
            arr.emplace_back(rand()%n);
            arr.emplace_back(rand()%m);
        }while(st.count(arr));
        st.insert(arr);
        return arr;
    }
    
    void reset() {
        st.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */