class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner=arr[0];
        int n=arr.size();
        int maxi=arr[0];
        int cnt=0;

        for(int i=1;i<n;i++){
            if(winner>arr[i]) cnt++;
            else{
                winner=arr[i];
                cnt=1;
            }
            maxi=max(maxi,arr[i]);
            if(cnt==k) return winner;
        }
        return maxi;
    }
};