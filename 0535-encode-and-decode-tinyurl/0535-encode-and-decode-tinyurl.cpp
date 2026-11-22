class Solution {
public:

    unordered_map<string,string>shorttolong;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tiny="http://tinyurl.com"+to_string(shorttolong.size());
        shorttolong[tiny]=longUrl;
        return tiny;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return shorttolong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));