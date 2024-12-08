/*
179. Largest Number
Given a list of non-negative integers nums, arrange them such that they form the
largest number and return it. Since the result may be very large, so you need to
return a string instead of an integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 10^9
*/

class Solution {
public:
  string largestNumber(vector<int>& nums) {
    // Convert int vector to string vector
    vector<string> nums_str;
    for (int num : nums) {
      nums_str.push_back(to_string(num));
    }

    // Custom sort based on the concatenation comparison
    sort(
        nums_str.begin(), nums_str.end(), [](const string& a, const string& b) {
          return a + b > b + a; // Sort descending based on concatenated strings
        });

    // Handle case where the largest number is "0"
    if (nums_str[0] == "0") {
      return "0";
    }

    // Concatenate sorted strings to form the largest number
    string largest_num;
    for (const string& num_str : nums_str) {
      largest_num += num_str;
    }

    return largest_num;
  }
};

// Logic->
/*
convert from int to string

first convert the elements into individual ones
now check with their own 0th index
like in 10,2 ->2 is greater than 1
so put 2 into output

sorting logic -> ab
a + b > b + a
then the corresponding remaining elements

check for base case where one element is 0

Concatenate sorted strings to form the largest number

append all
return as string
*/
