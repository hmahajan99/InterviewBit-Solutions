// What is the worst case time complexity of the following code :

// /* 
//  * V is sorted 
//  * V.size() = N
//  * The function is initially called as searchNumOccurrence(V, k, 0, N-1)
//  */
// int searchNumOccurrence(vector<int> &V, int k, int start, int end) {
//     if (start > end) return 0;
//     int mid = (start + end) / 2;
//     if (V[mid] < k) return searchNumOccurrence(V, k, mid + 1, end);
//     if (V[mid] > k) return searchNumOccurrence(V, k, start, mid - 1);
//     return searchNumOccurrence(V, k, start, mid - 1) + 1 + searchNumOccurrence(V, k, mid + 1, end);
// }

// Answer - O(n)
// T(N) = 2 * T(N/2) + constant
// = 4 * T(N/4) + constant ( 2 * constant = another constant )
// = 8 * T(N/8) + constant
// …
// = N * T(N/N) + constant
// = N + constant
// = O(N)