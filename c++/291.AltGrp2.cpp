/* 3208. Alternating Groups II
There is a circle of red and blue tiles. You are given an array of integers
colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating
colors (each tile in the group except the first and last one has a different
color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are
considered to be next to each other.



Example 1:

Input: colors = [0,1,0,1,0], k = 3

Output: 3

Explanation:



Alternating groups:



Example 2:

Input: colors = [0,1,0,0,1,0,1], k = 6

Output: 2

Explanation:



Alternating groups:



Example 3:

Input: colors = [1,1,0,1], k = 4

Output: 0

Explanation:





Constraints:

3 <= colors.length <= 105
0 <= colors[i] <= 1
3 <= k <= colors.length
*/

// color[i]=0->red, else blue
// consider colors[(i + j) % n] for index wrapping.
// return no of alternating groups
// each k elemt follow rule: colors[i] != colors[i+1]
// tle

/* 1. let `n=|color|`, `sz=n+k-1`
2. Initialize `ans=0`, `alt=1`, `prev=color[0]` where `ans` is the answer to
return
3. Use a loop from i=1 to sz-1 do the following
```cpp
// if adjacent ones are equal reset alt to 1, otherwise increase by 1
alt=(prev==colors[i%n])?1:alt+1;
ans+=(alt>=k); //when alt>=k increase ans by 1
prev=colors[i%n]; // update prev
```
4.return ans
*/

class Solution {
public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    const int n = colors.size(), sz = n + k - 1;
    int ans = 0, alt = 1, prev = colors[0];
    for (int i = 1; i < sz; i++) {
      alt = (prev == colors[i % n]) ? 1 : alt + 1;
      ans += (alt >= k);
      prev = colors[i % n];
    }
    return ans;
  }
};
// sub:https://leetcode.com/problems/alternating-groups-ii/submissions/1568063962/
// sol:
// https://leetcode.com/problems/alternating-groups-ii/solutions/6517274/3208-alternating-groups-ii-by-nalindalal-qqe4/
