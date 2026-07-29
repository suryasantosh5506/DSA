class Solution {
public:

    unordered_map<int,string>mpp;

    void solution(int i,string &digits,string &seq,vector<string>&ans){
        if(i==digits.size()){
            ans.emplace_back(seq);
            return;
        }

        int num=digits[i]-'0';
        string word=mpp[num];

        for(char &ch:word){
            seq+=ch;
            solution(i+1,digits,seq,ans);
            seq.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string seq="";
        mpp[2]="abc";
        mpp[3]="def";
        mpp[4]="ghi";
        mpp[5]="jkl";
        mpp[6]="mno";
        mpp[7]="pqrs";
        mpp[8]="tuv";
        mpp[9]="wxyz";
        solution(0,digits,seq,ans);
        return ans;
    }
};