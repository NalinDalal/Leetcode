/*
4. Median of Two Sorted Arrays
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the
median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

/* Soln->
 Median is the middle element of the sorted array.

 to dono array ko merge karna hai

 to dono array ko sort karna hai
append the 2nd array into 1s array

 sort the array.

 for median just log the middle element
 middle element=nums[(totalSize/2)];

 ek kam kr
 recursively call the function
  [1,2,3]
  1-> [1,2,3],[1,3,2]
  2->[2,1,3],[2,3,1]
  3->[3,1,2],[3,2,1]

  3!=6 ways
 */

#include <vector>
class Solution {
private:
  void recurPermute(vector<int>& ds, vector<int>& nums,
                    vector<vector<int>>& ans, int freq[]) {
    if (ds.size() == nums.size()) {
      ans.push_back(ds);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (!freq[i]) {
        ds.push_back(nums[i]);
        freq[i] = 1;
        recurPermute(ds, nums, ans, freq);
        freq[i] = 0;
        ds.pop_back();
      }
    }
  }

public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()] = {0};
    for (int i = 0; i < nums.size(); i++)
      freq[i] = 0;
    recurPermute(ds, nums, ans, freq);
    return ans;
    ｝
  };

  /*
    solution->
  Let's break down the entire code for both the `permute` function (which
  generates permutations of a list of numbers) and the `checkInclusion` function
  (which checks if a permutation of one string is a substring of another
  string).

  ### 1. **`permute` function:**

  This function generates all permutations of a given list of numbers (`nums`).

  ```cpp
  class Solution {
  private:
      void recurPermute(vector<int> &ds, vector<int> &nums, vector<vector<int>>
  &ans, int freq[]) {
  ```
  - This is a **recursive helper function** called `recurPermute` that generates
  permutations.
  - Parameters:
    - `ds`: A temporary vector to store one possible permutation (in progress).
    - `nums`: The input vector of numbers.
    - `ans`: A 2D vector that stores all the permutations generated.
    - `freq[]`: An array used to track whether a number from `nums` has been
  included in the current permutation (`ds`).

  ```cpp
          if(ds.size() == nums.size()) {
              ans.push_back(ds);
              return;
          }
  ```
  - **Base case**: If the size of `ds` (the current permutation) is equal to the
  size of `nums` (meaning we have a complete permutation), the function pushes
  `ds` into `ans` and returns.

  ```cpp
          for (int i = 0; i < nums.size(); i++) {
              if (!freq[i]) {
                  ds.push_back(nums[i]);
                  freq[i] = 1;
                  recurPermute(ds, nums, ans, freq);
                  freq[i] = 0;
                  ds.pop_back();
              }
          }
      }
  ```
  - **Recursive case**: For each number in `nums`, if it has not been used in
  the current permutation (`if (!freq[i])`):
    1. **Add the number** to the current permutation (`ds.push_back(nums[i])`).
    2. **Mark the number as used** (`freq[i] = 1`).
    3. **Recursively call `recurPermute`** to continue building the permutation.
    4. **Backtrack**: After the recursive call, unmark the number (`freq[i] =
  0`) and remove the number from `ds` to try another permutation.

  ### Public Function:
  ```cpp
  public:
      vector<vector<int>> permute(vector<int>& nums) {
          vector<vector<int>> ans;
          vector<int> ds;
          int freq[nums.size()];
          for (int i = 0; i < nums.size(); i++) freq[i] = 0;
          recurPermute(ds, nums, ans, freq);
          return ans;
      }
  ```
  - The `permute` function initializes:
    - `ans`: A vector to store all the generated permutations.
    - `ds`: A temporary vector to store the current permutation being built.
    - `freq`: An array to track whether a number has already been used in the
  current permutation.
  - It then calls the recursive function `recurPermute` and returns `ans` with
  all possible permutations.

  ### 2. **`checkInclusion` function:**

  This function checks if one string `s1` is a permutation of any substring of
  another string `s2`.

  ```cpp
      bool checkInclusion(string s1, string s2) {
          if (s1.size() > s2.size()) return false;
  ```
  - If `s1` is larger than `s2`, it's impossible for `s1` to be a permutation of
  any substring of `s2`, so return `false`.

  ```cpp
          // Frequency arrays to store the count of characters
          vector<int> s1Freq(26, 0), s2Freq(26, 0);
  ```
  - **Frequency arrays**: These arrays store the count of each character ('a' to
  'z', 26 letters). `s1Freq` stores the frequency of characters in `s1`, and
  `s2Freq` stores the frequency of the current window in `s2`.

  ```cpp
          // Initialize frequency array for s1 and the first window of s2
          for (int i = 0; i < s1.size(); i++) {
              s1Freq[s1[i] - 'a']++;
              s2Freq[s2[i] - 'a']++;
          }
  ```
  - This loop initializes the frequency arrays:
    - `s1Freq` counts the occurrences of characters in `s1`.
    - `s2Freq` counts the occurrences of characters in the first window of `s2`
  (of size `s1.size()`).

  ```cpp
          // Sliding window over s2
          for (int i = s1.size(); i < s2.size(); i++) {
              if (s1Freq == s2Freq) {
                  return true;
              }

              // Add the next character of the window and remove the first
  character of the window s2Freq[s2[i] - 'a']++; s2Freq[s2[i - s1.size()] -
  'a']--;
          }
  ```
  - **Sliding window**: After initializing the frequency counts for the first
  window, this loop moves the window one character at a time over `s2`.
    - **Check if `s1Freq` matches `s2Freq`**: If the character frequencies
  match, it means the current window in `s2` is a permutation of `s1`, so return
  `true`.
    - **Update the window**:
      - Add the next character in `s2` to the frequency array (`s2Freq[s2[i] -
  'a']++`).
      - Remove the character that is no longer in the window (`s2Freq[s2[i -
  s1.size()] - 'a']--`).

  ```cpp
          // Check the last window
          return s1Freq == s2Freq;
      }
  };
  ```
  - **Final check**: After sliding through all of `s2`, check the last window.
  If the frequencies match, return `true`; otherwise, return `false`.

  ### Summary:
  - **`permute` function**: Recursively generates all possible permutations of a
  list of numbers using backtracking.
  - **`checkInclusion` function**: Uses the sliding window technique and
  frequency arrays to determine if a permutation of `s1` exists as a substring
  in `s2`.
  */
