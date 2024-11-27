/* 43. Multiply Strings

Given two non-negative integers num1 and num2 represented as strings, return the
product of num1 and num2, also represented as a string. Note: You must not use
any built-in BigInteger library or convert the inputs tointeger directly.


Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"


Constraints:

1 <= num1.length, num2.length <= 200
num1 and num2 consist of digits only.
Both num1 and num2 do not contain any leading zero, except the number 0
itself.*/

// Approach:
/*first of all, convert string num1, string num2 into integer num1, num2;
store the product of num1 and num2 into an integer product;
convert the int product into string product;
return product;*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    int n1 = stoi(num1);
    int n2 = stoi(num2);
    int product = n1 * n2;
    string product_str = to_string(product);
    return product_str;
  }
};
// int overflow for product
// use long long int
// not runs
// If num1 or num2 is large, converting them to int will cause an overflow,
// leading to incorrect results.

// Approach 2:
// perform the multiplication manually using string manipulation

// Explanation:
/*Initialization:
Use a vector<int> to store the intermediate results of the multiplication.

Digit-by-Digit Multiplication:
Multiply each digit of num1 with each digit of num2.
Accumulate the result at the appropriate position in the result vector,
considering carry.

Handle Carry:
Add the carry to the next higher digit.

Convert to String:
Skip leading zeros while converting the result vector into the final string.*/

class Solution2 {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0")
      return "0";

    int m = num1.size(), n = num2.size();
    vector<int> result(m + n, 0);

    // Perform multiplication digit by digit
    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
        int sum = mul + result[i + j + 1];

        result[i + j + 1] = sum % 10; // Store current digit
        result[i + j] += sum / 10;    // Carry to the next position
      }
    }

    // Convert the result vector to a string
    string product;
    for (int num : result) {
      if (!(product.empty() && num == 0)) { // Skip leading zeros
        product.push_back(num + '0');
      }
    }
    return product.empty() ? "0" : product;
  }
};
// Time Complexity: O(mxn)
// Space Complexity: O(m+n)

int main() {
  Solution sol;
  Solution2 sol2;
  cout << "Approach 1:" << endl;
  cout << "Test Case 1:" << endl;
  string num1 = "2";
  string num2 = "3";
  string product1 = sol.multiply(num1, num2);
  // cout<<"Approach 1:"<<endl;
  cout << "num1:" << num1 << " num2:" << num2 << " product:" << product1
       << endl;
  cout << "Test Case 2:" << endl;
  string num3 = "123";
  string num4 = "456";
  string product2 = sol.multiply(num3, num4);
  cout << "num1: " << num3 << " num2: " << num4 << "product: " << product2
       << endl;

  cout << "Approach 2:" << endl;
  cout << "Test Case 1:" << endl;
  string num5 = "2";
  string num6 = "3";
  string product3 = sol2.multiply(num5, numб);
  cout << "num1:" << num5 << " num2:" << num6 << " product:" << product3
       << endl;
  cout << "Test Case 2:" << endl;
  string num7 = "123";
  string num8 = "456";
  string product4 = sol2.multiply(num7, num8);
  cout << "num1:" << num7 << " num2:" << num8 << " product:" << product4
       << endl;
  return 0;
}
