class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int>users(numberOfUsers,0);
        unordered_map<int,string>offline;
        unordered_map<int,int>availability;

        sort(events.begin(),events.end(),[](auto &a,auto &b){
            int t1=stoi(a[1]);
            int t2=stoi(b[1]);

            if(t1==t2) return a[0]=="OFFLINE" && b[0]=="MESSAGE";
            return t1<t2;
        });

        for(auto &event:events){
            string eventType=event[0];
            int timestamp=stoi(event[1]);
            stringstream ss(event[2]);

            for(auto it=availability.begin();it!=availability.end();){
                if(it->second <= timestamp){
                    offline.erase(it->first);
                    it=availability.erase(it);
                }
                else it++;
            }

            if(eventType=="OFFLINE"){
                string id="";
                while(getline(ss,id,' ')){
                    int num=stoi(id);
                    offline[num]="OFFLINE";
                    availability[num]=timestamp+60;
                }
            }

            if(eventType=="MESSAGE"){
                if(event[2]=="ALL"){
                    for(int &it:users) it++;
                }else if(event[2]=="HERE"){
                    for(int i=0;i<users.size();i++){
                        if(offline.count(i)) continue;
                        users[i]++;
                    }
                }else{
                    string id="";
                    while(getline(ss,id,' ')){
                        int num=stoi(id.substr(2));
                        users[num]++;
                    }
                }
            }
        }

        return users;
    }
};