class Solution {
public:
    int minBitFlips(int start, int goal) {
        goal=start^goal;
        int ans=0;
        while(goal>0){
            goal&=(goal-1);
            ans++;
        }
        return ans;
    }
};