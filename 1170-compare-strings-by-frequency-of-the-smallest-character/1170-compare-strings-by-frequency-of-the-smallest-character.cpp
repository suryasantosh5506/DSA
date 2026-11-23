class Solution {
public:

    int getscore(string &word){
        unordered_map<char,int>mpp;
        char mini='z';
        for(char &x:word){
            mpp[x]++;
            mini=min(mini,x);
        }
        return mpp[mini];
    }


    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>arr;
        for(string &word:words) arr.emplace_back(getscore(word));
        sort(arr.begin(),arr.end());
        vector<int>ans;
        for(string query:queries) ans.emplace_back(arr.end()-upper_bound(arr.begin(),arr.end(),getscore(query)));
        return ans;
    }
};