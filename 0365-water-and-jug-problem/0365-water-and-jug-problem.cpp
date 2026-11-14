class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        queue<pair<int,int>>q;
        q.push({0,0});
        set<pair<int,int>>visited;
        visited.insert({0,0});

        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();

            if(a==target || b==target || a+b==target) return true;

            // fill first jug
            pair<int,int>operation={x,b};
            if(!visited.count(operation)){
                q.push(operation);
                visited.insert(operation);
            }
            
            // fill second jug
            operation={a,y};
            if(!visited.count(operation)){
                q.push(operation);
                visited.insert(operation);
            }

            // empty first jug
            operation={0,b};
            if(!visited.count(operation)){
                q.push(operation);
                visited.insert(operation);
            }

            // empty second jug
            operation={a,0};
            if(!visited.count(operation)){
                q.push(operation);
                visited.insert(operation);
            }

            // pour from a to b
            int atob=min(a,y-b);
            operation={a-atob,b+atob};
            if(!visited.count(operation)){
                q.push(operation);
                visited.insert(operation);
            }

            // pour from b to a
            int btoa=min(b,x-a);
            operation={a+btoa,b-btoa};
            if(!visited.count(operation)){
                q.push(operation);
                visited.insert(operation);
            }
        }
        return false;
    }
};