// problem link:- https://leetcode.com/problems/design-event-manager/description/

#include<bits/stdc++.h>
using namespace std;

class EventManager {
public:

    unordered_map<int,int>mpp;
    // {id,priority}

    
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,function<bool(pair<int,int>,pair<int,int>)>>pq;
    // {pri,id}
    
    EventManager(vector<vector<int>>& events) : pq([](pair<int,int>a,pair<int,int>b){
        if(a.first==b.first)  return a.second>b.second;
        return a.first<b.first;
    }){
        for(int i=0;i<events.size();i++){
            mpp[events[i][0]]=events[i][1];
            pq.push({events[i][1],events[i][0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(mpp.count(eventId)){
            mpp[eventId]=newPriority;
            pq.push({newPriority,eventId});
        }
    }
    
    int pollHighest() {
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();

            if(mpp.find(top.second)!=mpp.end() && top.first==mpp[top.second]){
                mpp.erase(top.second);
                return top.second;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */