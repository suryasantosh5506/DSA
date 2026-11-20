class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=grumpy.size();
        int i=0,j=0;
        int alreadysatisfied=0;
        int extrasatisfied=0;
        int maxi=0;
        while(j<n){
            if(grumpy[j]==1) extrasatisfied+=customers[j];
            else alreadysatisfied+=customers[j];

            while(j-i+1>minutes){
                if(grumpy[i]==1) extrasatisfied-=customers[i];
                i++;
            }

            maxi=max(maxi,extrasatisfied);
            j++;
        }
        return alreadysatisfied+maxi;
    }
};