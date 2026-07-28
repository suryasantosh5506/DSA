typedef long long ll;
class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        ll ans=0;
        int n=technique1.size();
        vector<int>diff;
        int cnt=0;

        for(int i=0;i<n;i++){
            if(technique1[i]>=technique2[i]){
                ans+=technique1[i];
                cnt++;
            }else{
                ans+=technique2[i];
                diff.emplace_back(technique2[i]-technique1[i]);
            }
        }
        if(cnt>=k) return ans;
        sort(diff.begin(),diff.end());
        int i=0;
        while(cnt<k){
            ans-=diff[i++];
            cnt++;
        }
        return ans;
    }
};