#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>odd(n,INT_MIN);
        vector<int>even(n,INT_MIN);

        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) even[i]=nums1[i];
            else{
                for(int j=0;j<n && j!=i;j++){
                    if((nums1[i]-nums1[j])%2==0) even[i]=nums1[i]-nums1[j];
                }
            }
    
            if(nums1[i]%2==1) odd[i]=nums1[i];
            else{
                for(int j=0;j<n && j!=i;j++){
                    if((nums1[i]-nums1[j])%2==1) odd[i]=nums1[i]-nums1[j];
                }
            }
        }

        for(int i=0;i<n;i++){
            if(odd[i]==INT_MIN && even[i]==INT_MIN) return false;
        }
        return true;
    }
};