/* 66. Plus One

You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.


Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].


Constraints:
1 <= digits.length <= 100
0 <= digits[i] <= 9
digits does not contain any leading 0's.*/

// Approach
/* 1. First of all store all the digits into a stack from the vector
 * 2. Now pop the top of stack and add one to it
 * 3. if the popped digit is 9 then pop the top of stack again and add one to it
 * Handle carry:
If the result of the addition is less than 10, push the updated digit back onto
the stack. If the result is 10 (carry over), push 0 and continue with the next
digit.

 * 4. now push the new digit to stack
 * 5.repeat till stack.size()==full*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    stack<int> st;

    // Step 1: Push all digits into the stack
    for (int digit : digits) {
      st.push(digit);
    }

    vector<int> result;
    int carry = 1; // Initially, we add 1 to the number

    // Step 2: Process the stack
    while (!st.empty()) {
      int top = st.top();
      st.pop();

      int sum = top + carry;
      result.push_back(sum % 10); // Add the last digit of the sum to the result
      carry = sum / 10;           // Update carry
    }

    // Step 3: If there's still a carry, add it
    if (carry > 0) {
      result.push_back(carry);
    }

    // Step 4: Reverse the result to get the final number
    reverse(result.begin(), result.end());

    return result;
  }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

int main() {
  vector<int> digits1 = {1, 2, 3};
  vector<int> digits2 = {4, 3, 2, 1};
  vector<int> digits3 = {9};

  Solution sol;
  cout << digits1 << sol.plusOne(digits1) << endl;
  cout << digits2 << sol.plusOne(digits2) << endl;
  cout << digits3 << sol.plusOne(digits3) << endl;

  return 0;
}
