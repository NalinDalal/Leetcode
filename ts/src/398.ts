//3349. Adjacent Increasing Subarrays Detection I
function hasIncreasingSubarrays(
  input: number[],
  minLengthOfIncreasingSubarray: number,
): boolean {
  let currentIncreasingCount = 1;
  let previousIncreasingCount = 0;

  for (let i = 1; i < input.length; ++i) {
    if (
      foundTwoAdjacentIncreasingSubarraysWithMinLength(
        currentIncreasingCount,
        previousIncreasingCount,
        minLengthOfIncreasingSubarray,
      )
    ) {
      return true;
    }

    if (input[i - 1] >= input[i]) {
      previousIncreasingCount = currentIncreasingCount;
      currentIncreasingCount = 1;
      continue;
    }
    ++currentIncreasingCount;
  }

  return foundTwoAdjacentIncreasingSubarraysWithMinLength(
    currentIncreasingCount,
    previousIncreasingCount,
    minLengthOfIncreasingSubarray,
  );
}

function foundTwoAdjacentIncreasingSubarraysWithMinLength(
  currentIncreasingCount: number,
  previousIncreasingCount: number,
  minLengthOfIncreasingSubarray: number,
): boolean {
  return (
    currentIncreasingCount >= 2 * minLengthOfIncreasingSubarray ||
    (currentIncreasingCount >= minLengthOfIncreasingSubarray &&
      previousIncreasingCount >= minLengthOfIncreasingSubarray)
  );
}

//sub: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/submissions/1801149788/?envType=daily-question&envId=2025-10-14
//sol: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/solutions/7274080/3349-adjacent-increasing-subarrays-detec-4f8y/
