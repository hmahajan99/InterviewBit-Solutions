// Consider the following for loops:
//   A) for(i = 0; i < n; i++) - O(n)
//   B) for(i = 0; i < n; i += 2) - O(n/2)
//   C) for(i = 1; i < n; i *= 2) - Answer - O(logn)
//   D) for(i = n; i > -1; i /= 2) - Infinite Loop
// If n is the size of input(positive), which function is the most efficient? In other words, which loop completes the fastest.