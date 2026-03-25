// problem link:- https://leetcode.com/problems/construct-uniform-parity-array-ii/description/

#include<bits/stdc++.h>
using namespace std;

class Brute {
public:

//     For each index i, you must choose exactly one of the following (in any order):

// nums2[i] = nums1[i]
// nums2[i] = nums1[i] - nums1[j], for an index j != i
// Return true if it is possible to construct such an array, otherwise, return false.

    
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>odd(n,INT_MIN);
        vector<int>even(n,INT_MIN);

        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) even[i]=nums1[i];
            else{
                for(int j=0;j<n;j++){
                    if(j==i) continue;
                    if(abs(nums1[i]-nums1[j])%2==0 && nums1[i] - nums1[j] >= 1) {
                         even[i]=nums1[i]-nums1[j];
                         break;
                    }
                }
            }
    
            if(nums1[i]%2==1) odd[i]=nums1[i];
            else{
                for(int j=0;j<n;j++){
                    if(j==i) continue;
                    if(abs(nums1[i]-nums1[j])%2==1 && nums1[i] - nums1[j] >= 1){
                         odd[i]=nums1[i]-nums1[j];
                         break;
                    }
                }
            }
        }

        bool poss1=true,poss2=true;

        for(auto x:odd){
            if(x==INT_MIN){
                poss1=false;
                break;
            }
        }

        for(auto x:even){
            if(x==INT_MIN){
                poss2=false;
                break;
            }
        }
    
        return poss1||poss2;
    }
};

class Optimal {
public:
    bool uniformArray(vector<int>& nums1) {
        int minval=INT_MAX;
        bool hasodd=false;

        for(int x:nums1){
            if(x<minval) minval=x;
            if(x%2==1) hasodd=true;
        }

        if(minval%2==1) return true;
        else return !hasodd;
    }
};