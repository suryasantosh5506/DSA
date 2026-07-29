class Solution {
public:

    vector<vector<int>>ans;
    vector<int>seq;
    int n;

    void solution(int i,vector<int>&arr,int tgt){
        if(tgt==0){
            ans.emplace_back(seq);
            return;
        }
        if(i==n) return;
        if(tgt<0) return;

        for(int j=i;j<n;j++){
            if(j!=i && arr[j]==arr[j-1]) continue;
            seq.emplace_back(arr[j]);
            solution(j+1,arr,tgt-arr[j]);
            seq.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        n=candidates.size();
        solution(0,candidates,target);
        return ans;
    }
};