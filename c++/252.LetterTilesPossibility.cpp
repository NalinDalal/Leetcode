/* 1079. Letter Tile Possibilities

You have n  tiles, where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make using
the letters printed on those tiles.

Example 1:
Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB",
"ABA", "BAA".

Example 2:
Input: tiles = "AAABBC"
Output: 188

Example 3:
Input: tiles = "V"
Output: 1


Constraints:
1 <= tiles.length <= 7
tiles consists of uppercase English letters.*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
  int numTilePossibilities(string tiles) {
    // given a string of tiles, return all possible sequnces of letters
    // like give all permutations of letters in string
    sort(tiles.begin(), tiles.end()); // Sort to handle duplicates
    vector<bool> visited(tiles.size(), false);
    int count = 0;
    backtrack(tiles, visited, "", count);
    return count;
  }

private:
  void backtrack(const string& tiles, vector<bool>& visited, string path,
                 int& count) {
    for (int i = 0; i < tiles.size(); i++) {
      if (visited[i])
        continue; // Skip already used tile
      if (i > 0 && tiles[i] == tiles[i - 1] && !visited[i - 1])
        continue; // Avoid duplicates

      visited[i] = true;
      count++;
      backtrack(tiles, visited, path + tiles[i], count);
      visited[i] = false;
    }
  }
};
// Time: O(n)
// Space: O(1)
//  sub:
//  https://leetcode.com/problems/letter-tile-possibilities/submissions/1545731392/?envType=daily-question&envId=2025-02-17
int main() {
  Solution solution;
  string tiles1 = "AAB";
  cout << tiles1 << endl;
  cout << "Ans:" << solution.numTilePossibilities(tiles1) << endl;
  string tiles2 = "AAABBC";
  cout << tiles2 << endl;
  cout << "Ans: " << solution.numTilePossibilities(tiles2) << endl;
  string tiles3 = "V";
  cout << tiles3 << endl;
  cout << "Ans: " << solution.numTilePossibilities(tiles3) << endl;
  return 0;
}
// sol:
// https://leetcode.com/problems/letter-tile-possibilities/solutions/6431483/1079-letter-tile-possibilities-by-nalind-clui/
