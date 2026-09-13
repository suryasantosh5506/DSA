    class Solution {
    public:
        int countSpecialIntegers(vector<int>& nums) {
            int n=nums.size();
            int ans=0;
            vector<vector<int>>arr;
            for(int i=0;i<n;i++){
                arr.push_back({nums[i],i});
            }
            sort(arr.begin(),arr.end());
            for(int i=0;i<n;){
                int ele=arr[i][0];
                int ind=arr[i][1];
                int cnt=1;
                int prevdiff=-1;
                bool ok=true;
                int j=i+1;
                for(;j<n;j++){
                    if(arr[j][0]!=ele){
                        break;
                    }
                    if(prevdiff!=-1 && arr[j][1]-ind!=prevdiff){
                        ok=false;
                    }
                    cnt++;
                    prevdiff=arr[j][1]-ind;
                    ind=arr[j][1];
                }
                i=j;
                if(ok && cnt>=3) ans++;
            }
            return ans;
        }
    };