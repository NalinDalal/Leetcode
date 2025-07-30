//2419. Longest Subarray With Maximum Bitwise AND
function longestSubarray(nums: number[]): number {
    const maxVal = Math.max(...nums);
    let longest = 0, current = 0;

    for (const num of nums) {
        if (num === maxVal) {
            current++;
            longest = Math.max(longest, current);
        } else {
            current = 0;
        }
    }

    return longest;
}
//sub: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/submissions/1716479380/?envType=daily-question&envId=2025-07-30
//sol: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/solutions/7022002/2419-longest-subarray-with-maximum-bitwi-6z4b/
