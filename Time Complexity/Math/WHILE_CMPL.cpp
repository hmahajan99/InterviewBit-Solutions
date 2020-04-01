// What is the time complexity of the following code :

//         int a = 0, i = N;
//         while (i > 0) {
//             a += i;
//             i /= 2;
//         }

// Answer - O(log N)
// Notice that in every iteration, i goes to i / 2
// So, after x iterations, i will be N / 2^x
// We have to find first x such that N / 2^x < 1 OR 2^x > N