//2044. Count Number of Maximum Bitwise-OR Subsets
function countMaxOrSubsets(nums: number[]): number {
    let count = 0;
    const n = nums.length;
    let maxOr = 0;

    for (const num of nums) {
        maxOr |= num;
    }

    function dfs(index: number, currOr: number) {
        if (index === n) {
            if (currOr === maxOr) count++;
            return;
        }

        // Include nums[index]
        dfs(index + 1, currOr | nums[index]);
        // Exclude nums[index]
        dfs(index + 1, currOr);
    }

    dfs(0, 0);
    return count;
}
//sub: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/submissions/1714325285/?envType=daily-question&envId=2025-07-28
//sol: https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/solutions/7015088/2044-count-number-of-maximum-bitwise-or-98ei7/
