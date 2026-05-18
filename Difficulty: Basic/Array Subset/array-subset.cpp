class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        unordered_map<int,int>mpp;
        for(auto x:a) mpp[x]++;
        for(auto x:b){
            if(mpp.find(x)==mpp.end()) return false;
            mpp[x]--;
            if(mpp[x]==0) mpp.erase(x);
        }
        return true;
    }
};