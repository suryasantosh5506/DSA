class Solution {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        long m=mass;
        Arrays.sort(asteroids);
        for(int x:asteroids){
            if(x>m) return false;
            m+=x;
        }
        return true;
    }
}