class Solution {
public:

    bool possible(int mid,vector<int> &position, int m){
        int last=position[0];
        int balls=1;
        
        for(auto x:position){
            if(x-last>=mid){
                balls++;
                last=x;
            }
            if(balls>=m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=0,high=position[n-1]-position[0];
        int ans=-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,position,m)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};