class Solution {
public:

    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i=0,j=0;
        int n=arr.size();
        int sum=0;
        int cnt=0;
        while(j<n){
            sum+=arr[j];
            while(j-i+1>k) sum-=arr[i++];
            if(j-i+1==k && (sum/k)>=threshold) cnt++;
            j++;
        }
        return cnt;
    }
};