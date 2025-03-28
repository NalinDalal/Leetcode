//28. Find the Index of the First Occurrence in a String
function strStr(haystack: string, needle: string): number {
  if (needle.length == 0) return 0; // If needle is empty, return 0

  for (let i = 0; i <= haystack.length - needle.length; i++) {
    if (haystack.substr(i, needle.length) == needle) {
      return i; // Found the first occurrence of needle
    }
  }

  return -1; // Return -1 if needle is not found
}
//sub: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1588823833/?envType=study-plan-v2&envId=top-interview-150
