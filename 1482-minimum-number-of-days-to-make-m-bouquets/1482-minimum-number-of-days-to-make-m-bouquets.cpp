typedef long long ll;
class Solution {
public:

    bool possible(int mid,vector<int>&bloomDay,int m,int k){
        int boquets=0;
        int cnt=0;
        for(auto x:bloomDay){
            if(x>mid){
                boquets+=cnt/k;
                cnt=0;
            }else cnt++;

            if(boquets>=m) return true;
        }
        boquets+=cnt/k;
        return boquets>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<1ll*m*k) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,bloomDay,m,k)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};