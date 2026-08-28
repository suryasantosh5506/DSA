class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mpp;
        for(string &path:paths){
            stringstream ss(path);
            string word;
            getline(ss,word,' ');
            string folder=word;
            while(getline(ss,word,' ')){
                int open=word.find('(');
                int close=word.find(')');
                string orifolder=folder+"/"+word.substr(0,open);

                string content=word.substr(open+1,close-open);
                mpp[content].emplace_back(orifolder);
            }
        }

        for(auto it:mpp){
            vector<string>temp;
            if(it.second.size()<=1) continue;
            for(auto itt:it.second){
                temp.emplace_back(itt);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};