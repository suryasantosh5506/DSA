class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        for(int &x:nums){
            if(x%k==0) st.insert(x);
        }
        for(int i=k;;i=i+k){
            if(!st.count(i)) return i;
        }
        return -1;
    }
};