class Solution {

    boolean possible(int mid,int position[], int m){
        int last=position[0];
        int balls=1;
        
        for(int x:position){
            if(x-last>=mid){
                balls++;
                last=x;
            }
            if(balls>=m) return true;
        }
        return false;
    }

    public int maxDistance(int[] position, int m) {
        Arrays.sort(position);
        int n=position.length;
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
}