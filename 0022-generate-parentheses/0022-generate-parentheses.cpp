class Solution {
public:

    vector<string>ans;

    void solution(int open,int close,int n,string seq){
        if(seq.size()==2*n){
            if(open==close){
                ans.emplace_back(seq);
            }
            return;
        }

        if(open<n){
            solution(open+1,close,n,seq+'(');
        }
        if(close<open){
            solution(open,close+1,n,seq+')');
        }
    }

    vector<string> generateParenthesis(int n) {
        solution(0,0,n,"");
        return ans;    
    }
};