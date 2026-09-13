class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n=plants.size();
        int refill=0;
        int alice=capacityA,bob=capacityB;
        int i=0,j=n-1;
        while(i<=j){
            if(i==j){
                if(alice<plants[i] && bob<plants[i]){
                    refill++;
                }
                i++;
                j--;
                break;
            }
            if(alice<plants[i]){
                refill++;
                alice=capacityA;
            }
            if(bob<plants[j]){
                refill++;
                bob=capacityB;
            }

            alice-=plants[i];
            i++;
            bob-=plants[j];
            j--;
        }
        return refill;
    }
};