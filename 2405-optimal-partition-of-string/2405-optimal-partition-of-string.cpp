class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>freq;
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(freq[s[i]]==1){
                cnt++;
                freq.clear();
            }
            freq[s[i]]++;
        }
        if(!freq.empty()) cnt++;
        return cnt;
    }
};