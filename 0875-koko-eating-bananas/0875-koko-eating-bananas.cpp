class Solution {
public:

    bool possible(int mid,vector<int>& piles, int h){
        int hours=0;
        for(int &x:piles){
            hours+=(x+mid-1)/mid;
            if(hours>h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,piles,h)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};