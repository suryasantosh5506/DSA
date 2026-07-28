class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        double ans=0;
        vector<vector<pair<int,double>>>graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].emplace_back(edges[i][1],succProb[i]);
            graph[edges[i][1]].emplace_back(edges[i][0],succProb[i]);
        }
        priority_queue<pair<double,int>>pq;
        // probability,node
        vector<double>distanceTracer(n, numeric_limits<double>::lowest());
        pq.push({1,start_node});
        distanceTracer[start_node]=1;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            int node=top.second;
            double prob=top.first;

            if (prob < distanceTracer[node]) continue;

            if(node==end_node) return prob;

            for(auto it:graph[node]){
                if(distanceTracer[it.first]<prob*it.second){
                    distanceTracer[it.first]=prob*it.second;
                    pq.push({prob*it.second,it.first});
                }
            }
        }
        return 0;
    }
};