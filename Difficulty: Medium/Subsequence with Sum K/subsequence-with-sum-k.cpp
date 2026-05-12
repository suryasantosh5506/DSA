class Solution {
  public:
  
    bool solution(int i,vector<int>&arr,int k){
        if(k==0) return true;
        if(k < 0) return false;
        if(i==arr.size()) return k==0;
        
        return solution(i+1,arr,k-arr[i])||solution(i+1,arr,k);
    }
  
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        // Code here
        return solution(0,arr,k);
    }
};