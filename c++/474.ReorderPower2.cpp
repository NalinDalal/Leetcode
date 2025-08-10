/*869. Reordered Power of 2
You are given an integer n. We reorder the digits in any order (including the
original order) such that the leading digit is not zero.

Return true if and only if we can do this so that the resulting number is a
power of two.



Example 1:
Input: n = 1
Output: true

Example 2:
Input: n = 10
Output: false


Constraints:
1 <= n <= 109
*/

// reorder n into any num, it must not have trailing zeroes
// now if the the num or reorder result is power of 2, return true
// else reutrn false;
/*1. Convert n to a digit frequency signature (e.g., 128 → "1128" sorted →
"128").

2. Precompute the digit signatures for all powers of 2 up to 10E9  (since n ≤
10E9 in problem constraints).

3. If n’s digit signature matches any power of 2 signature, return true.

1. Make a helper function
```cpp
string sig(int x) {
    string s = to_string(x);
    sort(s.begin(), s.end());
    return s;
}
```

2. Compute sig(n).

3. For each power of 2 from 1 to 2E30 , check if sig(n) matches
sig(power_of_two).

*/
class Solution {
public:
  bool reorderedPowerOf2(int n) {
    string s = sig(n);
    for (int i = 0; i < 31; i++) { // 2^0 to 2^30 fits in int
      if (s == sig(1 << i))
        return true;
    }
    return false;
  }

private:
  string sig(int x) {
    string s = to_string(x);
    sort(s.begin(), s.end());
    return s;
  }
};
// sub:
// https://leetcode.com/problems/reordered-power-of-2/submissions/1729600292/?envType=daily-question&envId=2025-08-10
// sol:
// https://leetcode.com/problems/reordered-power-of-2/solutions/7062756/869-reordered-power-of-2-by-nalindalal20-j6kz/
