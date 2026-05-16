class Solution {
  public:
    void insertAtIndex(vector<int> &arr, int index, int val) {
        // code here
        int n=arr.size();
        
        int next=INT_MIN;
        for(int i=0;i<n;i++){
            if(i==index){
                next=arr[i];
                arr[i]=val;
            }else if(next!=INT_MIN){
                int val=arr[i];
                arr[i]=next;
                next=val;
            }
        }
        arr.emplace_back((next==INT_MIN)?val:next);
    }
};
