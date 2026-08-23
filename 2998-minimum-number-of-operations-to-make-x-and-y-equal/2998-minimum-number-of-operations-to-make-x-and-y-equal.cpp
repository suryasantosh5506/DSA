class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int,int>>q;
        unordered_set<int>visited;
        q.push({0,x});
        visited.insert(x);

        while(!q.empty()){
            auto top=q.front();
            q.pop();

            int steps=top.first;
            int ele=top.second;

            if(ele==y) return steps;

            if(ele%11==0 && !visited.count(ele/11)){
                q.push({steps+1,ele/11});
                visited.insert(ele/11);
            }
            
            if(ele%5==0 && !visited.count(ele/5)){
                q.push({steps+1,ele/5});
                visited.insert(ele/5);
            }
            if(!visited.count(ele+1)){
                q.push({steps+1,ele+1});
                visited.insert(ele+1);
            }
            if(!visited.count(ele-1)){
                q.push({steps+1,ele-1});
                visited.insert(ele-1);
            }
        }
        return -1;
    }
};