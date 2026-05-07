class Solution {
public:

    bool possible(int mid,vector<int>& weights, int days){
        int cap=0;
        int totaldays=1;

        for(auto x:weights){
            if(cap+x>mid){
                totaldays++;
                cap=0;
            }
            cap+=x;
            if(totaldays>days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,weights,days)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};