//2966. Divide Array Into Arrays With Max Difference
function divideArray(nums: number[], k: number): number[][] {
  nums.sort((a, b) => a - b);
  const result: number[][] = [];

  for (let i = 0; i < nums.length; i += 3) {
    const group = nums.slice(i, i + 3);
    if (group[2] - group[0] > k) {
      return []; // Invalid triplet
    }
    result.push(group);
  }

  return result;
}
//sub: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/submissions/1667815013/?envType=daily-question&envId=2025-06-18
//sol: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/solutions/6856057/2966-divide-array-into-arrays-with-max-d-lu25/
