/*
69. Sqrt(x)

Given a non-negative integer x, return the square root of x rounded down to the
nearest integer. The returned integer should be non-negative as well. You must
not use any built-in exponent function or operator. For example, do not use
pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to
the nearest integer, 2 is returned.

Constraints:
0 <= x <= 2^31 - 1
*/

// What can we do:
/*
we can't use x raised to power of 0.5
constraints requirement

note: to round off, use GIF function
-> double x = 3.14;
    int greatestInteger = floor(x);

This is a very simple method. We subtract the consecutive odd numbers
from the number for which we are finding the square root, till
we reach 0. The number of times we subtract is the square root of the
given number. This method works only for perfect square numbers.

4-> 4-1=3
    3-3=0
Ans=2

8-> 8-1=7
    7-3=4
    4-5=-1
Ans=2

14-> 14-1=13
    13-3=10
    10-5=5
    5-6=-1
Ans=3.8 something
GIF=3
Ans=3
*/

// Attempt 1:
/*
class Solution {
public:
    int mySqrt(int x) {
        for (int i = 0; i < x / 2; i++) {
            if (pow(i,2) > x) {
                return i - 1;
            }
        }
        return -1;
    }
};
*/
// Problem: fucked up for perfect squares

// Attempt 2:
/*
find the square of numbers from 1 to N, till the square of some number K becomes
greater than N. Hence the value of (K – 1) will be the floor square root of N.
algorithm:
- Iterate a loop from numbers 1 to N in K.
- For any K, if its square becomes greater than N, then K-1 is the floor square
root of N.

time complexity: O(n)
*/

// Overflow code
// Problem: integer overflow

/*
class Solution {
public:
  int mySqrt(int N) {
    int K = 1; // Start from K = 1

    // Iterate until K^2 is greater than N
    while (K * K <= N) {
      K++; // Increment K
    }

    // Return the floor square root, which is K - 1
    return K - 1;
  }
};
*/

// Solved: cast the multiplication result to a larger data type (like long long
// int)
// gptied only for this thing, for type casting
class Solution {
public:
  int mySqrt(int N) {
    int K = 1; // Start from K = 1

    // Iterate until K^2 is greater than N
    while ((long long)K * K <= N) { // Cast to long long to prevent overflow
      K++;                          // Increment K
    }

    // Return the floor square root, which is K - 1
    return K - 1;
  }
};

// Time complexity:O(n)
// Space complexity:O(1)
