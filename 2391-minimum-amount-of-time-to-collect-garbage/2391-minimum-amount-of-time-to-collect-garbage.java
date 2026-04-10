class Solution {
    public int garbageCollection(String[] garbage, int[] travel) {
        int papertime=0;
        int garbagetime=0;
        int metaltime=0;

        int lastg=0,lastp=0,lastm=0;

        int n = garbage.length;

        for(int i=0;i<n;i++){
            for(char x:garbage[i].toCharArray()){
                if(x=='P'){
                    papertime++;
                    lastp=i;
                }
                if(x=='M'){
                    metaltime++;
                    lastm=i;
                }
                if(x=='G'){
                    garbagetime++;
                    lastg=i;
                }
            }
        }

        for (int i = 0; i < lastp; i++) papertime += travel[i];
        for (int i = 0; i < lastg; i++) garbagetime += travel[i];
        for (int i = 0; i < lastm; i++) metaltime += travel[i];

        return papertime+garbagetime+metaltime;
    }
}