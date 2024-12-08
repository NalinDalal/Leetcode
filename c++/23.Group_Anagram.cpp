/*
* 49. Group Anagrams
*
* Given an array of strings strs, group the anagrams together. You can return
the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different
word or phrase, typically using all the original letters exactly once.



Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]

*/

// Solution logic->
/*
 * 1. Traverse through vector and sort each string. and add the str[i] to the
 * sorted string. the sorted order of the words will match word to word ex.
 * ate,eat-> eat sorted will become aet, ate will become aet compare both we get
 * aet,add ate,eat to vector if the new words sorted is same as previous one,
 * append to new map
 * 2. Store the ans in vector of vector, size will be size of mp. i.e no. of
 * rows in map. example-> abt, bat aet, eat, tea, ate ant, tan, nat


# Complexity
- Time complexity:O(n^2)
- Space complexity:O(n)
 * */

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& str) {
    // 1. Store the values in the map..
    map<string, vector<string>> mp;
    for (int i = 0; i < str.size(); i++) {
      string s = str[i];
      sort(s.begin(), s.end());
      mp[s].push_back(str[i]);
    }

    // 2. storing of the ans.
    // size of the ans will be the no. of the rows. in mp;
    vector<vector<string>> ans(mp.size());
    int index = 0;
    for (auto x : mp) {
      // to store the anagrams or same items together.
      auto temp = x.second;
      for (auto x : temp) {
        ans[index].push_back(x);
      }
      index++;
    }
    return ans;
  }
};
