/*1865. Finding Pairs With a Certain Sum
You are given two integer arrays nums1 and nums2. You are tasked to implement a
data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given
value (0 <= i < nums1.length and 0 <= j < nums2.length). Implement the
FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with
two integer arrays nums1 and nums2. void add(int index, int val) Adds val to
nums2[index], i.e., apply nums2[index] += val. int count(int tot) Returns the
number of pairs (i, j) such that nums1[i] + nums2[j] == tot.


Example 1:

Input
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1,
1], [7]] Output [null, 8, null, 2, 1, null, null, 11]

Explanation
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5,
4]); findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4),
(3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4 findSumPairs.add(3,
2); // now nums2 = [1,4,5,4,5,4] findSumPairs.count(8);  // return 2; pairs
(5,2), (5,4) make 3 + 5 findSumPairs.count(4);  // return 1; pair (5,0) makes 3
+ 1 findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4] findSumPairs.add(1, 1);
// now nums2 = [2,5,5,4,5,4] findSumPairs.count(7);  // return 11; pairs (2,1),
(2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs
(5,3), (5,5) make 3 + 4


Constraints:

1 <= nums1.length <= 1000
1 <= nums2.length <= 105
1 <= nums1[i] <= 109
1 <= nums2[i] <= 105
0 <= index < nums2.length
1 <= val <= 105
1 <= tot <= 109
At most 1000 calls are made to add and count each.

Hint 1
The length of nums1 is small in comparison to that of nums2
Hint 2
If we iterate over elements of nums1 we just need to find the count of tot -
element for all elements in nums1

*/
// Approach
/* len(nums1)<len(nums2)
 * store element of nums2 in a map
 * enumerate each element num in nums1
  and look up the value corresponding to the key tot−num in the hash map. The
 sum of these values gives us the answer.

  store the arrays nums1 and nums2 , and also maintain a hash map cnt to keep
 track of the frequencies of elements in nums2.

  add(int index,int val){
  cnt[nums2[index]]--;
  nums2[index]+=val;
  cnt[nums2[index]]++;
  }

  getPairs(int tot){
  enumerate each element num in nums1 , add cnt[tot−num] to the result, and
 return the final sum.
  }


    */

class FindSumPairs {
private:
  vector<int> nums1, nums2;
  unordered_map<int, int> cnt;

public:
  FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
    this->nums1 = nums1;
    this->nums2 = nums2;
    for (int num : nums2) {
      ++cnt[num];
    }
  }

  void add(int index, int val) {
    --cnt[nums2[index]];
    nums2[index] += val;
    ++cnt[nums2[index]];
  }

  int count(int tot) {
    int ans = 0;
    for (int num : nums1) {
      int rest = tot - num;
      if (cnt.count(rest)) {
        ans += cnt[rest];
      }
    }
    return ans;
  }
};

// Your FindSumPairs object will be instantiated and called as such:
int main() {
  FindSumPairs* obj = new FindSumPairs(nums1, nums2);
  obj->add(index, val);
  int param_2 = obj->count(tot);
  return 0;
}
// sub:
// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/submissions/1688569962/?envType=daily-question&envId=2025-07-06
// sol:
// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/solutions/6928087/1865-finding-pairs-with-a-certain-sum-by-itq6/
