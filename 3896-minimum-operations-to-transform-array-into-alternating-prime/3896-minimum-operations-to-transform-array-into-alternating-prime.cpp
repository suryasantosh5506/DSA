class Solution {
public:

    int maxi;
    vector<int>sieve;

    void prime(){
        int n=maxi;
        for(int i=0;i<=n;i++) sieve[i]=i;
        sieve[0]=sieve[1]=-1;

        for(int i=2;i*i<=n;i++){
            if(sieve[i]==i){
                for(int j=i+i;j<=n;j+=i){
                    sieve[j]=i;
                }
            }
        }
    }

    int minOperations(vector<int>& nums) {
        maxi = *max_element(nums.begin(), nums.end()) + 1000;
        sieve.resize(maxi+1);
        prime();
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0){
                while(sieve[nums[i]]!=nums[i]){
                    nums[i]++;
                    ans++;
                }
            }else{
                while(sieve[nums[i]]==nums[i]){
                    nums[i]++;
                    ans++;
                }
            }
        }
        return ans;
    }
};