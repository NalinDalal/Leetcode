/* 202. Happy Number

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares
of its digits. Repeat the process until the number equals 1 (where it will
stay), or it loops endlessly in a cycle which does not include 1. Those numbers
for which this process ends in 1 are happy. Return true if n is a happy number,
and false if not.


Example 1:
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1


Example 2:
Input: n = 2
Output: false


Constraints:

1 <= n <= 2^31 - 1 */

#include <iostream>

class Solution {
public:
  bool isHappy(int n) {
    if (n == 1 || n == 0)
      return true;
    int sum = 0;
    while (n != 1) {
      sum = 0;
      while (n != 0) {
        sum += n % 10 * n % 10;
        n /= 10;
      }
      n = sum;
    }
    return n == 1;
  }
};

// problem1: infinite loop for number which is not happy
// problem2: infinite cycle detected

// Solution
// 1. Happy numbers eventually reach 1 if you repeatedly replace the number with
// the sum of squares of its digits.
// 2. Non-happy numbers get stuck in a cycle that doesn't include 1. Detecting
// such a cycle helps terminate the process.

class Solution1 {
public:
  bool isHappy(int n) {
    // Helper function to calculate sum of squares of digits
    auto getSumOfSquares = [](int num) {
      int sum = 0;
      while (num > 0) {
        int digit = num % 10;
        sum += digit * digit;
        num /= 10;
      }
      return sum;
    };

    int slow = n, fast = n;
    do {
      slow = getSumOfSquares(slow); // Move slow pointer one step
      fast =
          getSumOfSquares(getSumOfSquares(fast)); // Move fast pointer two steps
    } while (slow != fast);

    // If we reached 1, it is a happy number
    return slow == 1;
  }
};

using namespace std;

int main() {
  Solution1 sol1;
  cout << "19" << sol1.isHappy(19) << endl;
  cout << "2" << sol1.isHappy(2) << endl;
  return 0;
}
