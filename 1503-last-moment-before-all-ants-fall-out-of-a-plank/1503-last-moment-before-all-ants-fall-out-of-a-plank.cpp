class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxi=0; 
        if(!left.empty()) maxi=max(maxi,*max_element(left.begin(),left.end()));
        if(!right.empty()) maxi=max(maxi,n-*min_element(right.begin(),right.end()));
        return maxi;
    }
};