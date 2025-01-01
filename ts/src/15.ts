// 1422. Maximum Score After Splitting a String
/* class Solution1 {
public:
  int maxScore(string s) {
    int totalOnes = 0;
    int leftZeros = 0, rightOnes = 0;
    int maxScore = 0;

    // Count total number of ones in the string
    for (char c : s) {
      if (c == '1') {
        totalOnes++;
      }
    }

    // Traverse the string and calculate the score dynamically
    for (int i = 0; i < s.length() - 1; ++i) {
      if (s[i] == '0') {
        leftZeros++; // Increment left zeros
      } else {
        rightOnes++; // Increment right ones
      }

      // Calculate score: left zeros + remaining right ones
      maxScore = max(maxScore, leftZeros + (totalOnes - rightOnes));
    }

    return maxScore;
  }
};
*/

function maxScore(s: string): number {
  let totalOnes: number = 0;
  let leftZeros: number = 0,
    rightOnes: number = 0;
  let maxScore: number = 0;

  //Count tota number of one in the string
  for (let c of s) {
    if (c == "1") {
      totalOnes++;
    }
  }

  //traverse string and calculate score dynamically
  for (let i = 0; i < s.length - 1; i++) {
    if (s[i] == "0")
      leftZeros++; //increment left zeroes
    else rightOnes++; //increment right ones

    //calculate score: leftZeros+remainging rightOnes
    maxScore = Math.max(maxScore, leftZeros + (totalOnes - rightOnes));
  }

  return maxScore;
}
