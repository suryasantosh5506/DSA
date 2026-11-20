class Solution {
public:

    bool isvowel(char &ch){
        unordered_set<char>vowels={'a','e','i','o','u'};
        return vowels.count(ch);
    }

    int solution(string word, int k){
        unordered_map<char,int>vowels={
            {'a',-1},
            {'e',-1},
            {'i',-1},
            {'o',-1},
            {'u',-1},
        };
        int consonants=0;
        int i=0,j=0;
        int n=word.size();
        int ans=0;
        while(j<n){
            if(isvowel(word[j])) vowels[word[j]]=j;
            else consonants++;

            while(consonants>k){
                if(!isvowel(word[i])){
                    consonants--;
                }
                i++;
            }
            int mini=INT_MAX;
            for(auto it:vowels) mini=min(mini,it.second);
            if(mini>=i) ans+=mini-i+1;
            j++;
        }
        return ans;
    }

    int countOfSubstrings(string word, int k) {
        return solution(word,k)-solution(word,k-1);
    }
};