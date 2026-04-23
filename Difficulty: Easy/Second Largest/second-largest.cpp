class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int fmaxi=INT_MIN,smaxi=INT_MIN;
        for(auto x:arr){
            if(x>fmaxi){
                smaxi=fmaxi;
                fmaxi=x;
            }else if(x!=fmaxi && x>smaxi){
                smaxi=x;
            }
        }
        return smaxi==INT_MIN?-1:smaxi;
    }
};