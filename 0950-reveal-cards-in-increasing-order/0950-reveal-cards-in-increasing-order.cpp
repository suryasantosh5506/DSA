class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int>ans(n);
        queue<int>q;
        for(int i=0;i<n;i++) q.push(i);
        int i=0;

        while(!q.empty()){
            int pos=q.front();
            q.pop();

            ans[pos]=deck[i++];
            if(!q.empty()){
                int p=q.front();
                q.pop();
                q.push(p);
            }
        }
        return ans;
    }
};