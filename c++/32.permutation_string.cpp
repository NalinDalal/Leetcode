/*
 * 567. Permutation in String
Solved
Medium
Topics
Companies
Hint
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or
false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.



Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false


Constraints:

1 <= s1.length, s2.length <= 104
s1 and s2 consist of lowercase English letters.
*/

/*
 * Algorithm

The simplest method is to generate all the permutations of the short string and
to check if the generated permutation is a substring of the longer string.

In order to generate all the possible pairings, we make use of a function
permute(string_1, string_2, current_index). This function creates all the
possible permutations of the short string s1.

To do so, permute takes the index of the current element current_index as one of
the arguments. Then, it swaps the current element with every other element in
the array, lying towards its right, so as to generate a new ordering of the
array elements. After the swapping has been done, it makes another call to
permute but this time with the index of the next element in the array. While
returning back, we reverse the swapping done in the current function call.

Thus, when we reach the end of the array, a new ordering of the array's elements
is generated. The following animation depicts the process of generating the
permutations.

*/

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
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
      freq[i] = 0;
    recurPermute(ds, nums, ans, freq);
    return ans;
  }
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;

    // Frequency arrays to store the count of characters
    vector<int> s1Freq(26, 0), s2Freq(26, 0);

    // Initialize frequency array for s1 and the first window of s2
    for (int i = 0; i < s1.size(); i++) {
      s1Freq[s1[i] - 'a']++;
      s2Freq[s2[i] - 'a']++;
    }

    // Sliding window over s2
    for (int i = s1.size(); i < s2.size(); i++) {
      if (s1Freq == s2Freq) {
        return true;
      }

      // Add the next character of the window and remove the first character of
      // the window
      s2Freq[s2[i] - 'a']++;
      s2Freq[s2[i - s1.size()] - 'a']--;
    }

    // Check the last window
    return s1Freq == s2Freq;
  }
};
