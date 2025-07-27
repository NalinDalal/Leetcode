//2210. Count Hills and Valleys in an Array
function countHillValley(nums: number[]): number {
    // Step 1: Remove consecutive duplicates
    const compressed: number[] = [nums[0]];
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            compressed.push(nums[i]);
        }
    }

    // Step 2: Count hills and valleys
    let count = 0;
    for (let i = 1; i < compressed.length - 1; i++) {
        if (
            (compressed[i] > compressed[i - 1] && compressed[i] > compressed[i + 1]) ||
            (compressed[i] < compressed[i - 1] && compressed[i] < compressed[i + 1])
        ) {
            count++;
        }
    }

    return count;
}
//sub: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/submissions/1713258734/?envType=daily-question&envId=2025-07-27
//sol: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/solutions/7011252/2210-count-hills-and-valleys-in-an-array-qda0/
