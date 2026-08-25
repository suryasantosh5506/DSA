typedef long long ll;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>ugly;
        ugly.emplace_back(1);
        int size=primes.size();
        vector<int>indexes(size,0);
        while(ugly.size()<n){
            ll mini=LLONG_MAX;

            for(int i=0;i<size;i++){
                ll ele=1ll*ugly[indexes[i]]*primes[i];
                if(ele<mini){
                    mini=ele;
                }
            }
            ugly.emplace_back(mini);

            for(int i=0;i<size;i++){
                if(1ll*ugly[indexes[i]]*primes[i]==mini) indexes[i]++;
            }
        }
        return ugly[n-1];
    }
};