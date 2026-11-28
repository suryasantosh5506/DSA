class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int maxi=0;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            for(char &ch:words[i]){
                arr[i]|=(1<<(ch-'a'));
            }
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((arr[i]&arr[j])==0) 
                    maxi=max(maxi,(int)(words[i].size()*words[j].size()));
            }
        }
        return maxi;
    }
};