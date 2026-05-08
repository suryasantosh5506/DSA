class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>atob,btoa;
        int n=s.size();
        int m=t.size();
        if(n!=m) return false;
        for(int i=0;i<n;i++){
            if(atob.find(s[i])==atob.end()) atob[s[i]]=t[i];
            else if(atob[s[i]]!=t[i]) return false;

            if(btoa.find(t[i])==btoa.end()) btoa[t[i]]=s[i];
            else if(btoa[t[i]]!=s[i]) return false;
        }
        return true;
    }
};