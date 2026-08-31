class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>>arr;
        for(auto restaurant:restaurants){
            if((veganFriendly==0 || restaurant[2]==1) && restaurant[3]<=maxPrice && restaurant[4]<=maxDistance){
                arr.emplace_back(restaurant);
            }
        }

        sort(arr.begin(),arr.end(),[](auto &a,auto &b){
            if(a[1]==b[1]){
                return a[0]>b[0];
            }
            return a[1]>b[1];
        });
        vector<int>ans;
        for(auto it:arr) ans.emplace_back(it[0]);
        return ans;
    }
};