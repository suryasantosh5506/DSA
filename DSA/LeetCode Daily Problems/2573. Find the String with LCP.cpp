// problem link:- https://leetcode.com/problems/find-the-string-with-lcp/description/?envType=daily-question&envId=2026-03-28

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        string s(n, '#');
        char curChar = 'a';

        for (int i = 0; i < n; i++) {
            if (s[i] != '#')
                continue;

            if (curChar > 'z')
                return "";

            for (int j = i; j < n; j++) {
                if (lcp[i][j] > 0) {
                    s[j] = curChar;
                }
            }
            curChar++;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int current_lcp = 0;
                if (s[i] == s[j]) {
                    current_lcp =
                        (i + 1 < n && j + 1 < n) ? 1 + lcp[i + 1][j + 1] : 1;
                }

                if (lcp[i][j] != current_lcp)
                    return "";
            }
        }

        return s;
    }
};