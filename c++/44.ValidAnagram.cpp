/*
242. Valid Anagram
Given two strings s and t, return true if t is an anagram of s, and false
otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

// Logic->
/*
first remove space
convert both s,t to lowercase
lowercase-> transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return
std::tolower(c); }); remove space-> s.erase(remove_if(s.begin(), s.end(),
::isspace), s.end()); t.erase(remove_if(t.begin(), t.end(), ::isspace),
t.end());

countCharacters uses an std::unordered_map<char, int> to count occurrences of
each character in the string. charCount1 and charCount2 store the character
counts for s and t respectively.

The function compares charCount1 with charCount2 to check if they have the same
character counts. It also checks if all characters in t are present in s using
charCount1.find(pair.first) == charCount1.end().
*/
/* JS Code
 var isAnagram = function(s, t) {
    s=s.replace(/\s/g,' ').toLowerCase();    //REMOVE SPACE;LOWERCASE ALL
  t=t.replace(/\s/g,' ').toLowerCase();

  function countCharacters(s){
      const charCount={};
      for(const char of s){
          charCount[char]=(charCount[char]||0)+1;
      }
      return charCount;
  }

  const charCount1=countCharacters(s);
  const charCount2=countCharacters(t);

  for(const char in charCount1){
      if(charCount1[char] !== charCount2[char]){
          return false;
      }
  }

  for(const char in charCount2){
      if(!(char in charCount1)){
          return false;
      }
  }
  return true;
};
*/

// CPP Code
class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    // Convert both strings to lowercase and remove spaces
    transform(s.begin(), s.end(), s.begin(),
              [](unsigned char c) { return std::tolower(c); });
    transform(t.begin(), t.end(), t.begin(),
              [](unsigned char c) { return std::tolower(c); });
    s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
    t.erase(remove_if(t.begin(), t.end(), ::isspace), t.end());

    // Function to count characters in a string
    auto countCharacters = [](const std::string& str) {
      std::unordered_map<char, int> charCount;
      for (char ch : str) {
        charCount[ch]++;
      }
      return charCount;
    };

    // Count characters in both strings
    auto charCount1 = countCharacters(s);
    auto charCount2 = countCharacters(t);

    // Compare character counts
    for (const auto& pair : charCount1) {
      if (pair.second != charCount2[pair.first]) {
        return false;
      }
    }

    // Check for characters in t that are not in s
    for (const auto& pair : charCount2) {
      if (charCount1.find(pair.first) == charCount1.end()) {
        return false;
      }
    }

    return true;
  }
}
