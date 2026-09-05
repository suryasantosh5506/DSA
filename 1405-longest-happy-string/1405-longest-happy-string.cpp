class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});

        while(!pq.empty()){
            auto [cnt,ch]=pq.top();
            pq.pop();

            vector<pair<int,char>>temp;
            if(ans.empty() || ans.size()<2){
                ans+=ch;
                cnt--;
                if(cnt>0) pq.push({cnt,ch});
            }else{
                pq.push({cnt,ch});
                string sub=ans.substr(ans.size()-2);
                while(!pq.empty() && sub==string(2,pq.top().second)){
                    temp.emplace_back(pq.top());
                    pq.pop();
                }
                if(pq.empty()) return ans;
                auto [cnt,ch]=pq.top();
                pq.pop();
                ans+=ch;
                cnt--;
                if(cnt>0) pq.push({cnt,ch});

                for(auto it:temp) pq.push(it);
            }
        }
        return ans;
    }
};