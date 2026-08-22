class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>>ans;
        set<vector<int>>st(queens.begin(),queens.end());

        // left
        for(int i=king[1]-1;i>=0;i--){
            vector<int>coor={king[0],i};
            if(st.count(coor)){
                ans.emplace_back(coor);
                break;
            }
        }

        // right
        for(int i=king[1]+1;i<8;i++){
            vector<int>coor={king[0],i};
            if(st.count(coor)){
                ans.emplace_back(coor);
                break;
            }
        }

        // bottom
        for(int i=king[0]-1;i>=0;i--){
            vector<int>coor={i,king[1]};
            if(st.count(coor)){
                ans.emplace_back(coor);
                break;
            }
        }

        // top
        for(int i=king[0]+1;i<8;i++){
            vector<int>coor={i,king[1]};
            if(st.count(coor)){
                ans.emplace_back(coor);
                break;
            }
        }

        // upper-left diagonal
        int i=king[0]-1,j=king[1]-1;
        while(i>=0 && j>=0){
            vector<int>coor={i,j};
            if(st.count(coor)){
                ans.emplace_back(coor);
                break;
            }
            i--;
            j--;
        }

        // upper-right diagonal
        i=king[0],j=king[1];
        while(i>=0 && j<8){
            vector<int>coor={i,j};
            if(st.count(coor)){
                ans.emplace_back(coor);
                break;
            }
            i--;
            j++;
        }

        // lower-left diagonal
        i=king[0],j=king[1];
        while(i<8 && j>=0){
            vector<int>coor={i,j};
            if(st.count(coor)){
                ans.emplace_back(coor);
                break;
            }
            i++;
            j--;
        }

        // lower-right diagonal
        i=king[0],j=king[1];
        while(i<8 && j<8){
            vector<int>coor={i,j};
            if(st.count(coor)){
                ans.emplace_back(coor);
                break;
            }
            i++;
            j++;
        }
        return ans;
    }
};