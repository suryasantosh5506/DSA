#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
        return (a==2 || b==2) && (a==1 || b==1 || a==3 || b==3);
    }
};