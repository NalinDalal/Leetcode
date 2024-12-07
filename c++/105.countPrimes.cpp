/* 204. Count Primes

Given an integer n, return the number of prime numbers that are strictly less
than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0


Constraints:
0 <= n <= 5 * 10^6 */

#include <iostream>
#include <vector>

using namespace std;

// What to do:
// 1. Well we can iterate from i =2 to n/2 and check if i is prime or not.
// 2. but new optimisation is that wcan check till i*i<=n; this reduces the time
// compexity fron o(n) to O(sqrt(n))
class Solution {
public:
  int countPrimes(int n) {
    if (n <= 2)
      return 0; // No primes below 2
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
      if (isPrime[i]) {
        for (int j = i * i; j <= n; j += i) {
          isPrime[j] = false;
        }
      }
    }
    int count = 0;
    for (int i = 2; i <= n; i++) {
      if (isPrime[i]) {
        ++count;
      }
    }
    return count;
  }
};

/*
more optimisation:
1. Stop Iteration Early in Inner Loop:Begin marking multiples from i×i and only
go up to n. This avoids redundant iterations for small primes. 2.Skip Even
Numbers Beyond 2:Numbers like 4, 6, 8, etc., are already marked as non-prime
when processing i=2. We can skip even numbers entirely by iterating over odd
numbers. 3.Process Only Odd Numbers: Maintain a smaller sieve size by storing
information for odd numbers only, halving the memory and iteration cost.
*/

class Solution2 {
public:
  int countPrimes(int n) {
    if (n <= 2)
      return 0; // Edge case: No primes less than 2

    // Step 1: Use a smaller sieve, only for odd numbers
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    // Step 2: Apply the optimized Sieve of Eratosthenes
    for (int i = 2; i * i < n; i++) {
      if (isPrime[i]) {
        // Start marking multiples from i * i
        for (int j = i * i; j < n; j += i) {
          isPrime[j] = false;
        }
      }
    }

    // Step 3: Count primes
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (isPrime[i])
        ++count;
    }
    return count;
  }
};

// further optimisation:
// consider only odd numbers
class Solution3 {
public:
  int countPrimes(int n) {
    if (n <= 2)
      return 0; // No primes less than 2

    // Use a sieve for odd numbers only
    vector<bool> isPrime((n + 1) / 2, true); // True for odd numbers
    isPrime[0] = false;                      // 1 is not prime

    // Iterate over odd numbers starting from 3
    for (int i = 3; i * i < n; i += 2) {
      if (isPrime[i / 2]) {
        // Mark multiples of i (starting from i * i)
        for (int j = i * i; j < n; j += 2 * i) {
          isPrime[j / 2] = false;
        }
      }
    }

    // Count primes
    int count = 1; // Include 2 as prime
    for (int i = 3; i < n; i += 2) {
      if (isPrime[i / 2])
        ++count;
    }
    return count;
  }
};

int main() {
  int n1 = 10, n2 = 0, n3 = 1;
  Solution3 obj;
  cout << "n1= " << n1 << " " << obj.countPrimes(n1) << endl;
  cout << "n2= " << n2 << " " << obj.countPrimes(n2) << endl;
  cout << "n3= " << n3 << " " << obj.countPrimes(n3) << endl;
  return 0;
}
