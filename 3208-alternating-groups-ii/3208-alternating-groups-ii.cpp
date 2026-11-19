class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        for(int i=0;i<k-1;i++) colors.emplace_back(colors[i]);
        n=colors.size();
        int i=0,j=0;
        int ans=0;
        int cnt=0;
        while(j<n){
            if(j-1>=0 && colors[j]!=colors[j-1]) cnt++;
            else{
                cnt=0;
                i=j;
            }

            if(j-i+1>=k && cnt>=k-1) ans++;
            j++;
        }
        return ans;
    }
};