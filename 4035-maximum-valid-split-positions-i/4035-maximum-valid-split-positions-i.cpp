class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n=nums.size();
        int ans=0;

        for(int removed=-1;removed<n;removed++){
            vector<int>arr;

            for(int i=0;i<n;i++){
                if(i==removed) continue;
                arr.emplace_back(nums[i]);
            }

            int n=arr.size();

            vector<int>prefix(n);
            vector<int>suffix(n);

            prefix[0]=arr[0];
            suffix[n-1]=arr[n-1];

            for(int i=1;i<n;i++){
                prefix[i]=gcd(prefix[i-1],arr[i]);
            }

            for(int i=n-2;i>=0;i--){
                suffix[i]=gcd(suffix[i+1],arr[i]);
            }

            int count=0;

            for(int i=0;i<n-1;i++){
                if(prefix[i]==suffix[i+1]) count++;
            }

            ans=max(ans,count);
        }
        return ans;
    }
};