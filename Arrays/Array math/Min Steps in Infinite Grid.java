public class Solution {
    public int coverPoints(ArrayList<Integer> x, ArrayList<Integer> y) {
        int ans=0;
        for(int i=0;i<x.size()-1;i++){
            int xdiff = Math.abs(x.get(i)-x.get(i+1));
            int ydiff = Math.abs(y.get(i)-y.get(i+1));
            ans += Math.max(xdiff,ydiff);
        }
        return ans;
    }
}
