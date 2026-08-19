class AuthenticationManager {
public:

    int time=1;
    int lifetime=0;
    unordered_map<string,int>tokens;

    AuthenticationManager(int timeToLive) {
        this->lifetime=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId]=currentTime+lifetime;
    }
    
    void renew(string tokenId, int currentTime) {
        if(!tokens.count(tokenId)) return;
        if(tokens[tokenId]<=currentTime){
            tokens.erase(tokenId);
            return;
        }
        int newtime=currentTime+lifetime;
        tokens[tokenId]=newtime;
    }
    
    int countUnexpiredTokens(int currentTime) {
        int ans=0;
        for(auto it:tokens){
            if(it.second>currentTime) ans++;
        }
        return ans;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */