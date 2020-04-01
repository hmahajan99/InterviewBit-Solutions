// What is the time complexity of the following code :

//         int j = 0;
//         for(int i = 0; i < n; ++i) {
//             while(j < n && arr[i] < arr[j]) {
//                 j++;
//             }
//         }

// Answer - O(n)
//  j is not initialized for each value of variable i.