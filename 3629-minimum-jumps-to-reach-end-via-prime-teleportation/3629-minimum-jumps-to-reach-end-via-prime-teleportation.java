class Solution {

    int[] sieve;

    void findPrimes() {

        int n = sieve.length;

        sieve[0] = sieve[1] = -1;

        for(int i = 2; i < n; i++){
            sieve[i] = i;
        }

        for(int i = 2; i * i < n; i++){

            if(sieve[i] == i){

                for(int j = i * i; j < n; j += i){

                    sieve[j] = i;
                }
            }
        }
    }

    boolean isPrime(int n){

        return n > 1 && sieve[n] == n;
    }

    public int minJumps(int[] nums) {

        int n = nums.length;

        int maxi = 0;

        for(int x : nums){
            maxi = Math.max(maxi, x);
        }

        sieve = new int[maxi + 1];

        findPrimes();

        Queue<int[]> q = new LinkedList<>();

        boolean[] visited = new boolean[n];

        // prime -> indices divisible by that prime
        HashMap<Integer, ArrayList<Integer>> mpp =
                new HashMap<>();

        for(int i = 0; i < n; i++){

            int x = nums[i];

            HashSet<Integer> factors = new HashSet<>();

            while(x > 1){

                int p = sieve[x];

                factors.add(p);

                x /= p;
            }

            for(int p : factors){

                mpp.putIfAbsent(p,
                        new ArrayList<>());

                mpp.get(p).add(i);
            }
        }

        q.offer(new int[]{0, 0});

        visited[0] = true;

        while(!q.isEmpty()){

            int[] top = q.poll();

            int i = top[0];

            int steps = top[1];

            if(i == n - 1)
                return steps;

            // left
            if(i - 1 >= 0 && !visited[i - 1]){

                visited[i - 1] = true;

                q.offer(new int[]{i - 1, steps + 1});
            }

            // right
            if(i + 1 < n && !visited[i + 1]){

                visited[i + 1] = true;

                q.offer(new int[]{i + 1, steps + 1});
            }

            // prime jumps
            if(isPrime(nums[i])){

                if(mpp.containsKey(nums[i])){

                    for(int idx : mpp.get(nums[i])){

                        if(!visited[idx]){

                            visited[idx] = true;

                            q.offer(new int[]{idx,
                                    steps + 1});
                        }
                    }

                    mpp.get(nums[i]).clear();
                }
            }
        }

        return -1;
    }
}