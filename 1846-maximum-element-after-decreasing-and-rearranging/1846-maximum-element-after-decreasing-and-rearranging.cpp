class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=1;
        int n=arr.size();
        if(arr[0]!=1){
            ans=1;
            arr[0]=1;
        }
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])>1){
                arr[i]=arr[i-1]+1;
            }
            ans=max(ans,arr[i]);
        }
        return ans;
    }
};