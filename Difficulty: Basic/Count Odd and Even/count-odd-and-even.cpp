class Solution {
  public:
    /*Function to count even and odd elements in the array
     * arr : Array with its elements
     */
    pair<int, int> countOddEven(vector<int> &arr) {
        // your code here
        int odd=0;
        int even=0;
        for(auto x:arr){
            if(x&1) odd++;
            else even++;
        }
        return {odd,even};
    }
};