// Given a sorted array of integers, find the number of occurrences of a given target value.
// If the target is not found in the array, return 0

int Solution::findCount(const vector<int> &A, int B) {
    return upper_bound(A.begin(),A.end(),B)-lower_bound(A.begin(),A.end(),B);
}
