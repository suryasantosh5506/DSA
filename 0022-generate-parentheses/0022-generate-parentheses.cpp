class Solution {
public:

    string seq="";
    vector<string>ans;
    int n;

    void solution(int i,int open,int close){
        if(i==2*n){
            if(open==close) ans.emplace_back(seq);
            return;
        }

        if(open<n){
            seq+='(';
            solution(i+1,open+1,close);
            seq.pop_back();
        }

        if(close<open){
            seq+=')';
            solution(i+1,open,close+1);
            seq.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        this->n=n;
        solution(0,0,0);
        return ans;
    }
};