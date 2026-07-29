class Solution {
public:

    vector<vector<int>>ans;
    vector<int>seq;
    int n;

    void solution(int i,int tgt,int n){
        if(tgt==0){
            if(seq.size()==n) ans.emplace_back(seq);
            return;
        }
        if(seq.size()>n) return;
        if(i==10) return;
        if(tgt<0) return;

        seq.emplace_back(i);
        solution(i+1,tgt-i,n);
        seq.pop_back();
        solution(i+1,tgt,n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        solution(1,n,k);
        return ans;
    }
};