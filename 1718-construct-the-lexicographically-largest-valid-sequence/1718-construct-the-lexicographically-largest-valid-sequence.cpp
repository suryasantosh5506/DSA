class Solution {
public:

    vector<int>ans;
    vector<bool>placed;
    int n;

    bool solution(int i){
        int size=2*n-1;
        while(i<size && ans[i]!=0) i++;
        if(i==size){
            return true;
        }

        for(int num=n;num>=1;num--){
            if(placed[num-1]) continue;
            if(num==1 && ans[i]==0){
                ans[i]=num;
                placed[num-1]=true;
                if(solution(i+1)) return true;
                ans[i]=0;
                placed[num-1]=false;
            }else{
                if(!(ans[i]==0 && i+num<size && ans[i+num]==0)) continue;
                ans[i]=ans[i+num]=num;
                placed[num-1]=true;
                if(solution(i+1)) return true;
                ans[i]=ans[i+num]=0;
                placed[num-1]=false;
            }
        }
        return false;
    }


    vector<int> constructDistancedSequence(int n) {
        this->n=n;
        ans.assign(2*n-1,0);
        placed.assign(2*n-1,false);
        solution(0);
        return ans;
    }
};