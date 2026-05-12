class Solution {
  public:
  
    void solution(int i,string seq,string s,vector<string>&ans){
        if(i==s.size()){
            ans.emplace_back(seq);
            return;
        } 
        
        solution(i+1,seq+s[i],s,ans);
        solution(i+1,seq,s,ans);
    }
  
    vector<string> AllPossibleStrings(string s) {
        // Code here
        vector<string>ans;
        string seq="";
        solution(0,seq,s,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};