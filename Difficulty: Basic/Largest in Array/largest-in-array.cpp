class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int maxi=INT_MIN;
        for(auto x:arr) maxi=max(maxi,x);
        return maxi;
    }
};
