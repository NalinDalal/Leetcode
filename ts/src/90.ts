// 3160. Find the Number of Distinct Colors Among the Balls

function queryResults(limit: number, queries: number[][]): number[] {
  const ballColor: Map<number, number> = new Map(); // Maps ball index to color
  const colorFreq: Map<number, number> = new Map(); // Maps color to frequency
  const result: number[] = [];
  let distinctColors = 0;

  for (const [x, y] of queries) {
    // If the ball already has a color, reduce its count
    if (ballColor.has(x)) {
      const oldColor = ballColor.get(x)!;
      colorFreq.set(oldColor, (colorFreq.get(oldColor) || 0) - 1);
      if (colorFreq.get(oldColor) === 0) {
        distinctColors--;
        colorFreq.delete(oldColor);
      }
    }

    // Assign new color
    ballColor.set(x, y);
    colorFreq.set(y, (colorFreq.get(y) || 0) + 1);

    // If new color was not present before, increase count
    if (colorFreq.get(y) === 1) {
      distinctColors++;
    }

    result.push(distinctColors);
  }

  return result;
}
//sub: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/submissions/1534426618/?envType=daily-question&envId=2025-02-07
//sol: https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/solutions/6388022/3160-find-the-number-of-distinct-colors-cc4xd/
