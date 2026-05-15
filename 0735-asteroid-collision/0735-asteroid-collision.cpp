class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(auto x:asteroids){
            if(x>0) st.emplace_back(x);
            else{
                while(!st.empty() && st.back()>0 && abs(x)>st.back()) st.pop_back();
                if(!st.empty() && abs(x)==st.back()) st.pop_back();
                else if(st.empty() || st.back()<0) st.emplace_back(x);
            }
        }
        return st;
    }
};