class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        vector<vector<string>>ans;
        set<string>food;
        vector<string>fooditems;
        map<pair<string,string>,int>mpp;
        // {table,item}
        set<int>tablenumbers;

        for(auto it:orders){
            food.insert(it[2]);
            mpp[{it[1],it[2]}]++;
            tablenumbers.insert(stoi(it[1]));
        }

        fooditems.emplace_back("Table");
        for(auto it:food) fooditems.emplace_back(it);

        ans.emplace_back(fooditems);
        
        for(auto it:tablenumbers){
            vector<string>freq;
            freq.emplace_back(to_string(it));
            for(int i=1;i<fooditems.size();i++){
                freq.emplace_back(to_string(mpp[{to_string(it),fooditems[i]}]));
            }
            ans.emplace_back(freq);
        }
        return ans;
    }
};