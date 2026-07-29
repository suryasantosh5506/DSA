class Solution {
public:

    vector<vector<int>>ans;
    vector<int>seq;
    int n;

    void solution(int i,vector<int>&arr,int tgt){
        if(i==n){
            if(tgt==0) ans.emplace_back(seq);
            return;
        }

        if(tgt<0) return;

        seq.emplace_back(arr[i]);
        solution(i,arr,tgt-arr[i]);
        seq.pop_back();
        solution(i+1,arr,tgt);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        solution(0,candidates,target);
        return ans;
    }
};