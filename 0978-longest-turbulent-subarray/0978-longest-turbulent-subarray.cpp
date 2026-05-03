class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(i+1<n ){
                if(i%2==1 && arr[i]>arr[i+1]) cnt++;
                else if(i%2==0 && arr[i]<arr[i+1]) cnt++;
                else cnt=0;
            }
            ans=max(ans,cnt);
        }

        cnt=0;

        for(int i=0;i<n;i++){
            if(i+1<n ){
                if(i%2==0 && arr[i]>arr[i+1]) cnt++;
                else if(i%2==1 && arr[i]<arr[i+1]) cnt++;
                else cnt=0;
            }
            ans=max(ans,cnt);
        }
        return ans+1;
    }
};