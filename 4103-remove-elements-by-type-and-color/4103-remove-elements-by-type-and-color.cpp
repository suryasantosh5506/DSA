class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<vector<int>>st;
        // {type,color,cnt}
        int n=types.size();
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()[0]==types[i] && st.top()[1]==colors[i]) st.top()[2]++;
            else st.push({types[i],colors[i],1});
            int size=groupSize[types[i]];
            if(st.top()[2]==size) st.pop();
        }
        return st.empty();
    }
};