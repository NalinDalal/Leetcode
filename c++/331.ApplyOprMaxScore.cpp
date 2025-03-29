/*  2818. Apply Operations to Maximize Score
You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by
applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen
previously. Choose an element x of nums[l, ..., r] with the highest prime score.
If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and
ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors
of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.



Example 1:
Input: nums = [8,3,9,3,8], k = 2
Output: 81
Explanation: To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray.
Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score
of 1, but nums[2] has the smaller index. Hence, we multiply the score by
nums[2]. The score becomes 9 * 9 = 81. It can be proven that 81 is the highest
score one can obtain.

Example 2:
Input: nums = [19,12,14,6,10,18], k = 3
Output: 4788
Explanation: To get a score of 4788, we can apply the following operations:
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray.
Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray.
Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score
of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2].
The score becomes 342 * 14 = 4788. It can be proven that 4788 is the highest
score one can obtain.


Constraints:
1 <= nums.length == n <= 105
1 <= nums[i] <= 105
1 <= k <= min(n * (n + 1) / 2, 109)

Hint 1
Calculate nums[i]'s prime score s[i] by factoring in O(sqrt(nums[i])) time.
Hint 2
For each nums[i], find the nearest index left[i] on the left (if any) such that
s[left[i]] >= s[i]. if none is found, set left[i] to -1. Similarly, find the
nearest index right[i] on the right (if any) such that s[right[i]] > s[i]. If
none is found, set right[i] to n.

Hint 3
Use a monotonic stack to compute
right[i] and left[i].

Hint 4
For each index i, if left[i] + 1 <= l <= i <= r <=
right[i] - 1, then s[i] is the maximum value in the range [l, r]. For this
particular i, there are ranges[i] = (i - left[i]) * (right[i] - i) ranges where
index i will be chosen.

Hint 5
Loop over all elements of nums by non-increasing
prime score, each element will be chosen min(ranges[i], remainingK) times, where
reaminingK denotes the number of remaining operations. Therefore, the score will
be multiplied by s[i]^min(ranges[i],remainingK).

Hint 6
Use fast exponentiation
to quickly calculate A^B mod C.
*/

// intuition:
//  chose element x with highest prime score from b/w [l,....,r]
//  element x ka prime score-> how many prime no multiply to get that
//  element
//  improve score k times max

// approach:
// 1. Precomput prime scores
// 2. use sliding window to find optimal window [l,r]
// 3. multiply to current score and update accordingly with greedy approach
/*You can change numbers in a list called "nums" up to k times.
• Select any non-empty subarray that has not been chosen before.
• Identify the number in this subarray with the highest prime score. The prime
score of a number num is defined as the number of distinct prime factors of num.
For example, 60 has a prime score of 3 because 60 = 2 × 2 × 3 x 5, Whereas 24 =
2 × 2 × 2 x 3 has a prime score of 2. If the selected subarray contains only 60
and 24, we choose 60. If multiple numbers have the same prime score, we select
the one that appears first in the subarray. • Multiply the current score by the
chosen number. The score starts at 1 . We need to find the highest score we can
get by doing an operation up to k times and then give the answer using a special
number (10^g + 7) to keep it small. You should always use all allowed moves
because multiplying by positive numbers will only make your score better. To get
the best score, we should always pick the subarray with the biggest number,
doing this k times.
*/
#include <iostream>
#include <vector>
using namespace std;

// 1. get max(heap)
// 2.update score
// 3. use mnonotonic stack
/*can't repeat subarr
prime score of n = num of prime factors of n
the order of mult doesn't matter find prime scores: n * sqrt(n)
brute force: find max element, count subarr where it has max score, which is
O(n) total complexity: O(n^2) Preprocessing? Prefix / suffix? For each nums[i],
we want left & right boundary Left[i] = closest index on left greater than OR
EQUAL to prime[i] Right[i] = closest index on right greater than prime[i]
Monotonic decreasing?
What about tie? */
const int MOD = 1e9 + 7;

class Solution {
public:
  vector<int> primeScore;

  // Function to compute prime scores for numbers up to maxVal
  void computePrimeScores(int maxVal) {
    primeScore.assign(maxVal + 1, 0);
    for (int i = 2; i <= maxVal; i++) {
      if (primeScore[i] == 0) { // Prime number
        for (int j = i; j <= maxVal; j += i) {
          primeScore[j]++;
        }
      }
    }
  }

  long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
      if (exp % 2 == 1) { // If exponent is odd
        result = (result * base) % mod;
      }
      base = (base * base) % mod; // Square the base
      exp /= 2;
    }
    return result;
  }

  int maximumScore(vector<int>& nums, int k) {
    int n = nums.size();
    int maxNum = *max_element(nums.begin(), nums.end());
    computePrimeScores(maxNum);

    vector<int> left(n, -1), right(n, n);
    stack<int> st;

    // Compute left boundary
    for (int i = 0; i < n; i++) {
      while (!st.empty() && primeScore[nums[st.top()]] < primeScore[nums[i]]) {
        st.pop();
      }
      left[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    while (!st.empty())
      st.pop();

    // Compute right boundary
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && primeScore[nums[st.top()]] <= primeScore[nums[i]]) {
        st.pop();
      }
      right[i] = st.empty() ? n : st.top();
      st.push(i);
    }

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
      pq.emplace(nums[i], i);
    }

    long long res = 1;
    while (k > 0 && !pq.empty()) {
      auto [num, index] = pq.top();
      pq.pop();
      int score = (num <= maxNum) ? primeScore[num] : 0;
      long long leftCnt = index - (left[index] == -1 ? -1 : left[index]);
      long long rightCnt = (right[index] == n ? n : right[index]) - index;
      long long operations = min(leftCnt * rightCnt, (long long)k);
      if (operations > 0) {
        res = (res * modExp(num, operations, MOD)) % MOD;
      }
      k -= operations;
    }

    return res;
  }
};
// sub:
// https://leetcode.com/problems/apply-operations-to-maximize-score/submissions/1589868758/?envType=daily-question&envId=2025-03-29
// sol:
// https://leetcode.com/problems/apply-operations-to-maximize-score/solutions/6592141/2818-apply-operations-to-maximize-score-z3hoi/
int main() {
  Solution sol;
  vector<int> nums = {10, 15, 7, 9, 6};
  int k = 2;
  cout << sol.maximumScore(nums, k) << endl;
  return 0;
}
