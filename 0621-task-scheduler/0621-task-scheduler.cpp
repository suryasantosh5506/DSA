class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();

        unordered_map<char,int>mpp;
        for(auto it:tasks) mpp[it]++;

        int time=0;
        priority_queue<int>pq;
        for(auto it:mpp) pq.push(it.second);


        while(!pq.empty()){
            int cycles=n+1;
            int taskscompleted=0;
            vector<int>temp;
            while(!pq.empty() && taskscompleted<cycles){
                int top=pq.top();
                pq.pop();
                top--;
                if(top>0) temp.emplace_back(top);
                taskscompleted++;
                time++;
            }

            for(auto it:temp) pq.push(it);
            if(pq.empty()) break;
            time+=(cycles-taskscompleted);
        }
        return time;
    }
};