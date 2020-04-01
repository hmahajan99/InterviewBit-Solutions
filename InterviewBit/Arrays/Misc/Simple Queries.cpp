// You are given an array A having N integers.
// You have to perform the following steps in a given order.
// generate all subarrays of A.
// take the maximum element from each subarray of A and insert it into a new array G.
// replace every element of G with the product of their divisors mod 1e9 + 7.
// sort G in descending order
// perform Q queries
// In each query, you are given an integer K, where you have to find the Kth element in G.

// Approach: 
// TODO ONCE CLEARLY

// Product of divisors of a number can be written as N^(D/2), where N is number and D is number of divisors of N.
// We can solve this problem by doing the binary search for each query.
// First, you need to find that how many times an element will appear in array G. i.e in how many subarrays an element is the greatest one.
// You can find that by finding the next greater element for the current element in both sides and then by multiplying them.
// Once you found the frequency of each element in an array G, you can sort the pairs(product_of_divisors_of_element, frequency) according to there value in descending order followed by taking the prefix sum of there frequencies you can do the binary search for each query.

#define ll long long int
const int mn = 1e5 + 5;
const ll mod = 1e9 + 7;
ll power(ll a, ll g) {ll ag = 1; while(g){if(g&1) ag = (ag%mod * a%mod)%mod; a = (a%mod * a%mod)%mod; g >>= 1;} return ag;}

ll p[mn]; // p[i] = product of divisors of i

void pre_compute_product_of_divisors() {
    p[0] = 0; p[1] = 1;
    if(p[2] != 0) return;
    for(ll i = 2; i < mn; i += 1) {
        if(p[i] == 0) {
            p[i] = 2;
            for(ll j = i+i; j < mn; j += i) {
                if(p[j] == 0) p[j] = 1;
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    cnt += 1;
                    tmp /= i;
                }
                p[j] *= (cnt + 1);
            }
        }
    }
    for(int i = 2; i < mn; i += 1) {
        p[i] = (power(i, p[i]/2)%mod * (p[i]&1 ? (ll)sqrt(i) : 1)%mod)%mod; // N^(D/2)
    }
}

// comparator to sort in descending order
bool compare(pair<int, long long int> a, pair<int, long long int> b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    
    pre_compute_product_of_divisors();
    
    int n = (int)A.size();
    // create arrays to store length of longest segment in which ith element is greater
    long long int l[n], r[n], lr[n];
    // initialize elements array equal to 1.
    for(int i = 0; i < n; i += 1) {
        l[i] = r[i] = 1;
    }
    // find next greater element to the left of the current element (similar to approach using stack)
    // l[i] = num of subarrays ending at i in which A[i] is max
    for(int i = 1; i < n; i += 1) {
        int last = i-1;
        while(last >= 0 and A[i] > A[last]) { // to handle duplicates >
            l[i] += l[last];
            last -= l[last];
        }
    }
    // find next greater element to the right of the current element (similar to approach using stack)
    // r[i] = num of subarrays starting at i in which A[i] is max
    for(int i = n-2; i >= 0; i -= 1) {
        int last = i+1;
        while(last < n and A[i] >= A[last]) { // to handle duplicates >=
            r[i] += r[last];
            last += r[last];
        }
    }
    // The number of subarrays in which current element will be the greater
    for(int i = 0; i < n; i += 1) {
        lr[i] = l[i] * r[i];
    }
    // Sort elements in descending order according to there value
    pair<int, long long int> ag[n];
    for(int i = 0; i < n; i += 1) {
        ag[i] = {p[A[i]], lr[i]};
    }
    sort(ag,ag+n,compare);

    // Take Prefix Sum of frequencies of elements
    long long pre[n];
    pre[0] = ag[0].second;
    for(int i = 1; i < n; i += 1) {
        pre[i] = pre[i-1] + ag[i].second;
    }
    
    // do Binary search for each query
    int q = (int)B.size();
    vector<int> ans(q);
    for(int i = 0; i < q; i += 1) {
        auto id = lower_bound(pre,pre+n,B[i])-pre;
        ans[i] = ag[id].first;
    }
    // return the ans array
    return ans;
}