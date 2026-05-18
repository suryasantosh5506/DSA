class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<pair<int,int>>arr;
        for(int i=0;i<n;i++){
            arr.emplace_back(val[i],wt[i]);
        }
        
        sort(arr.begin(),arr.end(),[](auto a,auto b){
           return (double)a.first/(double)a.second>(double)b.first/(double)b.second;
        });
        
        double ans=0;
        for(auto x:arr){
            if(capacity-x.second>=0){
                ans+=x.first;
                capacity-=x.second;
            }else{
                ans+=((double)x.first/(double)x.second)*capacity;
                break;
            }
        }
        return ans;
    }
};
