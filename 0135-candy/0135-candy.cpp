class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1;
        int ans=1;
        while(i<n){
            while(i<n && ratings[i]==ratings[i-1]){
                ans++;
                i++;
            }

            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                ans+=peak;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                ans+=down;
                down++;
                i++;
            }
            if(down>peak) ans+=down-peak;
        }
        return ans;
    }
};