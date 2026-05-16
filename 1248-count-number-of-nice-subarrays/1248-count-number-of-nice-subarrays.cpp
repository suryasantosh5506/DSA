class Solution {
public:

    int solution(vector<int>&arr,int k){
        if(k<0) return 0;
        int sum=0;
        int n=arr.size();
        int i=0,j=0;
        int ans=0;

        while(j<n){
            sum+=arr[j]%2;
            while(sum>k){
                sum-=arr[i]%2;
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solution(nums,k)-solution(nums,k-1);
    }
};