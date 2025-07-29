//2411. Smallest Subarrays With Maximum Bitwise OR
function smallestSubarrays(nums: number[]): number[] {
    const n = nums.length;
    const answer: number[] = new Array(n).fill(0);
    const lastSeen: number[] = new Array(32).fill(-1); // tracks last index for each bit

    for (let i = n - 1; i >= 0; --i) {
        for (let b = 0; b < 32; ++b) {
            if ((nums[i] & (1 << b)) !== 0) {
                lastSeen[b] = i;
            }
        }

        let maxIndex = i;
        for (let b = 0; b < 32; ++b) {
            if (lastSeen[b] !== -1) {
                maxIndex = Math.max(maxIndex, lastSeen[b]);
            }
        }

        answer[i] = maxIndex - i + 1;
    }

    return answer;
}
//sub: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/submissions/1715650205/
//sol: https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/solutions/7019344/2411-smallest-subarrays-with-maximum-bit-p9k4/
