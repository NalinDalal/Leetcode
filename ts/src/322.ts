function maxSum(nums: number[]): number {
    const seen = new Set<number>();
    let currSum = 0, maxSum = Number.MIN_SAFE_INTEGER, lastSum = 0;

    for (let i = 0; i < nums.length; i++) {
        if (!seen.has(nums[i])) {
            currSum += nums[i];
            maxSum = Math.max(maxSum, currSum);
            if (currSum < lastSum) currSum = lastSum;
            lastSum = currSum;
            seen.add(nums[i]);
        }
    }

    return maxSum;
}
//sub: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/submissions/1711201423/?envType=daily-question&envId=2025-07-25
//sol: https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/solutions/7004277/3487-maximum-unique-subarray-sum-after-d-4jm7/
