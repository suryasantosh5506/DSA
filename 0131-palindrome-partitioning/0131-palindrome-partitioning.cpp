class Solution {
public:

    vector<vector<string>>ans;
    vector<string>seq;
    int n;

    bool palindrome(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    void solution(int i,string s){
        if(i==n){
            ans.emplace_back(seq);
            return;
        }

        for(int j=i;j<n;j++){
            if(!palindrome(i,j,s)) continue;
            seq.emplace_back(s.substr(i,j-i+1));
            solution(j+1,s);
            seq.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        n=s.size();
        solution(0,s);
        return ans;
    }
};