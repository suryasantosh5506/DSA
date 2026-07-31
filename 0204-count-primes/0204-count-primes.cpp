class Solution {
public:
    int countPrimes(int n) {
        vector<int>sieve(n);
        for(int i=0;i<n;i++){
            sieve[i]=i;
        }

        for(int i=2;i*i<n;i++){
            if(sieve[i]==i){
                for(int j=i+i;j<n;j+=i){
                    sieve[j]=i;
                }
            }
        }

        int ans=0;
        for(int i=2;i<n;i++){
            if(sieve[i]==i) ans++;
        }
        return ans;
    }
};