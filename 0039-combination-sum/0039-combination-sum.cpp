class Solution {
public:

    void solution(int i,int tgt,vector<int>seq,vector<int>&candidates,vector<vector<int>>&ans){
        if(i==candidates.size()){
            if(tgt==0){
                ans.emplace_back(seq);
            }
            return;
        }

        if(tgt<0) return;

        seq.emplace_back(candidates[i]);
        solution(i,tgt-candidates[i],seq,candidates,ans);
        seq.pop_back();
        solution(i+1,tgt,seq,candidates,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>seq;
        solution(0,target,seq,candidates,ans);
        return ans;
    }
};