class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mpp;
        int n=time.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            time[i]%=60;
            cnt+=mpp[(60-time[i])%60];
            mpp[time[i]]++;
        }
        return cnt;
    }
};