class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        unordered_map<int,int>nooftasks;
        set<int>availableservers;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>busyservers;
        // {endtime,server}
        for(int i=0;i<k;i++){
            nooftasks[i]=0;
            availableservers.insert(i);
        }
        int n=arrival.size();

        for(int i=0;i<n;i++){
            int time=arrival[i];
            while(!busyservers.empty()){
                auto top=busyservers.top();
                int endtime=top.first;
                int server=top.second;

                if(endtime>time) break;
                availableservers.insert(server);
                busyservers.pop();
            }

            if(availableservers.empty()){
                continue;
            }

            int preferredserver=i%k;
            auto it = availableservers.lower_bound(i % k);

            if(it==availableservers.end()) it=availableservers.begin();
            int server=*it;
            availableservers.erase(it);
            busyservers.push({time+load[i],server});
            nooftasks[server]++;
        
        }
        int maxi=0;
        for(auto it:nooftasks){
            maxi=max(maxi,it.second);
        }
        vector<int>ans;
        for(auto it:nooftasks){
            if(it.second==maxi) ans.emplace_back(it.first);
        }
        return ans;
    }
};