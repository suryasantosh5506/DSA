class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mpp;
        for(char &x:s) mpp[x]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp) pq.push({it.second,it.first});
        string ans="";
        while(!pq.empty()){
            vector<pair<int,char>>temp;
            auto [cnt,ch]=pq.top();
            pq.pop();

            if(ans.empty() || ans.back()!=ch){
                ans+=ch;
                cnt--;
                if(cnt>0) pq.push({cnt,ch});
            }else{
                temp.emplace_back(cnt,ch);
                while(!pq.empty() && pq.top().second==ans.back()){
                    temp.emplace_back(pq.top());
                    pq.pop();
                }
                if(pq.empty()) return "";
                ans+=pq.top().second;
                auto [cnt,ch]=pq.top();
                pq.pop();
                cnt--;
                if(cnt>0)  pq.push({cnt,ch});

                for(auto it:temp) pq.push(it);
            }
        }
        if(ans.size()!=s.size()) return "";
        return ans;
    }
};