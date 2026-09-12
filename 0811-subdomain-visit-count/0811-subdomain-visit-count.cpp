class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>mpp;
        for(string str:cpdomains){
            int i=0;
            int number=0;
            
            for(;isdigit(str[i]);i++) number=number*10+(str[i]-'0');
            i++;

            string rev=str.substr(i);
            reverse(rev.begin(),rev.end());

            stringstream ss(rev);
            string word="";
            string domain="";

            while(getline(ss,word,'.')){
                domain+=word;
                mpp[domain]+=number;
                domain+='.';
            }
        }
        vector<string>ans;
        for(auto it:mpp){
            string str=it.first;
            reverse(str.begin(),str.end());
            ans.emplace_back(to_string(it.second)+" "+str);
        }
        return ans;
    }
};