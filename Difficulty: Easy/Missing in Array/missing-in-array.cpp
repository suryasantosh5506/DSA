class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n = arr.size() + 1;
        long long s2=(n*1ll*(n+1))/2;
        long long s1=accumulate(arr.begin(),arr.end(),0ll);
        return s2-s1;
    }
};