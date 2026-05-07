class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int>st(banned.begin(),banned.end());
        int cnt=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end()){
                if(sum+i>maxSum) break;
                cnt++;
                sum+=i;
            }
        }
        return cnt;
    }
};