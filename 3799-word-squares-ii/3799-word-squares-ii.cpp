class Solution {
public:

    int n;
    vector<string>seq;
    vector<vector<string>>ans;
    vector<bool>used;

    void solution(int ind,vector<string>&words){
        if(ind==4){
            ans.emplace_back(seq);
            return;
        }

        for(int i=0;i<n;i++){
            if(used[i]) continue;
            if(ind==0){
                used[i]=true;
                seq.emplace_back(words[i]);
                solution(ind+1,words);
                seq.pop_back();
                used[i]=false;
            }
            if(ind==1){
                if(words[i][0]==seq[0][0]){
                    used[i]=true;
                    seq.emplace_back(words[i]);
                    solution(ind+1,words);
                    seq.pop_back();
                    used[i]=false;
                }
            }
            if(ind==2){
                if(words[i][0]==seq[0][3]){
                    used[i]=true;
                    seq.emplace_back(words[i]);
                    solution(ind+1,words);
                    seq.pop_back();
                    used[i]=false;
                }
            }
            if(ind==3){
                if(words[i][0]==seq[1][3] && words[i][3]==seq[2][3]){
                    used[i]=true;
                    seq.emplace_back(words[i]);
                    solution(ind+1,words);
                    seq.pop_back();
                    used[i]=false;
                }
            }
        }

        return;
    }

    vector<vector<string>> wordSquares(vector<string>& words) {
        sort(words.begin(),words.end());
        n=words.size();
        used.resize(n,false);
        solution(0,words);
        return ans;
    }
};