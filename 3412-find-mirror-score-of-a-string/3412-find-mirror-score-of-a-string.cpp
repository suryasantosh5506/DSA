typedef long long ll;
class Solution {
public:
    long long calculateScore(string s) {
        vector<char>arr;
        for(int i=0;i<26;i++) arr.emplace_back((i+'a'));
        unordered_map<char,char>mirror;
        for(int i=0;i<26;i++) mirror[arr[i]]=arr[26-i-1];
        unordered_map<char,set<int>>mpp;
        int n=s.size();
        ll score=0;
        for(int i=0;i<n;i++){
            char ch=mirror[s[i]];
            if(mpp.count(ch)){
                if(mpp[ch].empty()){
                    mpp[s[i]].insert(i);
                    continue;
                }
                int index=*(mpp[ch].rbegin());
                mpp[ch].erase(index);
                score+=i-index;
            }else{
                mpp[s[i]].insert(i);
            }
        }
        return score;
    }
};