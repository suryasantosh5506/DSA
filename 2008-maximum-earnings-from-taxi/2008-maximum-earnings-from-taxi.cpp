typedef long long ll;
class Solution {
public:

    int n;
    vector<ll>dp;

    int findnext(vector<vector<int>>&arr,int end){
        int low=0,high=arr.size()-1;
        int ans=n+1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(end<=arr[mid][0]){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }

    ll solution(int i,vector<vector<int>>&arr){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        ll nottake=solution(i+1,arr);

        int next=findnext(arr,arr[i][1]);
        ll take=arr[i][1]-arr[i][0]+arr[i][2]+solution(next,arr);

        return dp[i]=max(take,nottake);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        this->n=rides.size();
        dp.assign(this->n,-1);
        sort(rides.begin(),rides.end());
        return solution(0,rides);
    }
};