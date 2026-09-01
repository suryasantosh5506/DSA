class Solution {
public:
    string minimizeStringValue(string s) {
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>>pq;
        unordered_map<char,int>mpp;
        int marks=0;
        vector<char>choosen;

        for(char &ch:s){
            if(ch=='?') marks++;
            else mpp[ch]++;
        }
        for(auto it:mpp) pq.push({it.second,it.first});
        for(char ch='a';ch<='z';ch++){
            if(!mpp.count(ch)){
                pq.push({0,ch});
            }
        }

        while(marks>0){
            auto top=pq.top();
            pq.pop();

            int freq=top.first;
            char ch=top.second;

            choosen.emplace_back(ch);
            freq++;

            pq.push({freq,ch});
            marks--;
        }

        sort(choosen.begin(),choosen.end());
        
        int i=0;
        for(char &x:s) if(x=='?') x=choosen[i++];

        return s;
    }
};