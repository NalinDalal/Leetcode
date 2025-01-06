// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
// 1769. Minimum Number of Operations to Move All Balls to Each Box

function minOperations(boxes: string): number[] {
  const n = boxes.length;
  const answer: number[] = new Array(n).fill(0);

  // Traverse from left to right
  let moves = 0,
    count = 0;
  for (let i = 0; i < n; i++) {
    answer[i] += moves;
    count += boxes[i] === "1" ? 1 : 0; // Count balls in the current box
    moves += count; // Add count to moves for the next box
  }

  // Traverse from right to left
  moves = 0;
  count = 0;
  for (let i = n - 1; i >= 0; i--) {
    answer[i] += moves;
    count += boxes[i] === "1" ? 1 : 0; // Count balls in the current box
    moves += count; // Add count to moves for the previous box
  }

  return answer;
}
