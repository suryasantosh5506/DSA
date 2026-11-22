class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int>arr={a,b,c};
        sort(arr.begin(),arr.end());
        a=arr[0],b=arr[1],c=arr[2];
        while(a+b<c) c=a+b;
        return max({a,b,c})-min({a,b,c});
    }
};