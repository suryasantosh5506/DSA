
void build(int segindex,int low,int high,int arr[],int segmentTree[]){
    if(low==high){
        segmentTree[segindex]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(2*segindex+1,low,mid,arr,segmentTree);
    build(2*segindex+2,mid+1,high,arr,segmentTree);
    
    segmentTree[segindex]=min(segmentTree[2*segindex+1],segmentTree[2*segindex+2]);
}

/* The functions which
builds the segment tree */
int *constructST(int arr[], int n) {
    // Your code here
    int *segmentTree=new int[4*n+1];
    build(0,0,n-1,arr,segmentTree);
    return segmentTree;
}

/* The functions returns the
 min element in the range
 from a and b */
 
int query(int segindex,int low,int high,int l,int r,int segmentTree[]){
    if(r<low || high<l) return INT_MAX;
    if(l<=low && high<=r) return segmentTree[segindex];
    int mid=(low+high)/2;
    int left=query(2*segindex+1,low,mid,l,r,segmentTree);
    int right=query(2*segindex+2,mid+1,high,l,r,segmentTree);
    return min(left,right);
}
 
int RMQ(int st[], int n, int a, int b) {
    return query(0,0,n-1,a,b,st);
    // Your code here
}