// problem link:- https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/?envType=daily-question&envId=2026-03-30

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();

        vector<int>odd1,odd2;
        vector<int>even1,even2;

        for(int i=0;i<n;i++){
            if(i%2==0){
                even1.emplace_back(s1[i]);
                even2.emplace_back(s2[i]);
            }else{
                odd1.emplace_back(s1[i]);
                odd2.emplace_back(s2[i]);
            }
        }

        sort(even1.begin(),even1.end());
        sort(even2.begin(),even2.end());
        sort(odd1.begin(),odd1.end());
        sort(odd2.begin(),odd2.end());

        return odd1==odd2 && even1==even2;
    }
};