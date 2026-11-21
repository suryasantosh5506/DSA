class Solution {
public:

    string normalise(string s){
        string ans="";
        for(char x:s) ans+=tolower(x);
        return ans;
    }

    string mask(string s){
        string ans="";
        unordered_set<char>st={'a','e','i','o','u','A','E','I','O','U'};
        for(char &x:s){
            if(st.contains(x)) ans+="*";
            else ans+=x;
        }
        return ans;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string>ans;
        unordered_map<string,string>exact;
        unordered_map<string,string>capitalize;
        unordered_map<string,string>vowel;

        for(string &s:wordlist){
            if(!exact.count(s)) exact[s]=s;
            string normal=normalise(s);
            if(!capitalize.count(normal)) capitalize[normal]=s;
            string masked=mask(normal);
            if(!vowel.count(masked)) vowel[masked]=s;
        }

        for(string &query:queries){
            string match="";
            string normal=normalise(query);
            string masked=mask(normal);
            if(exact.count(query)) match=exact[query];
            else if(capitalize.count(normal)) match=capitalize[normal];
            else if(vowel.count(masked)) match=vowel[masked];
            ans.emplace_back(match);
        }
        return ans;
    }
};