//1298. Maximum Candies You Can Get from Boxes
function maxCandies(
  status: number[],
  candies: number[],
  keys: number[][],
  containedBoxes: number[][],
  initialBoxes: number[],
): number {
  const n = status.length;
  const hasBox = Array(n).fill(false);
  const hasKey = Array(n).fill(false);
  const visited = Array(n).fill(false);
  const queue: number[] = [];

  for (const box of initialBoxes) {
    hasBox[box] = true;
    if (status[box] === 1) {
      queue.push(box);
      visited[box] = true;
    }
  }

  let totalCandies = 0;

  while (queue.length > 0) {
    const curr = queue.shift()!;
    totalCandies += candies[curr];

    for (const key of keys[curr]) {
      hasKey[key] = true;
      if (hasBox[key] && !visited[key]) {
        queue.push(key);
        visited[key] = true;
      }
    }

    for (const b of containedBoxes[curr]) {
      hasBox[b] = true;
      if ((status[b] === 1 || hasKey[b]) && !visited[b]) {
        queue.push(b);
        visited[b] = true;
      }
    }
  }

  return totalCandies;
}
//sub: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/submissions/1652338829/
//sol: https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/solutions/6806277/1298-maximum-candies-you-can-get-from-bo-9k9p/
