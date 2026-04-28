class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;

        for(auto row:grid){
            for(auto ele:row){
                arr.emplace_back(ele);
            }
        }

        int rem = arr[0] % x;
        for(int val : arr){
            if(val % x != rem) return -1;
        }

        sort(arr.begin(),arr.end());
        int ans=0;

        int median=arr[arr.size()/2];
        for(auto val:arr){
            ans+=abs(val-median)/x;
        }
        return ans;
    }
};