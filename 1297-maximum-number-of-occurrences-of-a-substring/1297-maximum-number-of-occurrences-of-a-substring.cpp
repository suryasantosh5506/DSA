class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string,int>mpp;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<char>unique;
            string sub="";
            for(int j=i;j<n;j++){
                unique.insert(s[j]);
                sub+=s[j];
                if(unique.size()<=maxLetters && j-i+1>=minSize && j-i+1<=maxSize){
                    mpp[sub]++;
                    ans=max(ans,mpp[sub]);
                }else if(unique.size()>maxLetters || j-i+1>maxSize) break;
            }
        }
        return ans;
    }
};