class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int>mpp;
        int ans=0;
        int n=arrivals.size();
        vector<bool>kept(n,false);

        for(int i=0;i<n;i++){
            if(i-w>=0 && kept[i-w]) mpp[arrivals[i-w]]--;
            if(mpp[arrivals[i]]<m){
                mpp[arrivals[i]]++;
                kept[i]=true;
            }else{
                ans++;
            }
        }
        
        return ans;
    }
};