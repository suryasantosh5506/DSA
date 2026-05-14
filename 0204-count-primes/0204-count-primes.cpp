class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<int>sieve(n);
        sieve[0]=-1;
        sieve[1]=-1;

        for(int i=2;i<n;i++) sieve[i]=i;

        for(int i=2;i*i<n;i++){
            if(sieve[i]==i){
                for(int j=i+i;j<n;j+=i) sieve[j]=i;
            }
        }

        int cnt=0;
        for(int i=2;i<n;i++){
            if(sieve[i]==i) cnt++;
        }
        return cnt;
    }
};