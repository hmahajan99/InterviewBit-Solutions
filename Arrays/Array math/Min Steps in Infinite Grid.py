class Solution:
	# @param x : list of integers
	# @param y : list of integers
	# @return an integer
	def coverPoints(self, x, y):
        ans=0
        for i in range(len(x)-1):
            xdiff = abs(x[i]-x[i+1]);
            ydiff = abs(y[i]-y[i+1]);
            ans += max(xdiff,ydiff);
        return ans;


