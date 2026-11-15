class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>ans(n,1);
        unordered_map<int,int>lasttimerained;
        set<int>drydays;
        for(int i=0;i<n;i++){
            if(rains[i]==0){
                drydays.insert(i);
                continue;
            }
            if(lasttimerained.count(rains[i])){
                int lasttime=lasttimerained[rains[i]];
                auto immediatedryday=drydays.upper_bound(lasttime);
                if(immediatedryday==drydays.end()) return {};
                int day=*immediatedryday;
                drydays.erase(immediatedryday);
                ans[day]=rains[i];
                ans[i]=-1;
                lasttimerained[rains[i]]=i;
            }else{
                lasttimerained[rains[i]]=i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};