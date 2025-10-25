/*1716. Calculate Money in Leetcode Bank
Hercy wants to save money for his first car. He puts money in the Leetcode bank
every day.

He starts by putting in $1 on Monday, the first day. Every day from Tuesday to
Sunday, he will put in $1 more than the day before. On every subsequent Monday,
he will put in $1 more than the previous Monday.

Given n, return the total amount of money he will have in the Leetcode bank at
the end of the nth day.



Example 1:
Input: n = 4
Output: 10
Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.

Example 2:
Input: n = 10
Output: 37
Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 +
3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.

Example 3:
Input: n = 20
Output: 96
Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 +
3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.


Constraints:
1 <= n <= 1000

Hint 1
Simulate the process by keeping track of how much money Hercy is putting in and
which day of the week it is, and use this information to deduce how much money
Hercy will put in the next day.
*/

/*so the money gets acquired like this simulation
week-1: 1 2 3 4 5 6 7
week-2: 2 3 4 5 6 7 8
week-3: 3 4 5 6 7 8 9

goes like that,
given n find total money acquired

divide n by 7, u get n/7 no of weeks required
*/
class Solution {
public:
  int totalMoney(int n) {
    long long weeks = n / 7;
    int rem = n % 7;

    // Sum of full weeks: sum_{i=1..weeks} (7*i + 21)
    // = 7 * (weeks*(weeks+1)/2) + 21*weeks
    long long total = 7 * (weeks * (weeks + 1) / 2) + 21 * weeks;

    // Remaining days: starting at (weeks + 1),
    // sum = rem*(weeks+1) + rem*(rem-1)/2
    total += 1LL * rem * (weeks + 1) + 1LL * rem * (rem - 1) / 2;

    return (int)total;
  }
};
// sub:
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/submissions/1811535052/?envType=daily-question&envId=2025-10-25
// sol:
// https://leetcode.com/problems/calculate-money-in-leetcode-bank/solutions/7300975/1716-calculate-money-in-leetcode-bank-by-ipit/
