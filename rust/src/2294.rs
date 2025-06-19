//2294. Partition Array Such That Maximum Difference Is K
impl Solution {
    pub fn partition_array(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort(); // Sort in-place

        let mut count = 1;
        let mut start = nums[0];

        for &num in nums.iter().skip(1) {
            if num - start > k {
                count += 1;
                start = num;
            }
        }

        count
    }
}
//sub: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/submissions/1669026089/?envType=daily-question&envId=2025-06-19
//sol: https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/solutions/6860292/2294-partition-array-such-that-maximum-d-16ky/
