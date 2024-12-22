/*
Code
Testcase
Test Result
Test Result
2940. Find Building Where Alice and Bob Can Meet
Hard
Topics
Companies
Hint
You are given a 0-indexed array heights of positive integers, where heights[i]
represents the height of the ith building.

If a person is in building i, they can move to any other building j if and only
if i < j and heights[i] < heights[j].

You are also given another array queries where queries[i] = [ai, bi]. On the ith
query, Alice is in building ai while Bob is in building bi.

Return an array ans where ans[i] is the index of the leftmost building where
Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a
common building on query i, set ans[i] to -1.



Example 1:

Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
Output: [2,5,-1,5,2]
Explanation: In the first query, Alice and Bob can move to building 2 since
heights[0] < heights[2] and heights[1] < heights[2]. In the second query, Alice
and Bob can move to building 5 since heights[0] < heights[5] and heights[3] <
heights[5]. In the third query, Alice cannot meet Bob since Alice cannot move to
any other building. In the fourth query, Alice and Bob can move to building 5
since heights[3] < heights[5] and heights[4] < heights[5]. In the fifth query,
Alice and Bob are already in the same building. For ans[i] != -1, It can be
shown that ans[i] is the leftmost building where Alice and Bob can meet. For
ans[i] == -1, It can be shown that there is no building where Alice and Bob can
meet. Example 2:

Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
Output: [7,6,-1,4,6]
Explanation: In the first query, Alice can directly move to Bob's building since
heights[0] < heights[7]. In the second query, Alice and Bob can move to building
6 since heights[3] < heights[6] and heights[5] < heights[6]. In the third query,
Alice cannot meet Bob since Bob cannot move to any other building. In the fourth
query, Alice and Bob can move to building 4 since heights[3] < heights[4] and
heights[0] < heights[4]. In the fifth query, Alice can directly move to Bob's
building since heights[1] < heights[6]. For ans[i] != -1, It can be shown that
ans[i] is the leftmost building where Alice and Bob can meet. For ans[i] == -1,
It can be shown that there is no building where Alice and Bob can meet.



Constraints:

1 <= heights.length <= 5 * 104
1 <= heights[i] <= 109
1 <= queries.length <= 5 * 104
queries[i] = [ai, bi]
0 <= ai, bi <= heights.length - 1 */

#include <iostream>
#include <vector>

using namespace std;

// what to do:
// well use map to store height and use to find leftmost building

// Intuition:
// Consider the pairs (height[i], i), then use sorting, monotonic stack &
// upper_bound

/*Approach:
1. Initialize the vector ans of size qz filled with -1
2. Let idx contain the pair (y, i) for (x,y)=queries[i] as follows
```cpp
if (x > y) // let x <= y
    swap(x, y);
if (x == y|| heights[x]<heights[y])
    ans[i] = y;// alice & bob meet
else idx.emplace_back(y, i);
````
3. sort idx w.r.t. greater
4. Build the vector stack over the pairs as monotonotonic stack
5. Proceed a loop for (_, i) in idx do the following with (x, y)=queries[i] &
j=n-1
```cpp
for (; j >y; j--) {
    while (!stack.empty() && heights[stack.back().second] < heights[j])
        stack.pop_back();
    stack.emplace_back(heights[j], j);
}

// Check if accessing elements beyond the bounds of stack here
auto it=upper_bound(stack.rbegin(), stack.rend(), make_pair(heights[x], n));
ans[i]=(it==stack.rend()) ?-1 : it->second;
````
*/

class Solution {
public:
  using int2 = pair<int, int>;
  vector<int> leftmostBuildingQueries(vector<int>& heights,
                                      vector<vector<int>>& queries) {
    int n = heights.size(), qz = queries.size();
    vector<int> ans(qz, -1);
    vector<int2> idx;

    for (int i = 0; i < qz; i++) {
      int &x = queries[i][0], &y = queries[i][1];
      if (x > y) // let x <= y
        swap(x, y);
      if (x == y || heights[x] < heights[y])
        ans[i] = y;
      else
        idx.emplace_back(y, i);
    }

    sort(idx.begin(), idx.end(), greater<pair<int, int>>());
    vector<int2> stack;

    int j = n - 1;
    for (auto [_, i] : idx) {
      int x = queries[i][0];
      int y = queries[i][1];
      for (; j > y; j--) {
        while (!stack.empty() && heights[stack.back().second] < heights[j])
          stack.pop_back();
        stack.emplace_back(heights[j], j);
      }

      // Check if accessing elements beyond the bounds of stack here
      auto it =
          upper_bound(stack.rbegin(), stack.rend(), make_pair(heights[x], n));
      ans[i] = (it == stack.rend()) ? -1 : it->second;
    }
    return ans;
  }
};

auto init = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 'c';
}();

// Time Complexity: O(qzlog(qz)+qzlogn)
// Space Complexity: O(qz+n)

void runTestCases() {
  Solution solution;

  // Test Case 1
  vector<int> heights1 = {5, 3, 8, 2, 6, 1, 4, 6};
  vector<vector<int>> queries1 = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
  vector<int> result1 = solution.leftmostBuildingQueries(heights1, queries1);
  cout << "Output for Test Case 1: ";
  for (int val : result1)
    cout << val << " ";
  cout << endl;

  // Test Case 2
  vector<int> heights2 = {6, 4, 8, 5, 2, 7};
  vector<vector<int>> queries2 = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
  vector<int> result2 = solution.leftmostBuildingQueries(heights2, queries2);
  cout << "Output for Test Case 2: ";
  for (int val : result2)
    cout << val << " ";
  cout << endl;

  // Additional Test Cases
  // Test Case 3
  vector<int> heights3 = {3, 1, 4, 1, 5, 9};
  vector<vector<int>> queries3 = {{0, 5}};
  vector<int> result3 = solution.leftmostBuildingQueries(heights3, queries3);
  cout << "Output for Test Case 3: ";
  for (int val : result3)
    cout << val << " ";
  cout << endl;

  // Test Case 4
  vector<int> heights4 = {2, 1, 1, 1, 1};
  vector<vector<int>> queries4 = {{0, 4}};
  vector<int> result4 = solution.leftmostBuildingQueries(heights4, queries4);
  cout << "Output for Test Case 4: ";
  for (int val : result4)
    cout << val << " ";
  cout << endl;

  // Test Case 5
  vector<int> heights5 = {10, 20, 30, 40, 50};
  vector<vector<int>> queries5 = {{4, 0}, {1, 3}, {2, 4}};
  vector<int> result5 = solution.leftmostBuildingQueries(heights5, queries5);
  cout << "Output for Test Case 5: ";
  for (int val : result5)
    cout << val << " ";
  cout << endl;

  // Test Case 6
  vector<int> heights6 = {4, 2, 3, 5};
  vector<vector<int>> queries6 = {{2, 2}, {0, 0}, {3, 3}};
  vector<int> result6 = solution.leftmostBuildingQueries(heights6, queries6);
  cout << "Output for Test Case 6: ";
  for (int val : result6)
    cout << val << " ";
  cout << endl;
}

int main() {
  runTestCases();
  return 0;
}
