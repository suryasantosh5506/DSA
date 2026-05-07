class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1=a.size(),n2=b.size();
        int n=n1+n2;
        int cnt=0;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(a[i]<=b[j]){
                if(cnt==k-1) return a[i];
                i++;
            }else{
                if(cnt==k-1) return b[j];
                j++;
            }
            cnt++;
        }
        
        while(i<n1){
            if(cnt==k-1) return a[i];
            i++;
            cnt++;
        }
        
        while(j<n2){
            if(cnt==k-1) return b[j];
            j++;
            cnt++;
        }
        return -1;
    }
};