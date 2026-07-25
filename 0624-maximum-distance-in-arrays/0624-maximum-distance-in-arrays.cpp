class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=INT_MAX;
        int maxi=INT_MIN;
        int n=arrays.size();
        int maxIndex=-1;
        for(int i=0;i<n;i++){
            int maxele=*max_element(arrays[i].begin(),arrays[i].end());
            if(maxele>maxi){
                maxIndex=i;
                maxi=maxele;
            }
        }
        for(int i=0;i<n;i++){
            if(i==maxIndex) continue;
            mini=min(mini,*min_element(arrays[i].begin(),arrays[i].end()));
        }
        int ans= maxi-mini;

        int minIndex=-1;
        mini=INT_MAX;
        maxi=INT_MIN;

        for(int i=0;i<n;i++){
            int minele=*min_element(arrays[i].begin(),arrays[i].end());
            if(minele<mini){
                minIndex=i;
                mini=minele;
            }
        }

        for(int i=0;i<n;i++){
            if(i==minIndex) continue;
            maxi=max(maxi,*max_element(arrays[i].begin(),arrays[i].end()));
        }
        return max(ans,maxi-mini);
    }
};