class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>freq;
        unordered_map<int,int>need; // how many subsequences are waiting for the current ele to get extended
        for(int x:nums) freq[x]++;

        for(int &x:nums){
            if(freq[x]==0) continue;

            // extend existing subsequence
            if(need[x]>0){
                need[x]--;
                need[x+1]++;
            }
            // create new subsequence
            else if(freq[x+1]>0 && freq[x+2]>0){
                freq[x+1]--;
                freq[x+2]--;
                need[x+3]++;
            }else{
                return false;
            }
            freq[x]--;
        }
        return true;
    }
};