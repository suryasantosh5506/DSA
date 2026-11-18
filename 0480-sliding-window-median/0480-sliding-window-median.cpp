class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int>dq;
        multiset<int>small,big;
        vector<double>ans;
        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front()<=i-k){
                int ele=nums[dq.front()];
                if(small.count(ele)){
                    small.erase(small.find(ele));
                }else{
                    big.erase(big.find(ele));
                }
                dq.pop_front();
            }

            dq.push_back(i);
            small.insert(nums[i]);
            big.insert(*small.rbegin());
            small.erase(prev(small.end()));

            while(small.size()<big.size()){
                small.insert(*big.begin());
                big.erase(big.begin());
            }

            if(i>=k-1){
                if(k%2==0){
                    ans.emplace_back(((double)*small.rbegin()+*big.begin())/2.0);
                }else{
                    ans.emplace_back(*small.rbegin());
                }
            }
        }
        return ans;
    }
};