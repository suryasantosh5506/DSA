class Solution {
public:

    bool ispossible(int mid,vector<int>&piles,int h){
        int timetaken=0;
        for(int &x:piles){
            timetaken+=(x+mid-1)/mid;
            if(timetaken>h) return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(mid,piles,h)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};