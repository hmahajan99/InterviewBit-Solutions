// What is the time complexity of the following code :

//     int i, j, k = 0;
//     for (i  = n/2; i <= n; i++) {
//         for (j = 2; j <= n; j = j * 2) {
//             k = k + n/2;
//         }
//     }

// Answer - Θ(nLogn)
// If you notice, j keeps doubling till it is less than or equal to n. Number of times, you can double a number till it is less than n would be log(n). 
// So, j would run for O(log n) steps. 
// i runs for n/2 steps. 
// So, total steps ` = O (n/ 2 * log (n)) = O(n logn) `