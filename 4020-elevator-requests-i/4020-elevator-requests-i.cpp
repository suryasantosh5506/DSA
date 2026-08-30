class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans=0;
        int floor=0;
        for(int &x:requests){
            ans+=abs(x-floor);
            floor=x;
        }
        return ans;
    }
};