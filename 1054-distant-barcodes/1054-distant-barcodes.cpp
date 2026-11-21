class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int>mpp;
        for(int &x:barcodes) mpp[x]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        // {cnt,num};
        for(auto it:mpp) pq.push({it.second,it.first});
        vector<int>ans;
        while(!pq.empty()){
            vector<pair<int,int>>arr;

            auto [cnt,num]=pq.top();
            pq.pop();

            if(ans.empty() || ans.back()!=num){
                ans.emplace_back(num);
                cnt--;
                if(cnt>0) pq.push({cnt,num});
                continue;
            }

            arr.emplace_back(cnt,num);
            while(!pq.empty() && ans.back()==pq.top().second){
                arr.emplace_back(pq.top());
                pq.pop();
            }
            if(!pq.empty()){
                auto [cnt,num]=pq.top();
                pq.pop();
                ans.emplace_back(num);
                cnt--;
                if(cnt>0) pq.push({cnt,num});
            }
            for(auto it:arr) pq.push(it);
        }
        return ans;
    }
};