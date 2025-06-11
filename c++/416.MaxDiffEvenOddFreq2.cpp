/* 3445. Maximum Difference Between Even and Odd Frequency II
You are given a string s and an integer k. Your task is to find the maximum
difference between the frequency of two characters, freq[a] - freq[b], in a
substring subs of s, such that:

subs has a size of at least k.
Character a has an odd frequency in subs.
Character b has an even frequency in subs.
Return the maximum difference.

Note that subs can contain more than 2 distinct characters.



Example 1:

Input: s = "12233", k = 4

Output: -1

Explanation:

For the substring "12233", the frequency of '1' is 1 and the frequency of '3'
is 2. The difference is 1 - 2 = -1.

Example 2:

Input: s = "1122211", k = 3

Output: 1

Explanation:

For the substring "11222", the frequency of '2' is 3 and the frequency of '1'
is 2. The difference is 3 - 2 = 1.

Example 3:

Input: s = "110", k = 3

Output: -1



Constraints:

3 <= s.length <= 3 * 104
s consists only of digits '0' to '4'.
The input is generated that at least one substring has a character with an even
frequency and a character with an odd frequency. 1 <= k <= s.length
*/

/* Intuition:
string s only contains digit characters [0,4], we can first enumerate the
characters a and b described in the problem a- odd, b- even a occurence parity
then b occurence parity; possible->[00,01,10,11] string correspond to `10` case
2 pointer approach-> status[right]=(cnt[a] mod 2)*2+(cnt[b] mod 2)
    - right-left>=k -> substr.size()=k
    - cnt[b]-prev[b]>=2 -> b appear even no of times
for valid left; ans=(cnt[a]-cnt[b])-(prev[b]-prev[a])
status[left]=(prev[a] mod 2)*2+(prev[b] mod 2)
    update best[status[left]] via prev[a]-prev[b]
    move left pointer, calculate for right pointer
hence
ans=(cnt[a]-cnt[b])-best[status[right] xor (10)base2]

*/

class Solution {
public:
  int maxDifference(string s, int k) {
    auto getStatus = [](int cnt_a, int cnt_b) -> int {
      return ((cnt_a & 1) << 1) | (cnt_b & 1);
    };

    int n = s.size();
    int ans = INT_MIN;
    for (char a = '0'; a <= '4'; ++a) {
      for (char b = '0'; b <= '4'; ++b) {
        if (a == b) {
          continue;
        }
        int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
        int cnt_a = 0, cnt_b = 0;
        int prev_a = 0, prev_b = 0;
        int left = -1;
        for (int right = 0; right < n; ++right) {
          cnt_a += (s[right] == a);
          cnt_b += (s[right] == b);
          while (right - left >= k && cnt_b - prev_b >= 2) {
            int left_status = getStatus(prev_a, prev_b);
            best[left_status] = min(best[left_status], prev_a - prev_b);
            ++left;
            prev_a += (s[left] == a);
            prev_b += (s[left] == b);
          }
          int right_status = getStatus(cnt_a, cnt_b);
          if (best[right_status ^ 0b10] != INT_MAX) {
            ans = max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
          }
        }
      }
    }
    return ans;
  }
};
// sub:
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/submissions/1660662581/?envType=daily-question&envId=2025-06-11
// sol;
// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/solutions/6832312/3445-maximum-difference-between-even-and-39j9/
