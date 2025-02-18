/* 68. Text Justification
Given an array of strings words and a width maxWidth, format the text such that
each line has exactly maxWidth characters and is fully (left and right)
justified.

You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line does not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is
inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters
only. Each word's length is guaranteed to be greater than 0 and not exceed
maxWidth. The input array words contains at least one word.


Example 1:

Input: words = ["This", "is", "an", "example", "of", "text", "justification."],
maxWidth = 16 Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall be",
because the last line must be left-justified instead of fully-justified. Note
that the second line is also left-justified because it contains only one word.
Example 3:

Input: words =
["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"],
maxWidth = 20 Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]


Constraints:
1 <= words.length <= 300
1 <= words[i].length <= 20
words[i] consists of only English letters and symbols.
1 <= maxWidth <= 100
words[i].length <= maxWidth
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
// combine words into a single string of size maxWidth

// keep the words in a vector
// now the words are of size maxWidth
// if size gets small, then add spaces to ensure size
// for last line, add spaces to the end
class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    int currentLength = 0;
    vector<string> currentLine;

    for (int i = 0; i < words.size(); i++) {
      // Check if adding words[i] exceeds maxWidth
      if (currentLength + currentLine.size() + words[i].size() > maxWidth) {
        // Build the current justified line
        string line = buildLine(currentLine, maxWidth - currentLength);
        result.push_back(line);

        // Reset variables for the next line
        currentLine.clear();
        currentLength = 0;
      }

      // Add words[i] to the current line
      currentLine.push_back(words[i]);
      currentLength += words[i].size();
    }

    // Last line handling (left justify)
    if (!currentLine.empty()) {
      string lastLine = buildLastLine(currentLine, maxWidth - currentLength);
      result.push_back(lastLine);
    }

    return result;
  }

private:
  string buildLine(vector<string>& lineWords, int extraSpaces) {
    string line;
    if (lineWords.size() == 1) {
      line = lineWords[0];
      line += string(extraSpaces, ' ');
      return line;
    }

    int spaces = extraSpaces / (lineWords.size() - 1);
    int extra = extraSpaces % (lineWords.size() - 1);

    for (int i = 0; i < lineWords.size(); i++) {
      line += lineWords[i];
      if (i < lineWords.size() - 1) {
        line += string(spaces, ' ');
        if (extra > 0) {
          line += ' ';
          extra--;
        }
      }
    }

    return line;
  }

  string buildLastLine(vector<string>& lineWords, int extraSpaces) {
    string line;
    for (int i = 0; i < lineWords.size(); i++) {
      line += lineWords[i];
      if (i < lineWords.size() - 1) {
        line += ' ';
        extraSpaces--;
      }
    }
    line += string(extraSpaces, ' ');
    return line;
  }
};
// time: O(n)
// space: O(n)
int main() {
  vector<string> words1 = {"This",          "is", "an", "example", "of", "text",
                           "justification."};
  int maxWidth1 = 16;
  Solution obj;
  vector<string> result1 = obj.fullJustify(words1, maxWidth1);
  cout << "\n";
  for (int i = 0; i < words1.size(); i++) {
    cout << words1[i] << " ";
  }
  cout << maxWidth1 << "\n";
  for (int i = 0; i < result1.size(); i++) {
    cout << result1[i] << "\n";
  }
  return 0;
}
// sub: https://leetcode.com/problems/text-justification/submissions/1546833323/
// sol:
// https://leetcode.com/problems/text-justification/solutions/6435370/68-text-justification-by-nalindalal2004-3ozx/
