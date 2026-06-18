class Solution {
    public double angleClock(int hour, int minutes) {
        double angle=Math.abs(30* hour-(11/2.0)*minutes);
        return (angle>180)?360-angle:angle;
    }
}