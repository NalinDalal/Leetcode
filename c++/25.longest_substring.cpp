/* 3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest substring without repeating
characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a
substring.
 */
/*
    *  //longest substring w/o repeating characters
        //my approach says iterate over the string, nested for loop
        //now we will iterate over the string, store the characters traversed
        //use a hashmap to store the characters
        //initalised with 0, jth char will be checked with the hashmap,
        //if already present-> break
        //max length=i-j+1
        //O(n^2)->time, O(n)->Space
*/
/*
 *   //sliding window- Algorithm
 *note the index of the character
 * take 2 pointer ->l,r
 * take a hash-> char and index
 * length=r-l+1
 * r++{a should have been iterated previously}
 * when the elements gwt twice,l=map(s[r]+1)-> l was at 0, now l=2
 * update the elements{a=5}
 * map[s[r]]>=l
 * till r<s.length
 */

/* Algo
 function(string s){
 hashmap(256)-> -1  //initalise all with -1
 n=s.length
 l=0,r=o, maxl=0    //l-leftptr, r-rightptr, maxl-maxlength
 while(r<n){
 if(hash[s[r]]!=-1){
     if(hash[s[r]]>=l){
         l=hash[s[r]]+1
     }
 }
 len=r-l+1
 maxlen=max(maxlen,len)
 hash[s[r]]=r
 r++;
 }
 return maxlen
 }
 */
// Time Complexity: O(n)
// Space Complexity: O(256)

#include <iostream>
#include <string>
#include <unordered_map>
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    // longest substring w/o repeating characters
    std::unordered_map<char, int> hash(256); // Initialize all values with -1
    for (auto& entry : hash) {
      entry.second = -1;
    }

    int n = s.length();
    int l = 0, r = 0,
        maxlen = 0; // l - left pointer, r - right pointer, maxlen - max length

    while (r < n) {
      if (hash[s[r]] != hash.end()) { // if there is empty string
        if (hash[s[r]] >= l) {
          l = hash[s[r]] + 1;
        }
      }
      int len = r - l + 1;
      maxlen = std::max(maxlen, len);
      hash[s[r]] = r;
      r++;
    }

    return maxlen;
  }
};
