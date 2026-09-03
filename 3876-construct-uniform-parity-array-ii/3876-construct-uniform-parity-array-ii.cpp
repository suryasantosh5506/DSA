class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=INT_MAX;
        bool hasOdd=false;
        for(int &x:nums1){
            if(x<mini) mini=x;
            if(x%2==1) hasOdd=true;
        }
        if(mini%2==1) return true;
        return !hasOdd;
    }
};