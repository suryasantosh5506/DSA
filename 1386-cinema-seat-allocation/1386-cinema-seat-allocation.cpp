class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=2*n;
        unordered_map<int,set<int>>mpp;

        for(auto it:reservedSeats){
            mpp[it[0]].insert(it[1]);
        }

        for(auto it:mpp){
            bool left=true;
            for(int k=2;k<=5;k++){
                if(it.second.count(k)){
                    left=false;
                    break;
                }
            }

            bool middle=true;
            for(int k=4;k<=7;k++){
                if(it.second.count(k)){
                    middle=false;
                    break;
                }
            }

            bool right=true;
            for(int k=6;k<=9;k++){
                if(it.second.count(k)){
                    right=false;
                    break;
                }
            }

            if(left && right);
            else if(left || right) ans-=1;
            else if(middle) ans-=1;
            else ans-=2;
        }
        return ans;
    }
};