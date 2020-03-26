// Given a non negative integer A, following code tries to find all pair of integers (a, b) such that

// a and b are positive integers
// a <= b, and
// a^2 + b^2 = A.
// 0 <= A <= 100000

vector<vector<int> > Solution::squareSum(int A) {
    vector<vector<int> > ans;
    for (int a = 0; a * a < A; a++) {
        for (int b = a; b * b < A; b++) {
            if (a * a + b * b == A) {
                vector<int> newEntry; 
                newEntry.push_back(a);
                newEntry.push_back(b);
                ans.push_back(newEntry);
            }
        }
    }
    return ans;
}
