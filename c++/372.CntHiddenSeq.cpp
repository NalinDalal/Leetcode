/*2145. Count the Hidden Sequences
You are given a 0-indexed array of n integers differences, which describes the
differences between each pair of consecutive integers of a hidden sequence of
length (n + 1). More formally, call the hidden sequence hidden, then we have
that differences[i] = hidden[i + 1] - hidden[i].

You are further given two integers lower and upper that describe the inclusive
range of values [lower, upper] that the hidden sequence can contain.

For example, given differences = [1, -3, 4], lower = 1, upper = 6, the hidden
sequence is a sequence of length 4 whose elements are in between 1 and 6
(inclusive). [3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences. [5, 6,
3, 7] is not possible since it contains an element greater than 6. [1, 2, 3, 4]
is not possible since the differences are not correct. Return the number of
possible hidden sequences there are. If there are no possible sequences, return
0.



Example 1:
Input: differences = [1,-3,4], lower = 1, upper = 6
Output: 2
Explanation: The possible hidden sequences are:
- [3, 4, 1, 5]
- [4, 5, 2, 6]
Thus, we return 2.

Example 2:
Input: differences = [3,-4,5,1,-2], lower = -4, upper = 5
Output: 4
Explanation: The possible hidden sequences are:
- [-3, 0, -4, 1, 2, 0]
- [-2, 1, -3, 2, 3, 1]
- [-1, 2, -2, 3, 4, 2]
- [0, 3, -1, 4, 5, 3]
Thus, we return 4.

Example 3:
Input: differences = [4,-7,2], lower = 3, upper = 6
Output: 0
Explanation: There are no possible hidden sequences. Thus, we return 0.


Constraints:
n == differences.length
1 <= n <= 105
-105 <= differences[i] <= 105
-105 <= lower <= upper <= 105
*/

// differences[i] = hidden[i + 1] - hidden[i].
// lower, upper inclusive
// Return the number of possible hidden sequences there are. If there are no
// possible sequences, return 0.
/*Let the first number be x

Then the sequence is:

x

x + differences[0]

x + differences[0] + differences[1]

...

So on...

Let’s call:

prefix_sum[i] = sum of differences[0..i-1] (we’ll add 0 as the first prefix)

The value at each point in the sequence will be:

```cpp
hidden[i] = x + prefix_sum[i]
```

So, we need:

```lua
lower <= x + prefix_sum[i] <= upper
=> lower - prefix_sum[i] <= x <= upper - prefix_sum[i]
```
To satisfy this for all i, take the maximum of lower bounds and minimum of upper
bounds.

use `long long` to avoid overflow
*/
class Solution {
public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long minPrefix = 0, maxPrefix = 0, prefix = 0;

    for (int diff : differences) {
      prefix += diff;
      minPrefix = min(minPrefix, prefix);
      maxPrefix = max(maxPrefix, prefix);
    }

    // valid x values are in [lower - minPrefix, upper - maxPrefix]
    long long minStart = (long long)lower - minPrefix;
    long long maxStart = (long long)upper - maxPrefix;

    return max(0LL, maxStart - minStart + 1);
  }
};
// sub:
// https://leetcode.com/problems/count-the-hidden-sequences/submissions/1613035489/?envType=daily-question&envId=2025-04-21
// sol:
// https://leetcode.com/problems/count-the-hidden-sequences/solutions/6672485/2145-count-the-hidden-sequences-by-nalin-vi26/
