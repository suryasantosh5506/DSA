class Solution {
public:

    void solution(int i,int tgt,vector<int>&candidates,vector<int>seq,vector<vector<int>>&ans){
        if(tgt==0){
            ans.emplace_back(seq);
            return;
        }
        if(i==candidates.size()){
            if(tgt==0) ans.emplace_back(seq);
            return;
        }

        if(tgt < 0) return;
        
        for(int j=i;j<candidates.size();j++){
            if(j!=i && candidates[j]==candidates[j-1]) continue;
            seq.emplace_back(candidates[j]);
            solution(j+1,tgt-candidates[j],candidates,seq,ans);
            seq.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>seq;
        sort(candidates.begin(),candidates.end());
        solution(0,target,candidates,seq,ans);
        return ans;
    }
};