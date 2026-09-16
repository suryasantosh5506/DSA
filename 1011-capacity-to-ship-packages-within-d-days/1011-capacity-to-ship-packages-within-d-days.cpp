class Solution {
public:

    bool possible(int mid,vector<int>& arr, int days){
        int d=1,cap=0;
        for(int &x:arr){
            if(cap+x>mid){
                cap=0;
                d++;
            }
            cap+=x;
            if(d>days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,arr,days))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};