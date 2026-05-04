class Solution {
  public:
  
    int count(int n){
        int cnt=0;
        while(n>0){
            n&=(n-1);
            cnt++;
        }
        return cnt;
    }
  
    vector<int> sortBySetBitCount(vector<int>& arr) {
        // code here
        stable_sort(arr.begin(),arr.end(),[&](int a,int b){
            return count(a)>count(b);
        });
        return arr;
    }
};