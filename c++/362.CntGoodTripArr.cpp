/* 2179. Count Good Triplets in an Array
You are given two 0-indexed arrays nums1 and nums2 of length n, both of which
are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing
order by position both in nums1 and nums2. In other words, if we consider pos1v
as the index of the value v in nums1 and pos2v as the index of the value v in
nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1,
such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.



Example 1:

Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation:
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1),
(2,0,3), (2,1,3), and (0,1,3). Out of those triplets, only the triplet (0,1,3)
satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet. Example 2:

Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).


Constraints:

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 and nums2 are permutations of [0, 1, ..., n - 1].

Hint 1: For every value y, how can you find the number of values x (0 ≤ x, y ≤ n
- 1) such that x appears before y in both of the arrays?

Hint 2: Similarly, for every
value y, try finding the number of values z (0 ≤ y, z ≤ n - 1) such that z
appears after y in both of the arrays.

Hint 3: Now, for every value y, count the
number of good triplets that can be formed if y is considered as the middle
element.

*/

/* We're given two permutations, nums1 and nums2. For a triplet (x, y, z)
(distinct values from 0 to n - 1), we want:

- pos1[x] < pos1[y] < pos1[z]

- pos2[x] < pos2[y] < pos2[z]

Instead of checking all combinations (which would be O(n^3) and TLE for n =
1e5), we need to optimize.*/

/* use Fenwick Tree / BIT {O(nlogn)}
1. Map values to positions:
- Use a map to convert values to their index in nums2 (i.e., pos2[val] = index).

2. Transform nums1 into nums2 indices:
- nums1_mapped[i] = pos2[nums1[i]]

3. Now, the problem becomes:
- Count the number of triplets i < j < k such that nums1_mapped[i] <
nums1_mapped[j] < nums1_mapped[k].

4. For each j, count:
- left[j]: number of elements before j that are smaller than nums1_mapped[j]
- right[j]: number of elements after j that are greater than nums1_mapped[j]

5. Then for each j, total good triplets with j as the middle element = left[j] *
right[j]


*/

class Fenwick {
  vector<int> bit;
  int n;

public:
  Fenwick(int size) : n(size) {
    bit.assign(n + 2, 0); // Prevent out-of-bounds at idx = n
  }

  void update(int idx, int delta) {
    for (++idx; idx <= n + 1; idx += idx & -idx)
      bit[idx] += delta;
  }

  int query(int idx) {
    int res = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
      res += bit[idx];
    return res;
  }

  int range_query(int left, int right) {
    return query(right) - query(left - 1);
  }
};

class Solution {
public:
  long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();

    // Map each number to its index in nums2
    vector<int> pos2(n);
    for (int i = 0; i < n; ++i)
      pos2[nums2[i]] = i;

    // Map nums1[i] to its corresponding index in nums2
    vector<int> mapped(n);
    for (int i = 0; i < n; ++i)
      mapped[i] = pos2[nums1[i]];

    Fenwick bitLeft(n), bitRight(n);
    vector<int> rightFreq(n, 0);

    // Count initial frequencies for right BIT
    for (int x : mapped)
      rightFreq[x]++;

    for (int i = 0; i < n; ++i)
      if (rightFreq[i])
        bitRight.update(i, rightFreq[i]);

    long long res = 0;
    for (int j = 0; j < n; ++j) {
      int mid = mapped[j];
      bitRight.update(mid, -1); // remove current from right BIT

      int leftCount = bitLeft.query(mid - 1); // less than mid to the left
      int rightCount =
          (mid + 1 <= n - 1) ? bitRight.range_query(mid + 1, n - 1) : 0;

      res += 1LL * leftCount * rightCount;
      bitLeft.update(mid, 1); // add current to left BIT
    }

    return res;
  }
};
// sub:
// https://leetcode.com/problems/count-good-triplets-in-an-array/submissions/1607117927/?envType=daily-question&envId=2025-04-15
// sol:
// https://leetcode.com/problems/count-good-triplets-in-an-array/solutions/6651868/2179-count-good-triplets-in-an-array-by-lpheo/
