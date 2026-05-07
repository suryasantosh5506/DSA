// User function Template for C++

class Solution {
  public:
  
    bool possible(int mid,vector<int>& sweetness, int N, int k){
        int pieces=0;
        int sweet=0;
        for(auto x:sweetness){
            if(sweet+x>=mid){
                pieces++;
                sweet=0;
            }else{
                sweet+=x;
            }
            if(pieces>=k+1) return true;
        }
        return false;
    }
  
    int maxSweetness(vector<int>& sweetness, int N, int K) {
        // Write your code here.
        int low = 1;

        int high = accumulate(sweetness.begin(),
                              sweetness.end(), 0);
        int ans=0;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(mid,sweetness,N,K)){
                ans=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }
};
