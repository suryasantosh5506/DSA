class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly;
        ugly.emplace_back(1);
        int a=0,b=0,c=0;
        while(ugly.size()<n){
            int ele1=2*ugly[a];
            int ele2=3*ugly[b];
            int ele3=5*ugly[c];

            int next=min({ele1,ele2,ele3});
            ugly.emplace_back(next);

            if(ele1==next) a++;
            if(ele2==next) b++;
            if(ele3==next) c++;
        }
        return ugly[n-1];
    }
};