/* https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06
1726. Tuple with Same Product

Given an array nums of distinct positive integers, return the number of tuples
(a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums,
and a != b != c != d.



Example 1:
Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)

Example 2:
Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)


Constraints:
1 <= nums.length <= 1000
1 <= nums[i] <= 104
All elements in nums are distinct.
*/
#include <unordered_map>
#include <vector>

using namespace std;
/*Approach:
Use a hash map (unordered_map) to store the frequency of each product
a×b.
Iterate through all pairs (a,b) in nums, compute their product, and store it in
the hash map. If a product appears multiple times, it means multiple pairs have
the same product, forming valid tuples. The number of ways to pick two pairs
from k pairs that have the same product is k(k−1)/2  (combinations). Each valid
tuple can be arranged in 8 different ways:
`(a,b,c,d),(a,b,d,c),(b,a,c,d),(b,a,d,c),(c,d,a,b),(c,d,b,a),(d,c,a,b),(d,c,b,a)`
So multiply by 8.         */
class Solution {
public:
  int tupleSameProduct(vector<int>& nums) {
    if (nums.size() < 4)
      return 0;
    // return the number of tuples (a, b, c, d) such that a * b = c * d
    unordered_map<int, int> productCount;
    int count = 0;

    // Compute all possible products
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        int product = nums[i] * nums[j];
        count += 8 * productCount[product]; // Count valid tuples
        productCount[product]++;
      }
    }

    return count;
  }
};

// sub:
// https://leetcode.com/problems/tuple-with-same-product/submissions/1533247567/?envType=daily-question&envId=2025-02-06
// sol:
// https://leetcode.com/problems/tuple-with-same-product/solutions/6383461/1726-tuple-with-same-product100-by-nalin-jad2/
