class Solution {
public:

    vector<int>freq;
    int ans=0;

    void solution(){
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            ans++;
            freq[i]--;
            solution();
            freq[i]++;
        }
    }

    int numTilePossibilities(string tiles) {
        freq.resize(26,0);
        for(char &x:tiles) freq[x-'A']++;
        solution();
        return ans;
    }
};