class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0;
        int curr=capacity;
        int n=plants.size();
        for(int i=0;i<n;i++){
            if(curr<plants[i]){
                ans+=i;    //reaching back to refill water
                ans+=i+1;  // reaching back to current plant
                curr=capacity;
            }else{
                ans++;
            }
            curr-=plants[i];
        }
        return ans;
    }
};