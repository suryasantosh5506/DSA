class RangeFreqQuery {
public:

    unordered_map<int,vector<int>>mpp;

    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) mpp[arr[i]].emplace_back(i);
    }
    

    int query(int left, int right, int value) {
        vector<int>&arr=mpp[value];
        int f=lower_bound(arr.begin(),arr.end(),left)-arr.begin();
        int s=upper_bound(arr.begin(),arr.end(),right)-arr.begin();
        return s-f;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */