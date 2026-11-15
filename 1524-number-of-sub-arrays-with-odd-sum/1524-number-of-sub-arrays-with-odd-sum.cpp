class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int oddsumcnt=0;
        int evensumcnt=1;
        int n=arr.size();
        int sum=0;
        int ans=0;
        const int mod=1e9+7;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==1){
                oddsumcnt++;
                ans=(ans+evensumcnt)%mod;
            }else{
                evensumcnt++;
                ans=(ans+oddsumcnt)%mod;
            }
        }
        return ans;
    }
};