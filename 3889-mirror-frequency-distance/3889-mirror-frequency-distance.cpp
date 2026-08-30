class Solution {
public:
    int mirrorFrequency(string s) {
        vector<char>arr={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
                            'r','s','t','u','v','w','x','y','z'};
        unordered_map<char,char>mirror;
        int n=arr.size();
        int index=n-1;
        for(char &x:arr) mirror[x]=arr[index--];
        arr={'0','1','2','3','4','5','6','7','8','9'};
        index=9;
        for(char &x:arr) mirror[x]=arr[index--];

        unordered_map<int,int>mpp;
        for(char &x:s) mpp[x]++;
        unordered_set<char>used;

        int ans=0;
        for(char &x:s){
            if(used.count(x)) continue;
            ans+=abs(mpp[x]-mpp[mirror[x]]);
            used.insert(x);
            used.insert(mirror[x]);
        }

        return ans;
    }
};