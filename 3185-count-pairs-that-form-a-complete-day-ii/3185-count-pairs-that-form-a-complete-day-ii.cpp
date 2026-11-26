typedef long long ll;
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        ll cnt=0;
        int n=hours.size();
        unordered_map<int,ll>mpp;
        for(int i=0;i<n;i++){
            hours[i]%=24;
            cnt+=mpp[(24-hours[i])%24];
            mpp[hours[i]]++;
        }
        return cnt;
    }
};