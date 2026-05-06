class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long pro=1ll*mid*mid;
            if(pro==x) return mid;
            if(pro<x) low=mid+1;
            else high=mid-1;
        }
        return high;
    }
};