typedef long long ll;
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n=servers.size();
        int m=tasks.size();
        vector<int>ans(m);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        // {completion time, weight, index}
        priority_queue<vector<ll>,vector<vector<ll>>,greater<vector<ll>>> usedservers;
        ll time=0;

        for(int i=0;i<n;i++)pq.push({servers[i], i});

        for(int i=0;i<m;i++) {
            time=max(time,(ll)i);

            while(!usedservers.empty() && usedservers.top()[0]<=time) {
                auto top = usedservers.top();
                usedservers.pop();
                pq.push({top[1],top[2]});
            }

            if(pq.empty()) {
                time = usedservers.top()[0];
                while(!usedservers.empty() && usedservers.top()[0] <= time) {
                    auto top = usedservers.top();
                    usedservers.pop();
                    pq.push({top[1],top[2]});
                }
            }

            auto availableserver = pq.top();
            pq.pop();

            ans[i]=availableserver.second;

            usedservers.push({time + tasks[i],availableserver.first,availableserver.second});
        }

        return ans;
    }
};