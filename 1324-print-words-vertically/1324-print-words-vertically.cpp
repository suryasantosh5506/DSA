class Solution {
public:
    vector<string> printVertically(string s) {
        stringstream ss(s);
        vector<string>words;
        string word;
        int maxi=0;
        
        while(getline(ss,word,' ')){
            words.emplace_back(word);
            maxi=max(maxi,(int)word.size());
        }
        
        vector<string>ans;

        for(int i=0;i<maxi;i++){
            string w="";
            for(string &s:words){
                w+=(s.size()<=i)?' ':s[i];
            }
            while (!w.empty() && w.back()==' ') w.pop_back();
            ans.emplace_back(w);
        }
        return ans;
    }
};