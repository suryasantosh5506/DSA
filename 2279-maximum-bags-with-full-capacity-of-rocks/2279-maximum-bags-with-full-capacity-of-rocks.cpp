class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<vector<int>>arr;
        int n=capacity.size();

        for(int i=0;i<n;i++){
            arr.push_back({capacity[i],rocks[i]});
        }

        sort(arr.begin(),arr.end(),[](auto a,auto b){
            return a[0]-a[1]<b[0]-b[1];
        });

        int i=0;

        for(;i<n;i++){
            int rem=arr[i][0]-arr[i][1];
            if(additionalRocks-rem<0) break;
            additionalRocks-=rem;
        }
        return i;
    }
};