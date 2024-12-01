/* 1346. Check If N and Its Double Exist

Given an array arr of integers, check if there exist two indices i and j such
that : i != j 0 <= i, j < arr.length arr[i] == 2 * arr[j]


Example 1:
Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

Example 2:
Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.


Constraints:
2 <= arr.length <= 500
-10^3 <= arr[i] <= 10^3 */

#include <iostream>
#include <vector>

using namespace std;

// what is asked just do that
// check each element with each other, if it is double return true else false
class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[i] == 2 * arr[j] && i != j) {
          return true;
        }
      }
    }
    return false;
  }
};

// Overloading << operator to print vector
ostream &operator<<(ostream &os, const vector<int> &vec) {
  for (int num : vec) {
    os << num << " ";
  }
  return os;
}

int main() {
  Solution s;
  cout << "Test Case 1:" << endl;
  vector<int> arr1 = {10, 2, 5, 3};
  cout << arr1 << endl;
  cout << s.checkIfExist(arr1) << endl;
  cout << endl;
  cout << "Test Case 2: " << endl;
  vector<int> arr2 = {3, 1, 7, 11};
  cout << arr2 << endl;
  cout << s.checkIfExist(arr2) << endl;

  return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Beats 100%
