class SGTree{
public:
    vector<int>segmentTree;
    SGTree(int n){
        segmentTree.resize(4*n+1);
    }

    void build(int segmentIndex,int low,int high,vector<int>&arr){
        if(low==high){
            segmentTree[segmentIndex]=arr[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(2*segmentIndex+1,low,mid,arr);
        build(2*segmentIndex+2,mid+1,high,arr);;
        segmentTree[segmentIndex]=segmentTree[2*segmentIndex+1]+segmentTree[2*segmentIndex+2];
    }

    int query(int segmentIndex,int low,int high,int l,int r,vector<int>&arr){
        if(r<low ||high<l) return 0;
        if(l<=low && high<=r) return segmentTree[segmentIndex];
        int mid=low+(high-low)/2;
        return query(2*segmentIndex+1,low,mid,l,r,arr)+query(2*segmentIndex+2,mid+1,high,l,r,arr);
    }
};

class NumArray {
public:
    SGTree *segmentTree;
    vector<int>arr;
    int n;

    NumArray(vector<int>& nums) {
        n=nums.size();
        arr=nums;
        segmentTree=new SGTree(n);
        segmentTree->build(0,0,n-1,arr);
    }
    
    int sumRange(int left, int right) {
        return segmentTree->query(0,0,n-1,left,right,arr);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */