class Solution {
public:
    vector<int> sieve;

    void findPrimes() {
        int n = sieve.size();
        sieve[0] = sieve[1] = -1;

        for (int i = 2; i < n; i++){
            sieve[i] = i;
        }

        for (int i = 2; i * i < n; i++) {
            if (sieve[i] == i) {
                for (int j = i * i; j < n; j += i) {
                    sieve[j] = i;
                }
            }
        }
    }

    bool isPrime(int n) { return n > 1 && sieve[n] == n; }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        sieve.resize(maxi + 1);
        findPrimes();

        queue<vector<int>> q;
        vector<int> visited(n, 0);

        // storing indices of numsbers divisible by nums[i] if nums[i] is prime
        unordered_map<int, vector<int>> mpp;

        // prime -> indices divisible by that prime
        for (int i = 0; i < n; i++) {

            int x = nums[i];

            unordered_set<int> factors;

            while (x > 1) {

                int p = sieve[x];
                mpp[p].emplace_back(i);
                x /= p;
            }
        }

        q.push({0, 0});
        // {index,steps};
        visited[0] = 1;

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            int i = top[0];
            int steps = top[1];

            if (i == n - 1)
                return steps;

            if (i - 1 >= 0 && !visited[i - 1]) {
                q.push({i - 1, steps + 1});
                visited[i - 1] = 1;
            }

            if (i + 1 < n && !visited[i + 1]) {
                q.push({i + 1, steps + 1});
                visited[i + 1] = 1;
            }

            if (isPrime(nums[i])) {
                for (auto x : mpp[nums[i]]) {
                    if (!visited[x]) {
                        q.push({x, steps + 1});
                        visited[x] = 1;
                    }
                }
                mpp[nums[i]].clear();
            }
        }
        return -1;
    }
};