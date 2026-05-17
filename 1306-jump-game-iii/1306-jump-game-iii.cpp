class Solution {
public:

    int n;
    vector<int>visited;

    bool solution(int i,vector<int>&arr){
        if(i<0 || i>=n) return false;
        if(arr[i]==0) return true;
        if(visited[i]) return false;

        visited[i]=1;
        bool left=false,right=false;
        if(i+arr[i]<n) right=solution(i+arr[i],arr);
        if(i-arr[i]>=0) left=solution(i-arr[i],arr);

        return left||right;
    }

    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        visited.assign(n,0);
        return solution(start,arr);
    }
};