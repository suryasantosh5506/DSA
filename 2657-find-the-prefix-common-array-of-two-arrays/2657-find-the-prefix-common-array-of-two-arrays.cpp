class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>ans(n);
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[A[i]]++;
            mpp[B[i]]--;
            int common=0;
            for(auto it:mpp){
                if(it.second==0) common++;
            }
            ans[i]=common;
        }
        return ans;
    }
};