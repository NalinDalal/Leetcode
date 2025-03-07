//1899. Merge Triplets to Form Target Triplet
function mergeTriplets(triplets: number[][], target: number[]): boolean {
  let foundA = false,
    foundB = false,
    foundC = false;

  for (const triplet of triplets) {
    if (
      triplet[0] > target[0] ||
      triplet[1] > target[1] ||
      triplet[2] > target[2]
    ) {
      continue;
    }

    if (triplet[0] === target[0]) foundA = true;
    if (triplet[1] === target[1]) foundB = true;
    if (triplet[2] === target[2]) foundC = true;

    if (foundA && foundB && foundC) {
      return true;
    }
  }

  return false;
}

// Example usage
console.log(
  mergeTriplets(
    [
      [2, 5, 3],
      [1, 8, 4],
      [3, 6, 4],
    ],
    [3, 6, 4],
  ),
); // true or false
//sub: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/submissions/1564587036/
//sol: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/solutions/6503743/1899-merge-triplets-to-form-target-tripl-bt3v/
