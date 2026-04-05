//problem link:- https://www.geeksforgeeks.org/problems/target-sum-1626326450/1

class Solution {
  public:
  
    int solution(int i,int sum,int tgt,vector<int>&arr){
        if(i==arr.size()){
            return tgt==sum;
        }
        
        return solution(i+1,sum-arr[i],tgt,arr)+solution(i+1,sum+arr[i],tgt,arr);
    }
  
    int totalWays(vector<int>& arr, int target) {
        //  code here
        return solution(0,0,target,arr);
    }
};
