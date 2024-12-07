/* 2554. Maximum Number of Integers to Choose From a Range I

You are given an integer array banned and two integers n and maxSum. You are
choosing some number of integers following the below rules: The chosen integers
have to be in the range [1, n]. Each integer can be chosen at most once. The
chosen integers should not be in the array banned. The sum of the chosen
integers should not exceed maxSum. Return the maximum number of integers you can
choose following the mentioned rules.



Example 1:
Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum
is 6, which did not exceed maxSum.

Example 2:
Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned
conditions.

Example 3:
Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is
28, which did not exceed maxSum.


Constraints:
1 <= banned.length <= 10^4
1 <= banned[i], n <= 10^4
1 <= maxSum <= 10^9 */

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// range is [1,n]
// sum of range is maxSum
// chosen should not be in banned

// Approach:
////1. Sort banned
// 2. Iterate over banned and check if sum of range is less than maxSum
// 3. If yes then add to range
// 4. If no then remove from banned
// 5. Repeat until all elements are added

class Solution {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    sort(banned.begin(), banned.end());
    int count = 0;
    int sum = 0;
    for (int i = 0; i < banned.size(); i++) {
      sum += banned[i];
      if (sum <= maxSum) {
        count++;
      } else {

        banned.erase(banned.begin() + i);
        i--;
      }
    }
    return count;
  }
};

// Problems:
// 1. no clear goal of functions
// 2. banned.earase() function has complexity of O(n) for each removal
// 3. banned list is treated as part of valid range, we have to ignore it

// Fixes:
// 1. Select num from 1 to n(excluding banned) such sum<maxSum
// 2. Use a HashSet for iteration
// 3. Avoid modifying the banned list in-place. Use a set for constant-time
// lookups.

class Solution2 {
public:
  int maxCount(vector<int> &banned, int n, int maxSum) {
    unordered_set<int> bannedSet(banned.begin(), banned.end()); // Fast lookup
    int count = 0;
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
      if (bannedSet.find(i) != bannedSet.end()) {
        continue; // Skip banned numbers
      }
      if (sum + i > maxSum) {
        break; // Stop if adding i exceeds maxSum
      }
      sum += i;
      count++;
    }

    return count;
  }
};

/* Time Complexity:𝑂(𝑛) for iterating through numbers  1 to 𝑛.
 * 𝑂(𝑏) for creating the unordered_set from the banned list (where b is the size
of banned).
 * Total: 𝑂(𝑛+𝑏).

Space Complexity:O(b) for the unordered_set */

void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}
int main() {
  vector<int> banned1 = {1, 6, 5};
  int n1 = 5, maxSum1 = 6;
  Solution2 obj1;
  print(banned1);
  cout << "n1= " << n1 << " " << obj1.maxCount(banned1, n1, maxSum1) << endl;
  vector<int> banned2 = {1, 2, 3, 4, 5, 6, 7};
  int n2 = 8, maxSum2 = 1;
  Solution2 obj2;
  print(banned2);
  cout << "n2= " << n2 << " " << obj2.maxCount(banned2, n2, maxSum2) << endl;
  vector<int> banned3 = {11};
  int n3 = 7, maxSum3 = 50;
  Solution2 obj3;
  print(banned3);
  cout << "n3= " << n3 << " " << obj3.maxCount(banned3, n3, maxSum3) << endl;
  return 0;
}
