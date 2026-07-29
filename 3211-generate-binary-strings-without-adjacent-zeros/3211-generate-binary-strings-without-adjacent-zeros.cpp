class Solution {
public:

    vector<string>ans;
    string seq="";

    void solution(int n){
        if(seq.size()==n){
            ans.emplace_back(seq);
            return;
        }

        if(seq.empty() || seq.back()!='0'){
            seq+='0';
            solution(n);
            seq.pop_back();
        }
        seq+='1';
        solution(n);
        seq.pop_back();
    }

    vector<string> validStrings(int n) {
        solution(n);
        return ans;
    }
};