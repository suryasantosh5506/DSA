class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans=1;
        int i=1;
        int n=ratings.size();
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                ans++;
                i++;
                continue;
            }

            int top=1;
            while(i<n && ratings[i]>ratings[i-1]){
                top++;
                ans+=top;
                i++;
            }
            int down=1;
            while(i<n && ratings[i]<ratings[i-1]){
                ans+=down;
                down++;
                i++;
            }
            if(down>top) ans+=down-top;
        }
        return ans;
    }
};