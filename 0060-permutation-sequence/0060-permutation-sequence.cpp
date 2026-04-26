class Solution {
public:

    bool solution(string &nums,string &permutation,int &k,unordered_map<char,bool>&used){
        if(permutation.size()==nums.size()){
            k--;
            if(k==0) return true;
            return false;
        }

        for(auto x:nums){
            if(used[x]) continue;
            used[x]=true;
            permutation+=x;
            if(solution(nums,permutation,k,used)) return true;
            used[x]=false;
            permutation.pop_back();
        }
        return false;
    }

    string getPermutation(int n, int k) {
        string nums(n,'.');
        for(int i=0;i<n;i++){
            nums[i]=(i+1)+'0';
        }
        unordered_map<char,bool>used;
        string ans="";
        solution(nums,ans,k,used);
        return ans;
    }
};