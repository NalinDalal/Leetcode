/*274. H-Index
Given an array of integers citations where citations[i] is the number of
citations a researcher received for their ith paper, return the researcher's
h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as
the maximum value of h such that the given researcher has published at least h
papers that have each been cited at least h times.



Example 1:
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of
them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has
3 papers with at least 3 citations each and the remaining two with no more than
3 citations each, their h-index is 3.

Example 2:
Input: citations = [1,3,1]
Output: 1


Constraints:
n == citations.length
1 <= n <= 5000
0 <= citations[i] <= 1000

Hint 1: An easy approach is to sort the array first.
Hint 2: What are the possible values of h-index?
Hint 3: A faster approach is to use extra space.
*/

// There should be atleast n citations at nth index when sorted in descending
// order.

// approach:
// sort in descending order
// then check if current is less than next
// if happens then break and return index
class Solution {
public:
  int hIndex(vector<int>& v) {
    sort(v.begin(), v.end(), greater<int>());
    int i;
    for (i = 0; i < v.size(); i++) {
      if (v[i] < i + 1) {
        break;
      }
    }
    return i;
  }
};
// sub:
// https://leetcode.com/problems/h-index/submissions/1590778376/?envType=study-plan-v2&envId=top-interview-150
// sol:
// https://leetcode.com/problems/h-index/solutions/6594947/274-h-index-by-nalindalal2004-n3n6/
