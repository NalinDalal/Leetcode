//3394. Check if Grid can be Cut into Sections
function checkValidCuts(n: number, rectangles: number[][]): boolean {
  return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
}

function checkCuts(rectangles: number[][], dim: number): boolean {
  let gapCount = 0;

  // Sort rectangles by their starting coordinate in the given dimension
  rectangles.sort((a, b) => a[dim] - b[dim]);

  // Track the furthest ending coordinate seen so far
  let furthestEnd = rectangles[0][dim + 2];

  for (let i = 1; i < rectangles.length; i++) {
    let rect = rectangles[i];

    // If current rectangle starts after the furthest end we've seen, there's a gap
    if (furthestEnd <= rect[dim]) {
      gapCount++;
    }

    // Update the furthest ending coordinate
    furthestEnd = Math.max(furthestEnd, rect[dim + 2]);
  }

  // We need at least 2 gaps to create 3 sections
  return gapCount >= 2;
}
//sub:https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/submissions/1585384602/?envType=daily-question&envId=2025-03-25
//sol:https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/solutions/6577093/3394-check-if-grid-can-be-cut-into-secti-jkra/
