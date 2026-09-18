class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size(),m=t.size();
        if(n!=m) return false;
        unordered_map<char,char>stot,ttos;
        for(int i=0;i<n;i++){
            if(stot.count(s[i])) if(stot[s[i]]!=t[i]) return false;
            if(ttos.count(t[i])) if(ttos[t[i]]!=s[i]) return false;
            stot[s[i]]=t[i];
            ttos[t[i]]=s[i];
        }
        return true;
    }
};