// problem link:- https://leetcode.com/problems/first-matching-character-from-both-ends/description/
    
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMatchingIndex(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==s[n-i-1]) return i;
        }
        return -1;
    }
};