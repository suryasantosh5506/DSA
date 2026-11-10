class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        int n=s1.size();
        int i=0;
        string seq1="",seq2="";
        while(i<n){
            if(s1[i]==s2[i]){
                i++;
                continue;
            }
            while(i<n && s1[i]!=s2[i]){
                seq1+=s1[i];
                seq2+=s2[i];
                i++;
            }
            ans.push_back({seq1,seq2});
            seq1.clear();
            seq2.clear();
        }
        if(!seq1.empty()) ans.push_back({seq1,seq2});
        return ans;
    }
};