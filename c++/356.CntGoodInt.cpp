/* 3272. Find the Count of Good Integers
You are given two positive integers n and k.

An integer x is called k-palindromic if:

x is a palindrome.
x is divisible by k.
An integer is called good if its digits can be rearranged to form a
k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form
the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a
k-palindromic integer.

Return the count of good integers containing n digits.

Note that any integer must not have leading zeros, neither before nor after
rearrangement. For example, 1010 cannot be rearranged to form 101.



Example 1:
Input: n = 3, k = 5
Output: 27
Explanation:
Some of the good integers are:
551 because it can be rearranged to form 515.
525 because it is already k-palindromic.

Example 2:
Input: n = 1, k = 4
Output: 2
Explanation:The two good integers are 4 and 8.

Example 3:
Input: n = 5, k = 6
Output: 2468



Constraints:
1 <= n <= 10
1 <= k <= 9

Hint 1: How to generate all K-palindromic strings of length n? Do we need to go
through all n digits? Hint 2: Use permutations to calculate the number of
possible rearrangements.
*/
// n-digit integers can be rearranged to form a palindrome divisible by k.
// K-palindromic: is palindrome and divisible by k
// permutate all possible digits
// return the count of good Integers

/* Generate all palindromic numbers of n digits.

Filter those that are divisible by k.

For each such k-palindromic number, count how many n-digit permutations exist
(with same digit counts).

Avoid overcounting by using sets or canonical forms (e.g., digit frequency
tuples).

*/
class Solution {
public:
  long long countGoodIntegers(int n, int k) {
    unordered_set<string> seen; // to avoid duplicate permutations
    int count = 0;

    vector<string> palindromes = generatePalindromes(n);

    for (const string& p : palindromes) {
      if (stoll(p) % k != 0)
        continue;

      string sortedDigits = p;
      sort(sortedDigits.begin(), sortedDigits.end());

      if (seen.count(sortedDigits))
        continue;

      seen.insert(sortedDigits);
      count += countValidPermutations(sortedDigits);
    }

    return count;
  }

private:
  // Generate all palindromic numbers with exactly n digits
  vector<string> generatePalindromes(int n) {
    vector<string> res;
    int half = (n + 1) / 2;
    int start = pow(10, half - 1);
    int end = pow(10, half);

    for (int i = start; i < end; ++i) {
      string left = to_string(i);
      string right = left;
      if (n % 2 == 1)
        right.pop_back();
      reverse(right.begin(), right.end());
      res.push_back(left + right);
    }

    return res;
  }

  // Count valid permutations of the digits that don't start with 0
  int countValidPermutations(const string& digits) {
    int n = digits.size();
    map<char, int> freq;
    for (char c : digits)
      freq[c]++;

    int total = factorial(n);

    for (auto& [ch, f] : freq) {
      total /= factorial(f);
    }

    // Subtract permutations that start with 0
    if (freq.count('0')) {
      freq['0']--;
      int sub = factorial(n - 1);
      for (auto& [ch, f] : freq) {
        sub /= factorial(f);
      }
      total -= sub;
      freq['0']++; // restore
    }

    return total;
  }

  int factorial(int x) {
    static vector<int> cache(11, -1);
    if (x == 0 || x == 1)
      return 1;
    if (cache[x] != -1)
      return cache[x];
    return cache[x] = x * factorial(x - 1);
  }
};
// sub:
// https://leetcode.com/problems/find-the-count-of-good-integers/submissions/1604133550/?envType=daily-question&envId=2025-04-12
// sol:
// https://leetcode.com/problems/find-the-count-of-good-integers/solutions/6641500/3272-find-the-count-of-good-integers-by-8lore/
